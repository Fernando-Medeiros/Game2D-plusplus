#ifndef ENUM_ANCHOR_H
#define ENUM_ANCHOR_H

#include <cstdint>

namespace core::enums {

enum class Anchor : uint8_t {
    /// Valor padrão para o alinhamento ser definido por outro componente;
    None,
    /// Esquerda superior;
    TopLeft,
    /// Direita superior;
    TopRight,
    /// Centro superior;
    TopCenter,
    /// Esquerda;
    Left,
    /// Centro;
    Center,
    /// Direita;
    Right,
    /// Centro inferior;
    BottomCenter,
    /// Esquerda inferior;
    BottomLeft,
    /// Direita inferior;
    BottomRight,
};
}
#endif
