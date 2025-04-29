#include <resource_manager.hpp>

void
ResourceManager::dispose () noexcept
{
  for (const auto &[_, resource] : _fonts)
    resource.get ()->dispose ();

  for (const auto &[_, resource] : _sounds)
    resource.get ()->dispose ();

  for (const auto &[_, resource] : _textures)
    resource.get ()->dispose ();

  _fonts.clear ();
  _sounds.clear ();
  _textures.clear ();
}
