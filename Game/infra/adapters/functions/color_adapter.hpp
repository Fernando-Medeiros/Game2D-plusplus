#ifndef COLOR_ADAPTER_HPP
#define COLOR_ADAPTER_HPP

#include <E_color.hpp>
#include <E_opacity.hpp>
#include <raylib.h>

constexpr Color
toColor (const EColor &color, const EOpacity &opacity = EOpacity::Light)
{
  Color colorResult = WHITE;

  switch (color)
    {
    case EColor::Black:
      return colorResult = Color (0, 0, 0, (int)opacity);
    case EColor::Gray:
      return colorResult = Color (102, 102, 102, (int)opacity);
    case EColor::Tomate:
      return colorResult = Color (255, 99, 71, (int)opacity);
    case EColor::Primary:
      return colorResult = Color (54, 46, 43, (int)opacity);
    case EColor::White:
      return colorResult = Color (255, 255, 255, (int)opacity);
    case EColor::GoldRod:
      return colorResult = Color (218, 165, 32, (int)opacity);
    case EColor::CornFlowerBlue:
      return colorResult = Color (100, 149, 237, (int)opacity);
    case EColor::DarkSeaGreen:
      return colorResult = Color (0, 114, 119, (int)opacity);
    case EColor::Light:
      return colorResult = Color (255, 255, 255, (int)EOpacity::Light);
    case EColor::Opaque:
      return colorResult = Color (255, 255, 255, (int)EOpacity::Opaque);
    case EColor::Regular:
      return colorResult = Color (255, 255, 255, (int)EOpacity::Regular);
    case EColor::Transparent:
      return colorResult = Color (255, 255, 255, (int)EOpacity::Transparent);
    default:
      break;
    };

  return colorResult;
}

#endif // COLOR_ADAPTER_HPP
