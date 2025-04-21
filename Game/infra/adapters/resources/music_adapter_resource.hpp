#ifndef ADAPTER_MUSIC_RESOURCE_HPP
#define ADAPTER_MUSIC_RESOURCE_HPP

#include <I_drawable.hpp>
#include <cassert>
#include <raylib.h>
#include <variant>

class MusicAdapterResource
{
private:
    Music _music;
    bool _valid = false;

public:
    MusicAdapterResource(const ResourceVariant &resource) noexcept
    {
        if (std::holds_alternative<Music>(resource)) {
            _music = std::get<Music>(resource);
            _valid = true;
        }
    }

    ~MusicAdapterResource() noexcept
    {
        if (_valid) {
            stop();
            UnloadMusicStream(_music);
        }
    }

    void play() noexcept { PlayMusicStream(_music); };
    void stop() noexcept { StopMusicStream(_music); };
    void update() noexcept { UpdateMusicStream(_music); };

    void setLoop(bool loop) noexcept { _music.looping = loop; };
    void setVolume(float volume) noexcept { SetMusicVolume(_music, volume); };

    float getVolume() const noexcept { return GetMasterVolume(); };

    operator Music() const noexcept { return _music; };
};
#endif
