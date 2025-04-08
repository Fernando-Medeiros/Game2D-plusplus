#ifndef ENUM_SOUND_H
#define ENUM_SOUND_H

#include <cstdint>

namespace core::enums {

enum class Sound : uint8_t {
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
} // namespace core::enums
#endif
