#include <enum_adapter.hpp>
#include <format>
#include <router_manager.hpp>
#include <stdexcept>

[[nodiscard]] RouterManager::Scene
RouterManager::createScene (const ESceneRoute &key) const
{
  auto it = _sceneFactory.find (key);

  if (it != _sceneFactory.end ())
    {
      return it->second ();
    }

  throw std::runtime_error (
      std::format ("Rota não registrada: {0}", getEnumName (key)));
}

[[nodiscard]] RouterManager::Hud
RouterManager::createHud (const EHudRoute &key) const
{
  auto it = _hudFactory.find (key);

  if (it != _hudFactory.end ())
    {
      return it->second ();
    }

  throw std::runtime_error (
      std::format ("Rota não registrada: {0}", getEnumName (key)));
}

void
RouterManager::dispose () noexcept
{
  _hudFactory.clear ();
  _sceneFactory.clear ();
}
