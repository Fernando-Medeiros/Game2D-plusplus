#ifndef ENUM_MOUSE_H
#define ENUM_MOUSE_H

#include <cstdint>

namespace core::enums {

/// Enumeração de botões do mouse.
enum class Mouse : int8_t {
    None = -99,
    ScrollDown = -1,
    Left = 0,
    ScrollUp = 1,
    Right,
    Middle,
    XButton1,
    XButton2,
    ButtonCount,
};
} // namespace core::enums
#endif
