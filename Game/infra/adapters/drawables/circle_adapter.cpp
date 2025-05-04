#include <circle_adapter.hpp>

ICircle &
CircleAdapter::setRadius (float value) noexcept
{
  _radius = value;
  return *this;
}

ICircle &
CircleAdapter::setScale (VectorAdapter value) noexcept
{
  _scale = value;
  return *this;
}

ICircle &
CircleAdapter::setPosition (VectorAdapter value) noexcept
{
  _position = value;
  return *this;
}

ICircle &
CircleAdapter::setTexture (ETexture value) noexcept
{
  _texture = value;
  return *this;
}

ICircle &
CircleAdapter::setOutlineSize (float value) noexcept
{
  _outlineSize = value;
  return *this;
}

ICircle &
CircleAdapter::setOutlineColor (EColor value) noexcept
{
  _outlineColor = value;
  return *this;
}

ICircle &
CircleAdapter::setFillColor (EColor value) noexcept
{
  _fillColor = value;
  return *this;
}

float
CircleAdapter::getRadius () const noexcept
{
  return _radius;
}

const VectorAdapter &
CircleAdapter::getSize () const noexcept
{
  return _size;
}

const VectorAdapter &
CircleAdapter::getScale () const noexcept
{
  return _scale;
}

const ETexture &
CircleAdapter::getTexture () const noexcept
{
  return _texture;
}

const VectorAdapter &
CircleAdapter::getPosition () const noexcept
{
  return _position;
}

const float &
CircleAdapter::getOutlineSize () const noexcept
{
  return _outlineSize;
}

const RectAdapter
CircleAdapter::getRect () const noexcept
{
  return RectAdapter (_position, _size);
}

const EColor &
CircleAdapter::getOutlineColor () const noexcept
{
  return _outlineColor;
}

const EColor &
CircleAdapter::getFillColor () const noexcept
{
  return _fillColor;
}
