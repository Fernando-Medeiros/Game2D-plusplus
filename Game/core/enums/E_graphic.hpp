#ifndef ENUM_GRAPHIC_HPP
#define ENUM_GRAPHIC_HPP

#include <cstdint>

enum class EGraphic : uint8_t
{
  AnchorLeft,
  AnchorRight,
  AnchorTopLeft,
  AnchorTopRight,
  AnchorTopCenter,
  AnchorBottomLeft,
  AnchorBottomRight,
  AnchorBottomCenter,

  LootNode,
  SelectedNode,
  PanelDefault,

  ButtonDefault,
  ButtonDefaultHover,
  ButtonDefaultPressed,

  EntryDefault,
  EntryDefaultHover,
  EntryDefaultPressed,
};
#endif
