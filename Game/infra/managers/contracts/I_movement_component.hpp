#ifndef I_MOVEMENT_COMPONENT_HPP
#define I_MOVEMENT_COMPONENT_HPP

#include <E_anchor.hpp>

class INode2D;
class IBody2D;
class IEventArgs;

class IMovementComponent
{
public:
  virtual ~IMovementComponent () noexcept = default;

  [[nodiscard]] virtual const EAnchor &getAnchor () const noexcept = 0;

  [[nodiscard]] virtual const INode2D &getAnchorForKey (IEventArgs *keyboardCode) const noexcept = 0;

  virtual void rotateAnchor (IEventArgs *keyboardCode) noexcept = 0;

  virtual void moveTo (IEventArgs *keyboardCode) noexcept = 0;

  virtual void dispose () noexcept = 0;
};

#endif // I_MOVEMENT_COMPONENT_HPP
