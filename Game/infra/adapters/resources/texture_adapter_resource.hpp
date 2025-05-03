#ifndef ADAPTER_TEXTURE_RESOURCE_HPP
#define ADAPTER_TEXTURE_RESOURCE_HPP

#include <constants_adapter.hpp>

class TextureAdapterResource
{
private:
  ExtTexture _texture;

public:
  TextureAdapterResource (ExtTexture resource) noexcept : _texture{ resource }
  {
  }

  operator const ExtTexture & () const noexcept { return _texture; }

  void
  dispose () noexcept
  {
    UnloadTexture (_texture);
  }
};
#endif
