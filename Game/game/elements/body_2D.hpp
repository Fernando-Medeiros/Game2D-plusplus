#ifndef BODY_2D_HPP
#define BODY_2D_HPP

#include <I_body_2D.hpp>

class Body2D : public IBody2D
{
public:
  Body2D () noexcept;

  INode2D &getNode () const noexcept override;

  ETexture &getTexture () const noexcept override;

  ILightComponent &getLightComponent () const noexcept override;

  IDamageComponent &getDamageComponent () const noexcept override;

  IMovementComponent &getMovementComponent () const noexcept override;

  IStatisticComponent &getStatisticComponent () const noexcept override;

  void execute (IEventArgs *sender) noexcept override;

  void setBody (IBody2D *entity) noexcept override;

  void setNode (INode2D *node) noexcept override;

  void setSprite (ETexture *sprite) noexcept override;

  void translate (INode2D &linkedNode) noexcept override;

  bool isDiposed () const noexcept override;

  void dispose () noexcept override;
};

#endif // BODY_2D_HPP
