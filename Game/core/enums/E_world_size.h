#ifndef ENUM_WORLD_SIZE_HPP
#define ENUM_WORLD_SIZE_HPP

#include <cstdint>

namespace core::enums {

enum class WorldSize : uint8_t {
    Tiny = 12,
    Small = 24,
    Default = 32,
    Large = 48,
    VeryLarge = 64,
};
}
#endif
