#ifndef ENUM_ACTION_H
#define ENUM_ACTION_H

#include <cstdint>

namespace core::enums {

enum class Action : uint8_t {
    None = 0,
    Increment,
    Decrement,
    Completed,
    Cancel,
    Victory,
    Defeat,
    Locked,
    Unlocked,
};
}
#endif
