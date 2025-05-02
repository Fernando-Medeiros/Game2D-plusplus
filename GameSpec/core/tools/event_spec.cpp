#include <E_keyboard_key.hpp>
#include <event.hpp>
#include <gtest/gtest.h>
#include <keyboard_args.hpp>

class EventSpec : public ::testing::Test {
protected:
    Event event;
    std::unique_ptr<IEventArgs> result;

    void SetUp() override {
      result.release ();
    }

    void
    callback (const IEventArgs &sender)
    {
      result = std::move (std::make_unique<IEventArgs> (sender));
    }

public:
  static void
  staticCallback (const IEventArgs &sender)
  {
  }
};

TEST_F(EventSpec, Should_Subscribe_And_Invoke_Callback) {
  EventId id
      = event.subscribe ([&] (const IEventArgs &sender) { callback (sender); });

  const IEventArgs &expected{ KeyboardArgs (EKeyboardKey::C,
                                           EKeyboardKey::CONTROL) };

  event.invoke (expected);

  EXPECT_EQ (id, 1);
  EXPECT_EQ (result, std::make_unique<IEventArgs> (expected));
}

TEST_F(EventSpec, Should_Return_Unique_EventId) {
    EventId id1 = event.subscribe([&](const IEventArgs&) {});
    EventId id2 = event.subscribe([&](const IEventArgs&) {});

    EXPECT_NE (id1, id2);
}

TEST_F(EventSpec, Should_Unsubscribe_And_Not_Invoke) {
  EventId id
      = event.subscribe ([&] (const IEventArgs &sender) { callback (sender); });

  IEventArgs expected{ KeyboardArgs (EKeyboardKey::C, EKeyboardKey::CONTROL) };

  event.unsubscribe (id);
  event.invoke (expected);

  EXPECT_TRUE (result == nullptr);
}

TEST_F(EventSpec, Should_Invoke_Multiple_Callbacks) {
    int count = 0;

    EventId id1 = event.subscribe([&](const IEventArgs&) { ++count; });
    EventId id2 = event.subscribe([&](const IEventArgs&) { ++count; });

    EventId id = event.subscribe (EventSpec::staticCallback);

    IEventArgs expected{ KeyboardArgs (EKeyboardKey::C,
                                      EKeyboardKey::CONTROL) };

    event.invoke (expected);

    EXPECT_EQ(count, 2);
}

TEST_F(EventSpec, Should_Handle_Empty_Invoke_Gracefully) {

  EXPECT_NO_THROW (event.invoke (IEventArgs ()));
}
