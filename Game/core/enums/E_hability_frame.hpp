#ifndef ENUM_HPPABILITY_FRAME_HPP
#define ENUM_HPPABILITY_FRAME_HPP

#include <cstdint>

namespace core::enums {

/// Animalções disponíveis.
/// Animações utilizam 5 frames com o nome da habilidade e um número de 1 a 5;
enum class HabilityFrame : uint8_t {
    HitPunch1,
    HitPunch2,
    HitPunch3,
    HitPunch4,
    HitPunch5,
    FireCast1,
    FireCast2,
    FireCast3,
    FireCast4,
    FireCast5,
    MagicExplosion1,
    MagicExplosion2,
    MagicExplosion3,
    MagicExplosion4,
    MagicExplosion5,
};
} // namespace core::enums
#endif
