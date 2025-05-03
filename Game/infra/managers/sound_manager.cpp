#include <sound_args.hpp>
#include <sound_manager.hpp>

SoundManager &
SoundManager::withResourceManager (
    const std::shared_ptr<ResourceManager> &ptr) noexcept
{
  _resourceManager = ptr;
  return *this;
}

void
SoundManager::update () noexcept
{
  if (_music)
    {
      _music->update ();
    }
}

void
SoundManager::execute (const IEventArgs &sender) noexcept
{
  auto sound = sender.toSecurePtr<SoundArgs> ();

  if (sound == nullptr)
    return;

  if (const auto &enumSound = sound->getSound (); enumSound != ESound::None)
    {
      const auto &adapter
          = _resourceManager->load<ResourceManager::SoundResource> (enumSound);

      adapter->setVolume (1);
      adapter->play ();
    }

  if (const auto &enumMusic = sound->getMusic (); enumMusic != EMusic::None)
    {
      if (_music)
        {
          _music->stop ();
          _music->dispose ();
          _music.release ();
        }

      _music = std::move (
          _resourceManager->load<ResourceManager::MusicResource> (enumMusic));

      _music->setVolume (1);
      _music->setLoop (true);
      _music->play ();
    }
}

void
SoundManager::dispose () noexcept
{
  if (_music)
    {
      _music->dispose ();
      _music.release ();
    }

  _resourceManager.reset ();
}
