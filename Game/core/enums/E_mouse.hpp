#ifndef ENUM_MOUSE_HPP
#define ENUM_MOUSE_HPP

#include <cstdint>

/// Enumeração de botões do mouse.
enum class EMouse : int8_t {
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
#endif
