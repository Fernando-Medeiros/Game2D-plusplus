#ifndef I_RECTANGLE_HPP
#define I_RECTANGLE_HPP

#include <E_color.hpp>
#include <E_texture.hpp>
#include <rect_adapter.hpp>
#include <vector_adapter.hpp>

class IRectangle
{
public:
  virtual ~IRectangle () noexcept = default;

  virtual IRectangle &setRotation (float value) noexcept = 0;

  virtual IRectangle &setSize (VectorAdapter value) noexcept = 0;

  virtual IRectangle &setScale (VectorAdapter value) noexcept = 0;

  virtual IRectangle &setPosition (VectorAdapter value) noexcept = 0;

  virtual IRectangle &setTexture (ETexture value) noexcept = 0;

  virtual IRectangle &setOutlineSize (VectorAdapter value) noexcept = 0;

  virtual IRectangle &setOutlineColor (EColor value) noexcept = 0;

  virtual IRectangle &setFillColor (EColor value) noexcept = 0;

  [[nodiscard]] virtual float getRotation () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getSize () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getScale () const noexcept = 0;

  [[nodiscard]] virtual const ETexture &getTexture () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getPosition () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getOutlineSize () const noexcept
      = 0;

  [[nodiscard]] virtual const RectAdapter getRect () const noexcept = 0;

  [[nodiscard]] virtual const EColor &getOutlineColor () const noexcept = 0;

  [[nodiscard]] virtual const EColor &getFillColor () const noexcept = 0;
};

#endif // I_RECTANGLE_HPP
