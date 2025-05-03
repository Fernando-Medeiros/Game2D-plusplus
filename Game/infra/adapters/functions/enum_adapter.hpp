#ifndef ENUM_ADAPTER_HPP
#define ENUM_ADAPTER_HPP

#include <E_keyboard_key.hpp>
#include <E_mouse.hpp>
#include <constants_adapter.hpp>

template <IsEnum E>
[[nodiscard]] constexpr std::string_view
getEnumName (const E &enumValue) noexcept
{
  return magic_enum::enum_name<E> (enumValue);
}

template <IsEnum E>
[[nodiscard]] constexpr E
castEnum (const std::string_view &enumName, const E &defaultEnum) noexcept
{
  return magic_enum::enum_cast<E> (enumName).value_or (defaultEnum);
}

////////////////////////////////////////////////////////////////////////////////

template <IsExtKeyboard E>
[[nodiscard]] constexpr EKeyboardKey
toKeyboardKey (const E &externEnum) noexcept
{
  std::string_view externName = getEnumName (externEnum);

  size_t lastUnderscore = externName.rfind ('_');

  std::string_view internalName = externName.substr (lastUnderscore + 1);

  return castEnum (internalName, EKeyboardKey::NONE);
}

template <IsExtMouseButton E>
[[nodiscard]] constexpr EMouseButton
toMouseKey (const E &externEnum) noexcept
{
  std::string_view externName = getEnumName (externEnum);

  size_t lastUnderscore = externName.rfind ('_');

  std::string_view internalName = externName.substr (lastUnderscore + 1);

  return castEnum (internalName, EMouseButton::NONE);
}

#endif // ENUM_ADAPTER_HPP
