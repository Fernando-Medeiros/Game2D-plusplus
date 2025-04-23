#ifndef KEYBOARD_TRANSPORT_HPP
#define KEYBOARD_TRANSPORT_HPP

#include <E_mouse.hpp>
#include <string>

struct KeyboardTransport
{
private:
    const std::string _code;
    bool _alt, _shift, _control;

public:
    KeyboardTransport(std::string code) noexcept
        : _code{code}
    {
        _alt = code.contains("Alt");
        _shift = code.contains("Shift");
        _control = code.contains("Control");
    }

    ~KeyboardTransport() noexcept = default;

    [[nodiscard]] const bool &altIsPressed() const noexcept { return _alt; };
    [[nodiscard]] const bool &shiftIsPressed() const noexcept { return _shift; };
    [[nodiscard]] const bool &controlIsPressed() const noexcept { return _control; };
    [[nodiscard]] const std::string &getPressedKey() const noexcept { return _code; };
};

#endif // KEYBOARD_TRANSPORT_HPP
