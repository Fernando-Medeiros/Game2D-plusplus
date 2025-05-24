#ifndef I_DAMAGE_COMPONENT_HPP
#define I_DAMAGE_COMPONENT_HPP

class IBody2D;
class IEventArgs;

class IDamageComponent
{
public:
  virtual ~IDamageComponent () noexcept = default;

  [[nodiscard]] virtual IDamageComponent &
  WithEntity (IBody2D &linkedEntity) noexcept
      = 0;

  virtual void receiveDamage (int damage) noexcept = 0;

  virtual void damageTo (IEventArgs *keyboardCode) noexcept = 0;

  virtual void dispose () noexcept = 0;
};

#endif // I_DAMAGE_COMPONENT_HPP
