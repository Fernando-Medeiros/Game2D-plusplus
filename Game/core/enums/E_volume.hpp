#ifndef ENUM_VOLUME_HPP
#define ENUM_VOLUME_HPP

#include <cstdint>

namespace core::enums {

enum class MusicVolume : uint8_t { S0 = 0, S1 = 25, S2 = 50, S3 = 75, S4 = 100 };

enum class SoundVolume : uint8_t {
    S0 = 0,
    S1 = 15,
    S2 = 30,
    S3 = 45,
    S4 = 60,
    S5 = 75,
    S6 = 90,
    S7 = 100
};
} // namespace core::enums
#endif
