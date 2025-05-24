#ifndef I_BODY_2D_HPP
#define I_BODY_2D_HPP

#include <E_body.hpp>
#include <E_texture.hpp>

// Forward Declaration
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

  [[nodiscard]] virtual INode2D &getNode () const noexcept = 0;

  [[nodiscard]] virtual ETexture &getTexture () const noexcept = 0;

  [[nodiscard]] virtual ILightComponent &getLightComponent () const noexcept
      = 0;

  [[nodiscard]] virtual IDamageComponent &getDamageComponent () const noexcept
      = 0;

  [[nodiscard]] virtual IMovementComponent &
  getMovementComponent () const noexcept
      = 0;

  [[nodiscard]] virtual IStatisticComponent &
  getStatisticComponent () const noexcept
      = 0;

  virtual void execute (IEventArgs *sender) noexcept = 0;

  virtual void setBody (IBody2D *entity) noexcept = 0;

  virtual void setNode (INode2D *node) noexcept = 0;

  virtual void setSprite (ETexture *sprite) noexcept = 0;

  virtual void translate (INode2D &linkedNode) noexcept = 0;

  virtual bool isDiposed () const noexcept = 0;

  virtual void dispose () noexcept = 0;
};

#endif // I_BODY_2D_HPP
