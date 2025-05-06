#include <enum_adapter.hpp>
#include <format>
#include <route_args.hpp>
#include <router_manager.hpp>
#include <stdexcept>

[[nodiscard]] RouterManager::Scene
RouterManager::createScene (const EScene &key) const
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
RouterManager::createHud (const EHud &key) const
{
  auto it = _hudFactory.find (key);

  if (it != _hudFactory.end ())
    {
      return it->second ();
    }

  throw std::runtime_error (
      std::format ("Rota não registrada: {0}", getEnumName (key)));
}

////////////////////////////////////////////////////////////////////////////////

void
RouterManager::render (WindowArgs &window) noexcept
{
  if (_currentScene != nullptr)
    _currentScene->render (window);

  for (auto &[_, hud] : _huds)
    hud->render (window);
}

void
RouterManager::execute (const IEventArgs &sender) noexcept
{
  if (const auto *args = sender.toSecurePtr<RouteArgs> ())
    {
      if (auto key = args->getHud (); key != EHud::None)
        {
          if (_huds.contains (key))
            {
              _huds[key]->dispose ();
              _huds[key].release ();
              _huds.erase (key);
              return;
            }

          _huds[key] = createHud (key);
          _huds[key]->initialize ();
        }

      if (auto key = args->getScene (); key != EScene::None)
        {
          _swapEScene = key;

          if (_currentEScene != _swapEScene)
            {
              for (auto &[_, hud] : _huds)
                hud->dispose ();

              _huds.clear ();

              _currentEScene = _swapEScene;

              if (_currentScene != nullptr)
                {
                  _currentScene->dispose ();
                  _currentScene.release ();
                }

              _currentScene = createScene (key);
              _currentScene->initialize ();
            }
        }
    }
}

void
RouterManager::dispose () noexcept
{
  for (auto &[_, hud] : _huds)
    hud->dispose ();

  _huds.clear ();
  _hudFactory.clear ();
  _sceneFactory.clear ();

  if (_currentScene != nullptr)
    _currentScene->dispose ();

  _currentScene.release ();

  _swapEScene = EScene::Main;
  _currentEScene = EScene::None;
}
