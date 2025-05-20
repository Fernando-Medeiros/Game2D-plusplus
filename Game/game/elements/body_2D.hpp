#ifndef BODY_2D_HPP
#define BODY_2D_HPP

#include <I_body_2D.hpp>

class Body2D : public IBody2D
{
public:
  Body2D ();

public:
  // IBody2D interface
public:
  INode2D &GetNode () const noexcept override;
  ETexture &GetTexture () const noexcept override;
  ILightComponent &GetLightComponent () const noexcept override;
  IDamageComponent &GetDamageComponent () const noexcept override;
  IMovementComponent &GetMovementComponent () const noexcept override;
  IStatisticComponent &GetStatisticComponent () const noexcept override;
  void Execute (IEventArgs *sender) noexcept override;
  void SetBody (IBody2D *entity) noexcept override;
  void SetNode (INode2D *node) noexcept override;
  void SetSprite (ETexture *sprite) noexcept override;
  void Translate (INode2D &linkedNode) noexcept override;
  bool IsDiposed () const noexcept override;
  void Dispose () noexcept override;
};

#endif // BODY_2D_HPP
