#ifndef BODY_2D_HPP
#define BODY_2D_HPP

#include <I_body_2D.hpp>
#include <node_2D.hpp>
#include <movement_component.hpp>

class Body2D : public IBody2D
{
private:
    bool disposed;
    EBody _source;
    Node2D _node;
    MovementComponent _movement;
    
public:
  Body2D(Body2D& body) noexcept;

  Body2D (const INode2D& linkedNode) noexcept;

  [[nodiscard]] const INode2D &getNode () const noexcept override;

  //[[nodiscard]] const ETexture &getTexture () const noexcept override;

  //[[nodiscard]] const ILightComponent &getLightComponent () const noexcept override;

  //[[nodiscard]] const IDamageComponent &getDamageComponent () const noexcept override;

  [[nodiscard]] const IMovementComponent &getMovementComponent () const noexcept override;

  //[[nodiscard]] const IStatisticComponent &getStatisticComponent () const noexcept override;

  void execute (IEventArgs *sender) noexcept override;

  void setBody (IBody2D *entity) noexcept override;

  void setNode (INode2D *node) noexcept override;

  void setSprite (ETexture *sprite) noexcept override;

  void translate (INode2D &linkedNode) noexcept override;

  bool isDiposed () const noexcept override;

  void dispose () noexcept override;
};

#endif // BODY_2D_HPP
