#ifndef ADAPTER_FONT_RESOURCE_HPP
#define ADAPTER_FONT_RESOURCE_HPP

#include <I_drawable.hpp>
#include <raylib.h>
#include <variant>
#include <cassert>

class FontAdapterResource
{
private:
    Font _font;
    bool _valid = false;
public:
    FontAdapterResource(const ResourceVariant &resource) noexcept
    {
        if (std::holds_alternative<Font>(resource)) {
            _font = std::get<Font>(resource);
            _valid = true;
        }
    };

    ~FontAdapterResource() noexcept {
	  if (_valid)
		UnloadFont(_font);
    };

    operator Font() const noexcept { return _font; };
};
#endif
