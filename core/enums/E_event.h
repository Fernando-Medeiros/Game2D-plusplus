#ifndef ENUM_EVENT_H
#define ENUM_EVENT_H

#include <cstdint>

namespace core::enums {

enum class Event : uint8_t {
    /// region Binding
    Camera,
    ExitGame,
    Logger,
    Node,
    Notification,
    Route,
    SaveGame,
    SchemaChanged,
    NodeSelected,
    Sound,
    Animation,
    /// region Window
    WindowResized,
    TextEntered,
    KeyPressed,
    KeyReleased,
    MouseMoved,
    MouseWheelScrolled,
    MouseButtonPressed,
    MouseButtonReleased,
};
}
#endif
