#ifndef MOUSE_ARGS_H
#define MOUSE_ARGS_H

#include <E_mouse.hpp>
#include <event.hpp>
#include <vector_adapter.hpp>

struct MouseArgs : public EventArgs
{
private:
    const EMouse _pressedButton;
    const VectorAdapter _position;

public:
    MouseArgs(EMouse button, VectorAdapter position) noexcept
        : _position{position}
        , _pressedButton{button} {};

    ~MouseArgs() noexcept = default;

    [[nodiscard]] const VectorAdapter &getPosition() const noexcept { return _position; };
    [[nodiscard]] const EMouse &getPressedButton() const noexcept { return _pressedButton; };
};
#endif // MOUSE_ARGS_H
