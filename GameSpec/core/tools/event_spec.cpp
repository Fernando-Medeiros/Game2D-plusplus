#include <any>
#include <event.hpp>
#include <gtest/gtest.h>
#include <string>

class EventSpec : public ::testing::Test {
protected:
    Event event;
    std::string result;

    void SetUp() override {
	  result.clear();
    }

    void callback(const EventArgs& args) {
	  result = std::any_cast<std::string>(args);
    }

public:
    static void staticCallback(const EventArgs& args) {}
};

TEST_F(EventSpec, Should_Subscribe_And_Invoke_Callback) {
    EventId id = event.subscribe([&](const EventArgs& args) { callback(args); });

    event.invoke(std::string("Hello"));

    EXPECT_EQ(id, 1);
    EXPECT_EQ(result, "Hello");
}

TEST_F(EventSpec, Should_Return_Unique_EventId) {
    EventId id1 = event.subscribe([&](const EventArgs&) {});
    EventId id2 = event.subscribe([&](const EventArgs&) {});

    EXPECT_NE(id1, id2);
}

TEST_F(EventSpec, Should_Unsubscribe_And_Not_Invoke) {
    EventId id = event.subscribe([&](const EventArgs& args) {callback(args); });

    event.unsubscribe(id);
    event.invoke(std::string("Hello"));

    EXPECT_TRUE(result.empty());
}

TEST_F(EventSpec, Should_Invoke_Multiple_Callbacks) {
    int count = 0;

    EventId id1 = event.subscribe([&](const EventArgs&) { ++count; });
    EventId id2 = event.subscribe([&](const EventArgs&) { ++count; });
    EventId id = event.subscribe(EventSpec::staticCallback);

    event.invoke(std::string("Hello"));

    EXPECT_EQ(count, 2);
}

TEST_F(EventSpec, Should_Handle_Empty_Invoke_Gracefully) {
    EXPECT_NO_THROW(event.invoke(std::string("Nothing")));
}
