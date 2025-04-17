#ifndef ENUM_CONSUMABLE_H
#define ENUM_CONSUMABLE_H

#include <cstdint>

namespace core::enums {

enum class Consumable : uint8_t {
    Hp = 0,
    Mp = 1,
    Elixir = 2,
};
}
#endif
