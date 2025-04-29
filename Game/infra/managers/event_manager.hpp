#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <E_event.hpp>
#include <event.hpp>

class EventManager
{
private:
  Event SoundRequested;
  Event RouteChanged;
  Event NodeSelected;
  Event CameraChanged;
  Event LoggerChanged;
  Event EndGameChanged;
  Event SaveGameChanged;
  Event AnimationChanaged;
  Event NotificationChanged;
  Event WindowResized;
  Event TextEntered;
  Event KeyPressed;
  Event KeyReleased;
  Event MouseMoved;
  Event MouseWheelScrolled;
  Event MouseButtonPressed;
  Event MouseButtonReleased;

public:
  void invoke (const EEvent &event, const EventArgs &sender) noexcept;

  void unsubscribe (const EEvent &event, const EventId &eventId) noexcept;

  [[nodiscard]] EventId subscribe (const EEvent &event,
                                   const EventCallback handler) noexcept;

  void dispose () noexcept;
};

#endif // EVENT_MANAGER_HPP
