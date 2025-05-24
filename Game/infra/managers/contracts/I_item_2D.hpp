#ifndef I_ITEM_2D_HPP
#define I_ITEM_2D_HPP

#include <E_texture.hpp>

class IItem2D
{
public:
  virtual ~IItem2D () noexcept = default;

  [[nodiscard]] virtual ETexture &getTexture () const noexcept = 0;

  virtual void dispose () noexcept = 0;
};

#endif // I_ITEM_2D_HPP
