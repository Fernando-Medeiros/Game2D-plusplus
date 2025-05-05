#ifndef TOOLS_EVENT_HPP
#define TOOLS_EVENT_HPP

#include <functional>
#include <unordered_map>

class IEventArgs
{
public:
  virtual ~IEventArgs () noexcept = default;

  template <typename T>
  requires std::derived_from<T, IEventArgs> [[nodiscard]] const T *
  toSecurePtr () const
  {
    return dynamic_cast<const T *> (this);
  }
};

using EventId = size_t;
using EventCallbackWrapper = void(const IEventArgs &);
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

  void invoke (const IEventArgs &sender) noexcept;

  void unsubscribe (EventId eventId) noexcept;

  [[nodiscard]] EventId subscribe (const EventCallback &handler) noexcept;

  [[nodiscard]] EventId subscribe (EventCallbackWrapper *handler) noexcept;
    };
#endif // TOOLS_EVENT_HPP
