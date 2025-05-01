#ifndef ENUM_ADAPTER_HPP
#define ENUM_ADAPTER_HPP

#include <E_keyboard_key.hpp>
#include <magic_enum/magic_enum.hpp>
#include <raylib.h>

template <typename E>
requires std::is_enum_v<E> [[nodiscard]] constexpr EKeyboardKey
toKeyboardKey (const E &externKeyboard) noexcept
{
  std::string_view externName = magic_enum::enum_name<E> (externKeyboard);

  size_t lastUnderscore = externName.rfind ('_');

  std::string_view internalName = externName.substr (lastUnderscore + 1);

  EKeyboardKey key = magic_enum::enum_cast<EKeyboardKey> (internalName)
                         .value_or (EKeyboardKey::None);
  return key;
}

#endif // ENUM_ADAPTER_HPP
