#ifndef ENUM_EVENT_HPP
#define ENUM_EVENT_HPP

#include <cstdint>

enum class EEvent : uint8_t
{
  /// region Binding
  Camera,
  ExitGame,
  Logger,
  Notification,
  Route,
  SaveGame,
  NodeSelected,
  Sound,
  Animation,
  /// region Window
  WindowResized,
  TextEntered,
  KeyPressed,
  KeyReleased,
  MouseMoved,
  MouseWheelScrolled,
  MouseButtonPressed,
  MouseButtonReleased,
};
#endif
