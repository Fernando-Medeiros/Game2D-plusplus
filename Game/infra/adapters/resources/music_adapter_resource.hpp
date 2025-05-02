#ifndef ADAPTER_MUSIC_RESOURCE_HPP
#define ADAPTER_MUSIC_RESOURCE_HPP

#include <constants_adapter.hpp>

class MusicAdapterResource
{
private:
  ExtMusic _music;

public:
  MusicAdapterResource (const ExtMusic &resource) noexcept : _music{ resource }
  {
  }

    ~MusicAdapterResource () noexcept = default;

    void play() noexcept { PlayMusicStream(_music); }

    void stop() noexcept { StopMusicStream(_music); }

    void update() noexcept { UpdateMusicStream(_music); }

    void setLoop(bool loop) noexcept { _music.looping = loop; }

    void setVolume(float volume) noexcept { SetMusicVolume(_music, volume); }

    float getVolume() const noexcept { return GetMasterVolume(); }

    operator ExtMusic () const noexcept { return _music; }

    void
    dispose () const noexcept
    {
      UnloadMusicStream (_music);
    }
};
#endif
