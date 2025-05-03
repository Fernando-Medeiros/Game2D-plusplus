#include <resource_manager.hpp>

void
ResourceManager::dispose () noexcept
{
  for (const auto &[_, resource] : _fonts)
    resource->dispose ();

  for (const auto &[_, resource] : _musics)
    resource->dispose ();

  for (const auto &[_, resource] : _sounds)
    resource->dispose ();

  for (const auto &[_, resource] : _textures)
    resource->dispose ();

  _fonts.clear ();
  _musics.clear ();
  _sounds.clear ();
  _textures.clear ();
}
