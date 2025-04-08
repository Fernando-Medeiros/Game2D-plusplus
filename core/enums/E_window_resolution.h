#ifndef ENUM_WINDOW_RESOLUTION_H
#define ENUM_WINDOW_RESOLUTION_H

#include <cstdint>

namespace core::enums {

enum class WindowResolution : uint8_t {
    /// SVGA
    R_800x600,
    /// XGA
    R_1024x768,
    /// HD
    R_1280x720,
    /// FULL HD
    R_1980x1280,
};
}
#endif
