#ifndef ADAPTER_RECTANGLE_HPP
#define ADAPTER_RECTANGLE_HPP

#include <I_drawable.hpp>
#include <I_rectangle.hpp>

class RectangleAdapter : public IRectangle, public IDrawable
{
private:
  ETexture _texture{ ETexture::NONE };
  EColor _outlineColor{ EColor::White }, _fillColor{ EColor::CornFlowerBlue };
  VectorAdapter _size, _scale, _center, _position, _outlineSize;
  float _rotation{ 0.0f };

public:
  IRectangle &setRotation (float value) noexcept override;

  IRectangle &setSize (VectorAdapter value) noexcept override;

  IRectangle &setScale (VectorAdapter value) noexcept override;

  IRectangle &setPosition (VectorAdapter value) noexcept override;

  IRectangle &setTexture (ETexture value) noexcept override;

  IRectangle &setOutlineSize (VectorAdapter value) noexcept override;

  IRectangle &setOutlineColor (EColor value) noexcept override;

  IRectangle &setFillColor (EColor value) noexcept override;

  float getRotation () const noexcept override;

  const VectorAdapter &getSize () const noexcept override;

  const VectorAdapter &getScale () const noexcept override;

  const ETexture &getTexture () const noexcept override;

  const VectorAdapter &getPosition () const noexcept override;

  const VectorAdapter &getOutlineSize () const noexcept override;

  const RectAdapter getRect () const noexcept override;

  const EColor &getOutlineColor () const noexcept override;

  const EColor &getFillColor () const noexcept override;
};
#endif
