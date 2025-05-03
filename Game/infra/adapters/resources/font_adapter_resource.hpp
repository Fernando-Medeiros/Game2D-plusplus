#ifndef ADAPTER_FONT_RESOURCE_HPP
#define ADAPTER_FONT_RESOURCE_HPP

#include <constants_adapter.hpp>

class FontAdapterResource
{
private:
  ExtFont _font;

public:
  FontAdapterResource (const ExtFont &font) noexcept : _font{ font } {}

  operator ExtFont () const noexcept { return _font; }

  void
  dispose () noexcept
  {
    UnloadFont (_font);
  }
};
#endif
