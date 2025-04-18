#ifndef ENUM_BODY_HPP
#define ENUM_BODY_HPP

#include <cstdint>

namespace core::enums {

enum class Body : uint8_t {
    Npc,
    Static,
    Player,
    Enemy,
};
}
#endif
