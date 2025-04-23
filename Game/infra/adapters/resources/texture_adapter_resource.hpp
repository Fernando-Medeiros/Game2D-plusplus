#ifndef ADAPTER_TEXTURE_RESOURCE_HPP
#define ADAPTER_TEXTURE_RESOURCE_HPP

#include <raylib.h>
#include <cassert>

class TextureAdapterResource
{
private:
    Texture2D _texture;

public:
    TextureAdapterResource(const Texture2D &resource) noexcept
        : _texture{resource}
    {}

    ~TextureAdapterResource() noexcept { UnloadTexture(_texture); }

    operator Texture() const noexcept { return _texture; }
};
#endif
