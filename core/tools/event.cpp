#include "event.h"

using namespace core::tools;

Event::Event()
    : nextId{make_unique<EventId>()}
    , handlers{make_unique<EventCollection>()}
{
    handlers->reserve(2);
};

EventId Event::subscribe(EventCallback handler)
{
    EventId id = ++(*nextId);
    handlers->emplace_back(id, std::move(handler));
    refreshCapacity();
    return id;
}

void Event::unsubscribe(EventId &eventId)
{
    auto expression = std::remove_if(handlers->begin(), handlers->end(), [=](const auto &pair) {
        return pair.first == eventId;
    });

    handlers->erase(expression, handlers->end());
    refreshCapacity();
}

void Event::invoke(any sender)
{
    for (auto &[_, handler] : *handlers) {
        handler(sender);
    }
}

void Event::refreshCapacity()
{
    size_t length = handlers->size();

    if (length == 0) {
        handlers->clear();
        handlers = make_unique<EventCollection>();
        handlers->reserve(1);
    } else {
        handlers->reserve(length + 1);
    }
}
