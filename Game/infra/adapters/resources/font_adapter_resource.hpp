#ifndef ADAPTER_FONT_RESOURCE_HPP
#define ADAPTER_FONT_RESOURCE_HPP

#include <raylib.h>
#include <cassert>

class FontAdapterResource
{
private:
    Font _font;

public:
    FontAdapterResource(const Font &resource) noexcept
        : _font{resource}
    {}

    ~FontAdapterResource() noexcept { UnloadFont(_font); }

    operator Font() const noexcept { return _font; }
};
#endif
