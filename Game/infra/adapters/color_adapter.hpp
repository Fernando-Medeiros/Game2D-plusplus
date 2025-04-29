#ifndef COLOR_ADAPTER_HPP
#define COLOR_ADAPTER_HPP

#include <E_color.hpp>
#include <E_opacity.hpp>
#include <raylib.h>

Color
toColor (const EColor &color)
{
  Color colorResult = WHITE;

  switch (color)
    {
    case EColor::Black:
      return colorResult = Color (0, 0, 0, 255);
    case EColor::Gray:
      return colorResult = Color (102, 102, 102, 255);
    case EColor::Tomate:
      return colorResult = Color (255, 99, 71, 255);
    case EColor::Primary:
      return colorResult = Color (54, 46, 43, 255);
    case EColor::White:
      return colorResult = Color (255, 255, 255, 255);
    case EColor::GoldRod:
      return colorResult = Color (218, 165, 32, 255);
    case EColor::CornFlowerBlue:
      return colorResult = Color (100, 149, 237, 255);
    case EColor::DarkSeaGreen:
      return colorResult = Color (0, 114, 119, 47);
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
