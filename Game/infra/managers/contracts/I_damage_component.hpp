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

  virtual void ReceiveDamage (int damage) noexcept = 0;

  virtual void DamageTo (IEventArgs *keyboardCode) noexcept = 0;

  virtual void Dispose () noexcept = 0;
};

#endif // I_DAMAGE_COMPONENT_HPP
