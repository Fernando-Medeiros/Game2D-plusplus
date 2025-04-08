#ifndef ENUM_PLACE_H
#define ENUM_PLACE_H

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
