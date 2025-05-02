#ifndef ENUM_MOUSE_HPP
#define ENUM_MOUSE_HPP

#include <cstdint>

enum class EMouseButton : uint8_t
{
  NONE,
  //
  LEFT,
  RIGHT,
  MIDDLE,
  //
  BACK,
  SIDE,
  EXTRA,
  FORWARD,
  //
  SCROLLUP,
  SCROLLDOWN,
};
#endif
