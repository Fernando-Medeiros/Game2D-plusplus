#ifndef ENUM_FRAME_H
#define ENUM_FRAME_H

#include <cstdint>

namespace core::enums {

enum class Frame : uint8_t {
    Minimum = 30,
    Common = 60,
    Maximum = 75,
};
}
#endif
