#include <E_keyboard_key.hpp>
#include <event.hpp>
#include <gtest/gtest.h>
#include <keyboard_args.hpp>

class EventSpec : public ::testing::Test {
protected:
    Event event;
    std::unique_ptr<EventArgs> result;

    void SetUp() override {
      result.release ();
    }

    void
    callback (const EventArgs &sender)
    {
      result = std::move (std::make_unique<EventArgs> (sender));
    }

public:
  static void
  staticCallback (const EventArgs &sender)
  {
  }
};

TEST_F(EventSpec, Should_Subscribe_And_Invoke_Callback) {
  EventId id
      = event.subscribe ([&] (const EventArgs &sender) { callback (sender); });

  const EventArgs &expected{ KeyboardArgs (EKeyboardKey::C,
                                           EKeyboardKey::CONTROL) };

  event.invoke (expected);

  EXPECT_EQ (id, 1);
  EXPECT_EQ (result, std::make_unique<EventArgs> (expected));
}

TEST_F(EventSpec, Should_Return_Unique_EventId) {
    EventId id1 = event.subscribe([&](const EventArgs&) {});
    EventId id2 = event.subscribe([&](const EventArgs&) {});

    EXPECT_NE (id1, id2);
}

TEST_F(EventSpec, Should_Unsubscribe_And_Not_Invoke) {
  EventId id
      = event.subscribe ([&] (const EventArgs &sender) { callback (sender); });

  EventArgs expected{ KeyboardArgs (EKeyboardKey::C, EKeyboardKey::CONTROL) };

  event.unsubscribe (id);
  event.invoke (expected);

  EXPECT_TRUE (result == nullptr);
}

TEST_F(EventSpec, Should_Invoke_Multiple_Callbacks) {
    int count = 0;

    EventId id1 = event.subscribe([&](const EventArgs&) { ++count; });
    EventId id2 = event.subscribe([&](const EventArgs&) { ++count; });

    EventId id = event.subscribe (EventSpec::staticCallback);

    EventArgs expected{ KeyboardArgs (EKeyboardKey::C,
                                      EKeyboardKey::CONTROL) };

    event.invoke (expected);

    EXPECT_EQ(count, 2);
}

TEST_F(EventSpec, Should_Handle_Empty_Invoke_Gracefully) {

  EXPECT_NO_THROW (event.invoke (EventArgs ()));
}
