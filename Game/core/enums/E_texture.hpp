#ifndef ENUM_TEXTURE_HPP
#define ENUM_TEXTURE_HPP

#include <cstdint>

enum class ETexture : uint16_t
{
  None,

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

#endif // ENUM_TEXTURE_HPP
