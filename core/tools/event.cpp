#include "event.h"

template<typename T>
void core::tools::Event<T>::subscribe(const Action &handler)
{
    handlers.push_back(handler);
}

template<typename T>
void core::tools::Event<T>::invoke(T &sender)
{
    for (const auto &handler : handlers) {
        handler(sender);
    }
}
