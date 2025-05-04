#ifndef CONSTANTS_ADAPTER_HPP
#define CONSTANTS_ADAPTER_HPP

#include <array>
#include <magic_enum/magic_enum.hpp>
#include <raylib.h>

// VECTOR --------------------
using Coords = uint16_t;
using Position = uint8_t;
using ExtVector2 = Vector2;
// VECTOR --------------------

// VIEWPORT ------------------
using ExtViewport = Camera2D;
// VIEWPORT ------------------

// RESOURCE ------------------
using ExtFont = Font;
using ExtSound = Sound;
using ExtMusic = Music;
using ExtTexture = Texture;
// RESOURCE ------------------

// INPUT ---------------------
using ExtMouseButton = MouseButton;
using ExtKeyboardKey = KeyboardKey;

constexpr std::array COMBINED_KEYBOARD_KEYS{
  ExtKeyboardKey::KEY_RIGHT_ALT,    ExtKeyboardKey::KEY_RIGHT_CONTROL,
  ExtKeyboardKey::KEY_RIGHT_SHIFT,  ExtKeyboardKey::KEY_LEFT_ALT,
  ExtKeyboardKey::KEY_LEFT_CONTROL, ExtKeyboardKey::KEY_LEFT_SHIFT,
};

constexpr std::array MOUSE_BUTTONS{
  magic_enum::enum_values<ExtMouseButton> ()
};
// INPUT ---------------------

// CONCEPTS ------------------
template <typename E>
concept IsExtKeyboard = std::is_enum_v<E> && std::is_same_v<E, ExtKeyboardKey>;

template <typename E>
concept IsExtMouseButton
    = std::is_enum_v<E> && std::is_same_v<E, ExtMouseButton>;

template <typename E> concept IsEnum = std::is_enum_v<E>;
// CONCEPTS ------------------
#endif // CONSTANTS_ADAPTER_HPP
