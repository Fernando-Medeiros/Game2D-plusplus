#ifndef I_SPRITE_HPP
#define I_SPRITE_HPP

#include <E_color.hpp>
#include <E_texture.hpp>
#include <rect_adapter.hpp>
#include <vector_adapter.hpp>

class ISprite
{
public:
  virtual ~ISprite () noexcept = default;

  virtual ISprite &setRotation (float value) noexcept = 0;

  virtual ISprite &setSize (VectorAdapter value) noexcept = 0;

  virtual ISprite &setScale (VectorAdapter value) noexcept = 0;

  virtual ISprite &setPosition (VectorAdapter value) noexcept = 0;

  virtual ISprite &setTexture (ETexture value) noexcept = 0;

  [[nodiscard]] virtual float getRotation () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getSize () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getScale () const noexcept = 0;

  [[nodiscard]] virtual const ETexture &getTexture () const noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getPosition () const noexcept = 0;

  [[nodiscard]] virtual const RectAdapter getRect () const noexcept = 0;
};

#endif // I_SPRITE_HPP
