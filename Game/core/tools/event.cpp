#include "event.hpp"
#include <type_traits>
#include <unordered_map>

namespace core::tools {

    Event::Event() noexcept :
	  nextId{ 0 },
	  handlers{ EventCollection() } {
	  handlers.reserve(4);
    }

    [[nodiscard]] EventId Event::subscribe(EventCallback handler) noexcept {
	  EventId id = ++nextId;
	  handlers[id] = std::move(handler);
	  return id;
    }

    [[nodiscard]] EventId Event::subscribe(EventCallbackWrapper* handler) noexcept {
	  EventId id = ++nextId;
	  handlers[id] = [handler](const EventArgs& args) { handler(args); };
	  return id;
    }

    void Event::unsubscribe(EventId eventId) noexcept {
	  handlers.erase(eventId);
    }

    void Event::invoke(const EventArgs& sender) noexcept {
	  for (auto& [_, handler] : handlers) {
		handler(sender);
	  }
    }
}
