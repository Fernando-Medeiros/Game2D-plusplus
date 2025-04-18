#ifndef ENUM_PROFESSION_HPP
#define ENUM_PROFESSION_HPP

#include <cstdint>

namespace core::enums {

enum class Profession : uint8_t {
    Barbarian = 0,
    Guardian = 1,
    Paladin = 2,
    Warrior = 3,

    BattleMage = 4,
    Cleric = 5,
    Druid = 6,
    Pyromancer = 7,

    Bard = 8,
    Ranger = 9,
    Rogue = 10,
    Monk = 11,
};
}
#endif
