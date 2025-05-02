#ifndef ADAPTER_SOUND_RESOURCE_HPP
#define ADAPTER_SOUND_RESOURCE_HPP

#include <constants_adapter.hpp>

class SoundAdapterResource
{
private:
  ExtSound _sound;

public:
  SoundAdapterResource (const ExtSound &resource) noexcept : _sound{ resource }
  {}

    ~SoundAdapterResource () noexcept = default;

    void play() noexcept { PlaySound(_sound); }

    float getVolume() noexcept { return GetMasterVolume(); }

    void setVolume(float volume) noexcept { SetSoundVolume(_sound, volume); }

    operator ExtSound () const noexcept { return _sound; }

    void
    dispose () const noexcept
    {
      UnloadSound (_sound);
    }
};
#endif
