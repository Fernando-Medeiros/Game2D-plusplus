#ifndef ADAPTER_FONT_RESOURCE_HPP
#define ADAPTER_FONT_RESOURCE_HPP

#include <constants_adapter.hpp>

class FontAdapterResource
{
private:
  ExtFont _font;

public:
  FontAdapterResource (const ExtFont &resource) noexcept : _font{ resource } {}

  ~FontAdapterResource () noexcept = default;

  operator ExtFont () const noexcept { return _font; }

  void
  dispose () const noexcept
  {
    UnloadFont (_font);
  }
};
#endif
