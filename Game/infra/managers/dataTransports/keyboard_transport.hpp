#ifndef KEYBOARD_TRANSPORT_HPP
#define KEYBOARD_TRANSPORT_HPP

#include <E_mouse.hpp>
#include <string>

struct KeyboardTransport
{
private:
    std::string code;
    bool alt, shift, control;

public:
    KeyboardTransport(std::string code) noexcept
    {
        this->code = code;
        alt = code.contains("Alt");
        shift = code.contains("Shift");
        control = code.contains("Control");
    }

    ~KeyboardTransport() noexcept = default;

    [[nodiscard]] const bool &altIsPressed() const noexcept { return alt; };
    [[nodiscard]] const bool &shiftIsPressed() const noexcept { return shift; };
    [[nodiscard]] const bool &controlIsPressed() const noexcept { return control; };
    [[nodiscard]] const std::string &getPressedKey() const noexcept { return code; };
};

#endif // KEYBOARD_TRANSPORT_HPP
