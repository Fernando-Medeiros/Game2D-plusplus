#ifndef ENUM_CONSUMABLE_HPP
#define ENUM_CONSUMABLE_HPP

#include <cstdint>

namespace core::enums {

enum class Consumable : uint8_t {
    Hp = 0,
    Mp = 1,
    Elixir = 2,
};
}
#endif
