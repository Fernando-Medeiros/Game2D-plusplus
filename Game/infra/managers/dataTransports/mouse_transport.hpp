#ifndef MOUSE_TRANSPORT_HPP
#define MOUSE_TRANSPORT_HPP

#include <E_mouse.hpp>
#include <vector_adapter.hpp>

struct MouseTransport
{
private:
    const EMouse _pressedButton;
    const VectorAdapter _position;

public:
    MouseTransport(EMouse button, VectorAdapter position) noexcept
        : _position{position}
        , _pressedButton{button} {};

    ~MouseTransport() noexcept = default;

    [[nodiscard]] const VectorAdapter &getPosition() const noexcept { return _position; };
    [[nodiscard]] const EMouse &getPressedButton() const noexcept { return _pressedButton; };
};
#endif // MOUSE_TRANSPORT_HPP
