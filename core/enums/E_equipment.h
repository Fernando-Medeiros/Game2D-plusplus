#ifndef ENUM_EQUIPMENT_H
#define ENUM_EQUIPMENT_H

#include <cstdint>

namespace core::enums {

enum class Equipment : uint8_t {
    Head = 0,
    Chest = 1,
    Legs = 2,
    LeftHand = 3,
    RightHand = 4,
    LeftRing = 5,
    RightRing = 6,
    Necklace = 7,
    Cloak = 8
};
}
#endif
