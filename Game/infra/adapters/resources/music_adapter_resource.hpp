#ifndef ADAPTER_MUSIC_RESOURCE_HPP
#define ADAPTER_MUSIC_RESOURCE_HPP

#include <cassert>
#include <raylib.h>

class MusicAdapterResource
{
private:
    Music _music;

public:
    MusicAdapterResource(const Music &resource) noexcept
        : _music{resource}
    {}

    ~MusicAdapterResource() noexcept { UnloadMusicStream(_music); }

    void play() noexcept { PlayMusicStream(_music); }
    void stop() noexcept { StopMusicStream(_music); }
    void update() noexcept { UpdateMusicStream(_music); }

    void setLoop(bool loop) noexcept { _music.looping = loop; }
    void setVolume(float volume) noexcept { SetMusicVolume(_music, volume); }

    float getVolume() const noexcept { return GetMasterVolume(); }

    operator Music() const noexcept { return _music; }
};
#endif
