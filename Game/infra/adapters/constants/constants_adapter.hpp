#ifndef CONSTANTS_ADAPTER_HPP
#define CONSTANTS_ADAPTER_HPP

#include <array>
#include <raylib.h>

namespace constants
{
constexpr std::array combinedKeys{
  KeyboardKey::KEY_RIGHT_ALT,    KeyboardKey::KEY_RIGHT_CONTROL,
  KeyboardKey::KEY_RIGHT_SHIFT,  KeyboardKey::KEY_LEFT_ALT,
  KeyboardKey::KEY_LEFT_CONTROL, KeyboardKey::KEY_LEFT_SHIFT,
};

}

#endif // CONSTANTS_ADAPTER_HPP
