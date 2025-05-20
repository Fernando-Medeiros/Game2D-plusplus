#ifndef ENUM_ANCHOR_HPP
#define ENUM_ANCHOR_HPP

#include <cstdint>

enum class EAnchor : uint8_t
{
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
#endif
