#ifndef I_BODY_2D_HPP
#define I_BODY_2D_HPP

#include <E_body.hpp>
#include <E_texture.hpp>

class INode2D;
class IEventArgs;
class ILightComponent;
class IDamageComponent;
class IStatisticComponent;
class IMovementComponent;

class IBody2D
{
public:
  virtual ~IBody2D () noexcept = 0;

  [[nodiscard]] virtual INode2D &GetNode () const noexcept = 0;

  [[nodiscard]] virtual ETexture &GetTexture () const noexcept = 0;

  [[nodiscard]] virtual ILightComponent &GetLightComponent () const noexcept
      = 0;

  [[nodiscard]] virtual IDamageComponent &GetDamageComponent () const noexcept
      = 0;

  [[nodiscard]] virtual IMovementComponent &
  GetMovementComponent () const noexcept
      = 0;

  [[nodiscard]] virtual IStatisticComponent &
  GetStatisticComponent () const noexcept
      = 0;

  virtual void Execute (IEventArgs *sender) noexcept = 0;

  virtual void SetBody (IBody2D *entity) noexcept = 0;

  virtual void SetNode (INode2D *node) noexcept = 0;

  virtual void SetSprite (ETexture *sprite) noexcept = 0;

  virtual void Translate (INode2D &linkedNode) noexcept = 0;

  virtual bool IsDiposed () const noexcept = 0;

  virtual void Dispose () noexcept = 0;
};

#endif // I_BODY_2D_HPP
