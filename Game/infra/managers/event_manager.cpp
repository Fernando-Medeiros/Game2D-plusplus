#include <event_manager.hpp>

void
EventManager::invoke (const EEvent &event, const EventArgs &sender) noexcept
{
  switch (event)
    {
    case EEvent::Sound:
      SoundRequested.invoke (sender);
      break;
    case EEvent::Route:
      RouteChanged.invoke (sender);
      break;
    case EEvent::Camera:
      CameraChanged.invoke (sender);
      break;
    case EEvent::Logger:
      LoggerChanged.invoke (sender);
      break;
    case EEvent::ExitGame:
      EndGameChanged.invoke (sender);
      break;
    case EEvent::SaveGame:
      SaveGameChanged.invoke (sender);
      break;
    case EEvent::NodeSelected:
      NodeSelected.invoke (sender);
      break;
    case EEvent::Animation:
      AnimationChanaged.invoke (sender);
      break;
    case EEvent::Notification:
      NotificationChanged.invoke (sender);
      break;
    case EEvent::WindowResized:
      WindowResized.invoke (sender);
      break;
    case EEvent::TextEntered:
      TextEntered.invoke (sender);
      break;
    case EEvent::KeyPressed:
      KeyPressed.invoke (sender);
      break;
    case EEvent::KeyReleased:
      KeyReleased.invoke (sender);
      break;
    case EEvent::MouseMoved:
      MouseMoved.invoke (sender);
      break;
    case EEvent::MouseWheelScrolled:
      MouseWheelScrolled.invoke (sender);
      break;
    case EEvent::MouseButtonPressed:
      MouseButtonPressed.invoke (sender);
      break;
    case EEvent::MouseButtonReleased:
      MouseButtonReleased.invoke (sender);
      break;
    };
}

void
EventManager::unsubscribe (const EEvent &event,
                           const EventId &eventId) noexcept
{
  switch (event)
    {
    case EEvent::Sound:
      SoundRequested.unsubscribe (eventId);
      break;
    case EEvent::Route:
      RouteChanged.unsubscribe (eventId);
      break;
    case EEvent::Camera:
      CameraChanged.unsubscribe (eventId);
      break;
    case EEvent::Logger:
      LoggerChanged.unsubscribe (eventId);
      break;
    case EEvent::ExitGame:
      EndGameChanged.unsubscribe (eventId);
      break;
    case EEvent::SaveGame:
      SaveGameChanged.unsubscribe (eventId);
      break;
    case EEvent::NodeSelected:
      NodeSelected.unsubscribe (eventId);
      break;
    case EEvent::Animation:
      AnimationChanaged.unsubscribe (eventId);
      break;
    case EEvent::Notification:
      NotificationChanged.unsubscribe (eventId);
      break;
    case EEvent::WindowResized:
      WindowResized.unsubscribe (eventId);
      break;
    case EEvent::TextEntered:
      TextEntered.unsubscribe (eventId);
      break;
    case EEvent::KeyPressed:
      KeyPressed.unsubscribe (eventId);
      break;
    case EEvent::KeyReleased:
      KeyReleased.unsubscribe (eventId);
      break;
    case EEvent::MouseMoved:
      MouseMoved.unsubscribe (eventId);
      break;
    case EEvent::MouseWheelScrolled:
      MouseWheelScrolled.unsubscribe (eventId);
      break;
    case EEvent::MouseButtonPressed:
      MouseButtonPressed.unsubscribe (eventId);
      break;
    case EEvent::MouseButtonReleased:
      MouseButtonReleased.unsubscribe (eventId);
      break;
    };
}

[[nodiscard]] EventId
EventManager::subscribe (const EEvent &event,
                         const EventCallback handler) noexcept
{
  EventId eventId;

  switch (event)
    {
    case EEvent::Sound:
      eventId = SoundRequested.subscribe (handler);
      break;
    case EEvent::Route:
      eventId = RouteChanged.subscribe (handler);
      break;
    case EEvent::Camera:
      eventId = CameraChanged.subscribe (handler);
      break;
    case EEvent::Logger:
      eventId = LoggerChanged.subscribe (handler);
      break;
    case EEvent::ExitGame:
      eventId = EndGameChanged.subscribe (handler);
      break;
    case EEvent::SaveGame:
      eventId = SaveGameChanged.subscribe (handler);
      break;
    case EEvent::NodeSelected:
      eventId = NodeSelected.subscribe (handler);
      break;
    case EEvent::Animation:
      eventId = AnimationChanaged.subscribe (handler);
      break;
    case EEvent::Notification:
      eventId = NotificationChanged.subscribe (handler);
      break;
    case EEvent::WindowResized:
      eventId = WindowResized.subscribe (handler);
      break;
    case EEvent::TextEntered:
      eventId = TextEntered.subscribe (handler);
      break;
    case EEvent::KeyPressed:
      eventId = KeyPressed.subscribe (handler);
      break;
    case EEvent::KeyReleased:
      eventId = KeyReleased.subscribe (handler);
      break;
    case EEvent::MouseMoved:
      eventId = MouseMoved.subscribe (handler);
      break;
    case EEvent::MouseWheelScrolled:
      eventId = MouseWheelScrolled.subscribe (handler);
      break;
    case EEvent::MouseButtonPressed:
      eventId = MouseButtonPressed.subscribe (handler);
      break;
    case EEvent::MouseButtonReleased:
      eventId = MouseButtonReleased.subscribe (handler);
      break;
    };

  return eventId;
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
