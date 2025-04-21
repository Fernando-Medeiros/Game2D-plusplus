#ifndef ADAPTER_TEXTURE_RESOURCE_HPP
#define ADAPTER_TEXTURE_RESOURCE_HPP

#include <I_drawable.hpp>
#include <raylib.h>
#include <variant>
#include <cassert>

class TextureAdapterResource
{
private:
    Texture _texture;
    bool _valid = false;
public:
    TextureAdapterResource(const ResourceVariant &resource) noexcept
    {
        if (std::holds_alternative<Texture>(resource)) {
            _texture = std::get<Texture>(resource);
            _valid = true;
        }
    };

    ~TextureAdapterResource() noexcept
    {
        if (_valid)
            UnloadTexture(_texture);
    };

    operator Texture() const noexcept { return _texture; };
};
#endif
