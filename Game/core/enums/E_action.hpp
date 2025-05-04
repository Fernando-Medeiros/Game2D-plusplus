#ifndef ENUM_ACTION_HPP
#define ENUM_ACTION_HPP

#include <cstdint>

enum class EAction : uint8_t
{
  None,
  Increment,
  Decrement,
  Cancel,
  Lock,
  Unlock,
};
#endif
