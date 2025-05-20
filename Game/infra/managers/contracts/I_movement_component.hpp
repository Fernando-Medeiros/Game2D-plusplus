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

  [[nodiscard]] virtual IMovementComponent
  WithEntity (IBody2D &linkedEntity) noexcept
      = 0;

  [[nodiscard]] virtual EAnchor GetAnchor () const noexcept = 0;

  [[nodiscard]] virtual INode2D
  GetAnchorForKey (IEventArgs *keyboardCode) const noexcept
      = 0;

  virtual void RotateAnchor (IEventArgs *keyboardCode) noexcept = 0;

  virtual void MoveTo (IEventArgs *keyboardCode) noexcept = 0;

  virtual void Dispose () noexcept = 0;
};

#endif // I_MOVEMENT_COMPONENT_HPP
