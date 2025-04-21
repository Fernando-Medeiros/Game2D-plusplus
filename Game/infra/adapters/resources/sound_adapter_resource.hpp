#ifndef ADAPTER_SOUND_RESOURCE_HPP
#define ADAPTER_SOUND_RESOURCE_HPP

#include <I_drawable.hpp>
#include <cassert>
#include <raylib.h>
#include <variant>

class SoundAdapterResource
{
private:
    Sound _sound;
    bool _valid = false;

public:
    SoundAdapterResource(const ResourceVariant &resource) noexcept
    {
        if (std::holds_alternative<Sound>(resource)) {
            _sound = std::get<Sound>(resource);
            _valid = true;
        }
    }

    ~SoundAdapterResource() noexcept
    {
        if (_valid) {
            UnloadSound(_sound);
        }
    }

    void play() noexcept { PlaySound(_sound); };

    void setVolume(float volume) noexcept { SetSoundVolume(_sound, volume); };

    float getVolume() noexcept { return GetMasterVolume(); };

    operator Sound() const noexcept { return _sound; };
};
#endif
