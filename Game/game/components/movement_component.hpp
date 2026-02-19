#ifndef MOVEMENT_COMPONENT_HPP
#define MOVEMENT_COMPONENT_HPP

#include <I_movement_component.hpp>
#include <body_2D.hpp>

class MovementComponent : public IMovementComponent
{
private:
    Body2D _linkedEntity;
    bool disposed{ false };
    EAnchor _anchor{ EAnchor::Right };

public:
    MovementComponent(Body2D& linkedEntity) noexcept;

    ~MovementComponent() noexcept = default;

    [[nodiscard]] const EAnchor &getAnchor() const noexcept;

    [[nodiscard]] const INode2D &getAnchorForKey(IEventArgs* keyboardCode) const noexcept;

    void rotateAnchor(IEventArgs* keyboardCode) noexcept;

    void moveTo(IEventArgs* keyboardCode) noexcept;

    void dispose() noexcept override;
};

#endif // MOVEMENT_COMPONENT_HPP
