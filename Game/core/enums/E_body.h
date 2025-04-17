#ifndef ENUM_BODY_H
#define ENUM_BODY_H

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
