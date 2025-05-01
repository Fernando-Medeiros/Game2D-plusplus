#include <event.hpp>
#include <unordered_map>

[[nodiscard]] EventId
Event::subscribe (const EventCallback &handler) noexcept
{
    EventId id = ++nextId;
    handlers[id] = std::move(handler);
    return id;
}

[[nodiscard]] EventId Event::subscribe(EventCallbackWrapper *handler) noexcept
{
    EventId id = ++nextId;
    handlers[id] = [handler](const EventArgs &args) { handler(args); };
    return id;
}

void Event::unsubscribe(EventId eventId) noexcept
{
    handlers.erase(eventId);
}

void Event::invoke(const EventArgs &sender) noexcept
{
    for (auto &[_, handler] : handlers) {
        handler(sender);
    }
}

void
Event::dispose () noexcept
{
  nextId = 0;
  handlers.clear ();
}
