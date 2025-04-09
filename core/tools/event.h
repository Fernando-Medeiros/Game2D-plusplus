#ifndef TOOLS_EVENT_H
#define TOOLS_EVENT_H

#include <functional>
#include <vector>

namespace core::tools {

template<typename T>
class Event
{
public:
    using Action = std::function<void(T &)>;

private:
    std::vector<Action> handlers;

public:
    Event() = default;
    ~Event() = default;

    void invoke(T &sender);
    void subscribe(const Action &handler);
};
} // namespace core::tools
#endif // TOOLS_EVENT_H
