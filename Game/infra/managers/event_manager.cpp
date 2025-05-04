#include <event_manager.hpp>

void
EventManager::invoke (const EEvent &event, const IEventArgs &sender) noexcept
{
  switch (event)
    {
    case EEvent::Sound:
      return SoundRequested.invoke (sender);
    case EEvent::Route:
      return RouteChanged.invoke (sender);
    case EEvent::CameraCenter:
      return CameraChanged.invoke (sender);
    case EEvent::Logger:
      return LoggerChanged.invoke (sender);
    case EEvent::ExitGame:
      return EndGameChanged.invoke (sender);
    case EEvent::SaveGame:
      return SaveGameChanged.invoke (sender);
    case EEvent::NodeSelected:
      return NodeSelected.invoke (sender);
    case EEvent::Animation:
      return AnimationChanaged.invoke (sender);
    case EEvent::Notification:
      return NotificationChanged.invoke (sender);
    case EEvent::WindowResized:
      return WindowResized.invoke (sender);
    case EEvent::TextEntered:
      return TextEntered.invoke (sender);
    case EEvent::KeyPressed:
      return KeyPressed.invoke (sender);
    case EEvent::KeyReleased:
      return KeyReleased.invoke (sender);
    case EEvent::MouseMoved:
      return MouseMoved.invoke (sender);
    case EEvent::MouseWheelScrolled:
      return MouseWheelScrolled.invoke (sender);
    case EEvent::MouseButtonPressed:
      return MouseButtonPressed.invoke (sender);
    case EEvent::MouseButtonReleased:
      return MouseButtonReleased.invoke (sender);
    };
}

void
EventManager::unsubscribe (const EEvent &event,
                           const EventId &eventId) noexcept
{
  switch (event)
    {
    case EEvent::Sound:
      return SoundRequested.unsubscribe (eventId);
    case EEvent::Route:
      return RouteChanged.unsubscribe (eventId);
    case EEvent::CameraCenter:
      return CameraChanged.unsubscribe (eventId);
    case EEvent::Logger:
      return LoggerChanged.unsubscribe (eventId);
    case EEvent::ExitGame:
      return EndGameChanged.unsubscribe (eventId);
    case EEvent::SaveGame:
      return SaveGameChanged.unsubscribe (eventId);
    case EEvent::NodeSelected:
      return NodeSelected.unsubscribe (eventId);
    case EEvent::Animation:
      return AnimationChanaged.unsubscribe (eventId);
    case EEvent::Notification:
      return NotificationChanged.unsubscribe (eventId);
    case EEvent::WindowResized:
      return WindowResized.unsubscribe (eventId);
    case EEvent::TextEntered:
      return TextEntered.unsubscribe (eventId);
    case EEvent::KeyPressed:
      return KeyPressed.unsubscribe (eventId);
    case EEvent::KeyReleased:
      return KeyReleased.unsubscribe (eventId);
    case EEvent::MouseMoved:
      return MouseMoved.unsubscribe (eventId);
    case EEvent::MouseWheelScrolled:
      return MouseWheelScrolled.unsubscribe (eventId);
    case EEvent::MouseButtonPressed:
      return MouseButtonPressed.unsubscribe (eventId);
    case EEvent::MouseButtonReleased:
      return MouseButtonReleased.unsubscribe (eventId);
    };
}

[[nodiscard]] EventId
EventManager::subscribe (const EEvent &event,
                         const EventCallback &handler) noexcept
{
  switch (event)
    {
    case EEvent::Sound:
      return SoundRequested.subscribe (handler);
    case EEvent::Route:
      return RouteChanged.subscribe (handler);
    case EEvent::CameraCenter:
      return CameraChanged.subscribe (handler);
    case EEvent::Logger:
      return LoggerChanged.subscribe (handler);
    case EEvent::ExitGame:
      return EndGameChanged.subscribe (handler);
    case EEvent::SaveGame:
      return SaveGameChanged.subscribe (handler);
    case EEvent::NodeSelected:
      return NodeSelected.subscribe (handler);
    case EEvent::Animation:
      return AnimationChanaged.subscribe (handler);
    case EEvent::Notification:
      return NotificationChanged.subscribe (handler);
    case EEvent::WindowResized:
      return WindowResized.subscribe (handler);
    case EEvent::TextEntered:
      return TextEntered.subscribe (handler);
    case EEvent::KeyPressed:
      return KeyPressed.subscribe (handler);
    case EEvent::KeyReleased:
      return KeyReleased.subscribe (handler);
    case EEvent::MouseMoved:
      return MouseMoved.subscribe (handler);
    case EEvent::MouseWheelScrolled:
      return MouseWheelScrolled.subscribe (handler);
    case EEvent::MouseButtonPressed:
      return MouseButtonPressed.subscribe (handler);
    case EEvent::MouseButtonReleased:
      return MouseButtonReleased.subscribe (handler);
    };
  return -1;
}

void
EventManager::dispose () noexcept
{
  SoundRequested.dispose ();

  RouteChanged.dispose ();
  NodeSelected.dispose ();
  CameraChanged.dispose ();
  LoggerChanged.dispose ();
  EndGameChanged.dispose ();
  SaveGameChanged.dispose ();
  AnimationChanaged.dispose ();
  NotificationChanged.dispose ();

  WindowResized.dispose ();
  TextEntered.dispose ();
  KeyPressed.dispose ();
  KeyReleased.dispose ();
  MouseMoved.dispose ();
  MouseWheelScrolled.dispose ();
  MouseButtonPressed.dispose ();
  MouseButtonReleased.dispose ();
}
