#ifndef I_ITEM_2D_HPP
#define I_ITEM_2D_HPP

#include <E_texture.hpp>

class Item2D
{
public:
  virtual ~Item2D () noexcept = default;

  [[nodiscard]] virtual ETexture &GetTexture () const noexcept = 0;

  virtual void Dispose () noexcept = 0;
};

#endif // I_ITEM_2D_HPP
