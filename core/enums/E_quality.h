#ifndef ENUM_QUALITY_H
#define ENUM_QUALITY_H

#include <cstdint>

namespace core::enums {

enum class Quality : uint8_t {
    Common = 0,
    Higher = 1,
    Legendary = 2,
    Mythical = 3,
    Perfect = 4,
};
}
#endif
