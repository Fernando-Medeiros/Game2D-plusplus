#ifndef ENUM_ALIGNMENT_HPP
#define ENUM_ALIGNMENT_HPP

#include <cstdint>

enum class EAlignment : uint8_t
{
  Malignant = 0,
  Chaotic = 1,
  Heretic = 2,
  Neutral = 3,
  Loyal = 4,
  Honored = 5,
};
#endif
