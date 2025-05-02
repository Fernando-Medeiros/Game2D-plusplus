#ifndef ADAPTER_SPRITE_HPP
#define ADAPTER_SPRITE_HPP

#include <I_drawable.hpp>
#include <I_sprite.hpp>

class SpriteAdapter : public ISprite, public IDrawable
{
private:
  ETexture _texture{ ETexture::NONE };
  VectorAdapter _size, _scale, _center, _position;
  float _rotation{ 0.0f };

public:
  ISprite &setRotation (float value) noexcept override;

  ISprite &setSize (VectorAdapter value) noexcept override;

  ISprite &setScale (VectorAdapter value) noexcept override;

  ISprite &setPosition (VectorAdapter value) noexcept override;

  ISprite &setTexture (ETexture value) noexcept override;

  [[nodiscard]] float getRotation () const noexcept override;

  [[nodiscard]] const VectorAdapter &getSize () const noexcept override;

  [[nodiscard]] const VectorAdapter &getScale () const noexcept override;

  [[nodiscard]] const ETexture &getTexture () const noexcept override;

  [[nodiscard]] const VectorAdapter &getPosition () const noexcept override;

  [[nodiscard]] const RectAdapter getRect () const noexcept override;
};
#endif
