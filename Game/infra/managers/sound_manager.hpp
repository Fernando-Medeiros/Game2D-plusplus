#ifndef SOUND_MANAGER_HPP
#define SOUND_MANAGER_HPP

#include <event.hpp>
#include <memory>
#include <music_adapter_resource.hpp>
#include <resource_manager.hpp>

class SoundManager
{
private:
  std::unique_ptr<MusicAdapterResource> _music;
  std::shared_ptr<ResourceManager> _resourceManager;

public:
  SoundManager &
  withResourceManager (const std::shared_ptr<ResourceManager> &ptr) noexcept;

  void update () noexcept;

  void execute (const IEventArgs &sender) noexcept;

  void dispose () noexcept;
};
#endif // SOUND_MANAGER_HPP
