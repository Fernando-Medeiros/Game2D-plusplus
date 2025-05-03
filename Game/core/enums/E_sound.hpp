#ifndef ENUM_SOUND_HPP
#define ENUM_SOUND_HPP

#include <cstdint>

enum class ESound : uint8_t
{
  None,
  /// region Ambient
  Rain,
  /// region UI
  ButtonClicked,
  /// region Combat
  Damage,
  Miss,
  Parry,
  /// region Others
  Drink,
  /// region Step
  StepDirtA,
  StepDirtB,
  StepDirtC,
  StepDirtD,
  StepIceA,
  StepIceB,
  StepIceC,
  StepIceD,
  StepLeavesA,
  StepLeavesB,
  StepMudA,
  StepMudB,
  StepMudC,
  StepMudD,
  StepSandA,
  StepSandB,
  StepSandC,
  StepSandD,
  StepSnowA,
  StepSnowB,
  StepSnowC,
  StepSnowD,
};
#endif
