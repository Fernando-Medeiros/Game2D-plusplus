#ifndef SOUND_ARGS_HPP
#define SOUND_ARGS_HPP

#include <E_music.hpp>
#include <E_sound.hpp>
#include <event.hpp>

class SoundArgs : public IEventArgs
{
private:
  ESound _sound{ ESound::None };
  EMusic _music{ EMusic::None };

public:
  SoundArgs (ESound sound) noexcept : _sound{ sound } {};
  SoundArgs (EMusic music) noexcept : _music{ music } {};

  [[nodiscard]] const ESound &
  getSound () const noexcept
  {
    return _sound;
  }

  [[nodiscard]] const EMusic &
  getMusic () const noexcept
  {
    return _music;
  }
};

#endif // SOUND_ARGS_HPP
