#ifndef ENUM_ATTRIBUTE_H
#define ENUM_ATTRIBUTE_H

#include <cstdint>

namespace core::enums {

enum class Attribute : int8_t {
    /// region CONDITION (-1 a -16)
    Poisoned = -1,
    Burning = -2,
    Cursed = -3,
    Frozen = -4,
    Petrified = -5,
    Stunned = -6,
    Paralyzed = -7,
    Blind = -8,
    Confused = -9,
    Bleeding = -10,
    Rot = -11,
    Toxic = -12,
    Asleep = -13,
    Drenched = -14,
    Blight = -15,
    Lulled = -16,

    /// region PRIMARY (0 a 4)
    Constitution = 0,
    Dexterity = 1,
    Intelligence = 2,
    Strength = 3,
    Experience = 4,

    /// region SECONDARY (5 a 15)
    Block = 5,
    CritRate = 6,
    CritHit = 7,
    Defense = 8,
    Dodge = 9,
    Energy = 10,
    Health = 11,
    Resistance = 12,
};
}
#endif
