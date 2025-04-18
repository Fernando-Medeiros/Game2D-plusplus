﻿#ifndef ENUM_GRAPHIC_HPP
#define ENUM_GRAPHIC_HPP

#include <cstdint>

namespace core::enums {

enum class Graphic : uint8_t {
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
}
#endif
