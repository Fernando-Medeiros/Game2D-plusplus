#ifndef ADAPTER_CIRCLE_HPP
#define ADAPTER_CIRCLE_HPP

#include <I_circle.hpp>
#include <I_drawable.hpp>

class CircleAdapter : public ICircle, public IDrawable
{
private:
  ETexture _texture{ ETexture::NONE };
  EColor _outlineColor{ EColor::White }, _fillColor{ EColor::CornFlowerBlue };
  VectorAdapter _size, _scale, _center, _position;
  float _radius{ 0.0f }, _outlineSize{ 0.f };

public:
  ICircle &setRadius (float value) noexcept override;

  ICircle &setScale (VectorAdapter value) noexcept override;

  ICircle &setPosition (VectorAdapter value) noexcept override;

  ICircle &setTexture (ETexture value) noexcept override;

  ICircle &setOutlineSize (float value) noexcept override;

  ICircle &setOutlineColor (EColor value) noexcept override;

  ICircle &setFillColor (EColor value) noexcept override;

  float getRadius () const noexcept override;

  const float &getOutlineSize () const noexcept override;

  const VectorAdapter &getSize () const noexcept override;

  const VectorAdapter &getScale () const noexcept override;

  const ETexture &getTexture () const noexcept override;

  const VectorAdapter &getPosition () const noexcept override;

  const RectAdapter getRect () const noexcept override;

  const EColor &getOutlineColor () const noexcept override;

  const EColor &getFillColor () const noexcept override;
};
#endif
