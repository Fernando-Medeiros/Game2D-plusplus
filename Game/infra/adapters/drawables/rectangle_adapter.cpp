#include <rectangle_adapter.hpp>

IRectangle &
RectangleAdapter::setRotation (float value) noexcept
{
  _rotation = value;
  return *this;
};

IRectangle &
RectangleAdapter::setSize (VectorAdapter value) noexcept
{
  _size = value;
  return *this;
}

IRectangle &
RectangleAdapter::setScale (VectorAdapter value) noexcept
{
  _scale = value;
  return *this;
}

IRectangle &
RectangleAdapter::setPosition (VectorAdapter value) noexcept
{
  _position = value;
  return *this;
}

IRectangle &
RectangleAdapter::setTexture (ETexture value) noexcept
{
  _texture = value;
  return *this;
}

IRectangle &
RectangleAdapter::setOutlineSize (VectorAdapter value) noexcept
{
  _outlineSize = value;
  return *this;
}

IRectangle &
RectangleAdapter::setOutlineColor (EColor value) noexcept
{
  _outlineColor = value;
  return *this;
}

IRectangle &
RectangleAdapter::setFillColor (EColor value) noexcept
{
  _fillColor = value;
  return *this;
}

float
RectangleAdapter::getRotation () const noexcept
{
  return _rotation;
}

const VectorAdapter &
RectangleAdapter::getSize () const noexcept
{
  return _size;
}

const VectorAdapter &
RectangleAdapter::getScale () const noexcept
{
  return _scale;
}

const ETexture &
RectangleAdapter::getTexture () const noexcept
{
  return _texture;
}

const VectorAdapter &
RectangleAdapter::getPosition () const noexcept
{
  return _position;
}

const VectorAdapter &
RectangleAdapter::getOutlineSize () const noexcept
{
  return _outlineSize;
}

const RectAdapter
RectangleAdapter::getRect () const noexcept
{
  return RectAdapter (_position, _size);
}

const EColor &
RectangleAdapter::getOutlineColor () const noexcept
{
  return _outlineColor;
}

const EColor &
RectangleAdapter::getFillColor () const noexcept
{
  return _fillColor;
}
