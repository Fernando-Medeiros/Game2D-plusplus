#ifndef ENUM_PLACE_HPP
#define ENUM_PLACE_HPP

#include <cstdint>

namespace core::enums {

enum class Place : uint8_t {
    Bank,
    Forge,
    Arena,
    Dungeon,
    Tower,
};
}
#endif
