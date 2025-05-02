#include <sprite_adapter.hpp>

ISprite &
SpriteAdapter::setRotation (float value) noexcept
{
  _rotation = value;
  return *this;
};

ISprite &
SpriteAdapter::setSize (VectorAdapter value) noexcept
{
  _size = value;
  return *this;
}

ISprite &
SpriteAdapter::setScale (VectorAdapter value) noexcept
{
  _scale = value;
  return *this;
}

ISprite &
SpriteAdapter::setPosition (VectorAdapter value) noexcept
{
  _position = value;
  return *this;
}

ISprite &
SpriteAdapter::setTexture (ETexture value) noexcept
{
  _texture = value;
  return *this;
}

float
SpriteAdapter::getRotation () const noexcept
{
  return _rotation;
}

const VectorAdapter &
SpriteAdapter::getSize () const noexcept
{
  return _size;
}

const VectorAdapter &
SpriteAdapter::getScale () const noexcept
{
  return _scale;
}

const ETexture &
SpriteAdapter::getTexture () const noexcept
{
  return _texture;
}

const VectorAdapter &
SpriteAdapter::getPosition () const noexcept
{
  return _position;
}

const RectAdapter
SpriteAdapter::getRect () const noexcept
{
  return RectAdapter (_position, _size);
}
