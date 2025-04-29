#ifndef ADAPTER_TEXTURE_RESOURCE_HPP
#define ADAPTER_TEXTURE_RESOURCE_HPP

#include <cassert>
#include <raylib.h>

class TextureAdapterResource
{
private:
  Texture _texture;

public:
  TextureAdapterResource (Texture resource) noexcept : _texture{ resource } {}

  ~TextureAdapterResource () noexcept = default;

  operator const Texture & () const noexcept { return _texture; }

  void
  dispose () const noexcept
  {
    UnloadTexture (_texture);
  }
};
#endif
