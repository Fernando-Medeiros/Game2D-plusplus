#ifndef ENUM_ADAPTER_HPP
#define ENUM_ADAPTER_HPP

#include <E_keyboard_key.hpp>
#include <E_mouse.hpp>
#include <constants_adapter.hpp>

template <IsExtKeyboard E>
[[nodiscard]] constexpr EKeyboardKey
toKeyboardKey (const E &externEnum) noexcept
{
  std::string_view externName = magic_enum::enum_name<E> (externEnum);

  size_t lastUnderscore = externName.rfind ('_');

  std::string_view internalName = externName.substr (lastUnderscore + 1);

  return magic_enum::enum_cast<EKeyboardKey> (internalName)
      .value_or (EKeyboardKey::NONE);
}

template <IsExtMouseButton E>
[[nodiscard]] constexpr EMouseButton
toMouseKey (const E &externEnum) noexcept
{
  std::string_view externName = magic_enum::enum_name<E> (externEnum);

  size_t lastUnderscore = externName.rfind ('_');

  std::string_view internalName = externName.substr (lastUnderscore + 1);

  return magic_enum::enum_cast<EMouseButton> (internalName)
      .value_or (EMouseButton::NONE);
}

#endif // ENUM_ADAPTER_HPP
