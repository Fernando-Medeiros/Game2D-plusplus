#ifndef ENUM_OPACITY_H
#define ENUM_OPACITY_H

#include <cstdint>

namespace core::enums {

enum class Opacity : uint8_t {
    Opaque = 64,
    Regular = 128,
    Light = 255,
    Transparent = 0,
};
}
#endif
