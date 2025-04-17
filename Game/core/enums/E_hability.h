#ifndef ENUM_HABILITY_H
#define ENUM_HABILITY_H

#include <cstdint>

namespace core::enums {

/// Animações disponíveis.
/// Animações utilizam 5 frames com o nome da habilidade e um número de 1 a 5;
enum class Hability : uint8_t {
    HitPunch,
    FireCast,
    MagicExplosion,
};
} // namespace core::enums
#endif
