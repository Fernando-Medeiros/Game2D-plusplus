#ifndef KEYBOARD_ARGS_H
#define KEYBOARD_ARGS_H

#include <E_keyboard_key.hpp>
#include <event.hpp>

struct KeyboardArgs : public EventArgs
{
private:
  EKeyboardKey _keyPressed{ EKeyboardKey::None },
      _keyDown{ EKeyboardKey::None };

public:
  KeyboardArgs (EKeyboardKey keyPressed) noexcept
      : _keyPressed{ keyPressed } {};

  KeyboardArgs (EKeyboardKey keyPressed, EKeyboardKey keyDown) noexcept
      : _keyPressed{ keyPressed },
        _keyDown{ keyDown } {};

  ~KeyboardArgs () noexcept = default;

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

#endif // KEYBOARD_ARGS_H
