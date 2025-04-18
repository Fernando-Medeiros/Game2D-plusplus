#ifndef TOOLS_EVENT_HPP
#define TOOLS_EVENT_HPP

#include <any>
#include <functional>
#include <memory>
#include <vector>

namespace core::tools {

using namespace std;

using EventId = size_t;
using EventArgs = any;
using EventCallback = function<void(EventArgs &)>;
using EventCollection = vector<pair<EventId, EventCallback>>;

class Event
{
private:
    unique_ptr<EventId> nextId;
    unique_ptr<EventCollection> handlers;

public:
    Event();
    ~Event() = default;

    void invoke(any sender);
    void unsubscribe(EventId &eventId);
    EventId subscribe(EventCallback handler);

private:
    void refreshCapacity();
};
} // namespace core::tools
#endif // TOOLS_EVENT_HPP
