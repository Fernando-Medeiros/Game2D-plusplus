#ifndef KEYBOARD_TRANSPORT_HPP
#define KEYBOARD_TRANSPORT_HPP

#include <E_keyboard_key.hpp>

struct KeyboardTransport
{
private:
  EKeyboardKey _keyPressed{ EKeyboardKey::None },
      _keyDown{ EKeyboardKey::None };

public:
  KeyboardTransport (EKeyboardKey keyPressed) noexcept
      : _keyPressed{ keyPressed } {};

  KeyboardTransport (EKeyboardKey keyPressed, EKeyboardKey keyDown) noexcept
      : _keyPressed{ keyPressed },
        _keyDown{ keyDown } {};

  ~KeyboardTransport () noexcept = default;

  [[nodiscard]] const bool
  altIsPressed () const noexcept
  {
    return _keyDown == EKeyboardKey::ALT;
  };

  [[nodiscard]] const bool

  shiftIsPressed () const noexcept
  {
    return _keyDown == EKeyboardKey::SHIFT;
  };

  [[nodiscard]] const bool

  controlIsPressed () const noexcept
  {
    return _keyDown == EKeyboardKey::CONTROL;
  };

  [[nodiscard]] const EKeyboardKey &
  getPressedKey () const noexcept
  {
    return _keyPressed;
  };
};

#endif // KEYBOARD_TRANSPORT_HPP
