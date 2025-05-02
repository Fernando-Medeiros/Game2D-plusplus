#ifndef I_CIRCLE_HPP
#define I_CIRCLE_HPP

#include <E_color.hpp>
#include <E_texture.hpp>
#include <rect_adapter.hpp>
#include <vector_adapter.hpp>

class ICircle
{
public:
  virtual ~ICircle () noexcept = default;

  virtual ICircle &setRotation (float value) noexcept = 0;

  virtual ICircle &setSize (VectorAdapter value) noexcept = 0;

  virtual ICircle &setScale (VectorAdapter value) noexcept = 0;

  virtual ICircle &setPosition (VectorAdapter value) noexcept = 0;

  virtual ICircle &setTexture (ETexture value) noexcept = 0;

  virtual ICircle &setOutlineSize (VectorAdapter value) noexcept = 0;

  virtual ICircle &setOutlineColor (EColor value) noexcept = 0;

  virtual ICircle &setFillColor (EColor value) noexcept = 0;

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
#endif // I_CIRCLE_HPP
