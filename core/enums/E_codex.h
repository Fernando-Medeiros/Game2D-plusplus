#ifndef ENUM_CODEX_H
#define ENUM_CODEX_H

#include <cstdint>

namespace core::enums {

enum class Codex : uint8_t {
    Alignment,
    Profession,
    Status,
    Race,

    Head,
    Chest,
    Boot,
    Ring,
    Cloak,
    Necklace,
    Weapons,
    Keys,
    Potions,
    Materials,
    Runes,
    Gems
};
}
#endif
