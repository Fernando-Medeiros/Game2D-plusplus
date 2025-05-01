#ifndef TOOLS_EVENT_HPP
#define TOOLS_EVENT_HPP

#include <any>
#include <functional>
#include <unordered_map>

using EventId = size_t;
using EventArgs = std::any;
using EventCallbackWrapper = void(const EventArgs &);
using EventCallback = std::function<EventCallbackWrapper>;
using EventCollection = std::unordered_map<EventId, EventCallback>;

class Event
{
private:
  EventId nextId;
  EventCollection handlers;

public:
  Event () noexcept = default;
  ~Event () noexcept = default;

  void dispose () noexcept;

  void invoke (const EventArgs &sender) noexcept;

  void unsubscribe (EventId eventId) noexcept;

  [[nodiscard]] EventId subscribe (const EventCallback &handler) noexcept;

  [[nodiscard]] EventId subscribe (EventCallbackWrapper *handler) noexcept;
    };
#endif // TOOLS_EVENT_HPP
