#ifndef ENUM_OPACITY_HPP
#define ENUM_OPACITY_HPP

#include <cstdint>

enum class EOpacity : uint8_t
{
  Opaque = 64,
  Regular = 128,
  Light = 255,
  Transparent = 0,
};
#endif
