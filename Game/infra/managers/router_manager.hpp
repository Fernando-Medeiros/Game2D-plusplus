#ifndef ROUTER_MANAGER_HPP
#define ROUTER_MANAGER_HPP

#include <E_hud.hpp>
#include <E_scene.hpp>
#include <I_hud.hpp>
#include <I_scene.hpp>
#include <constants_adapter.hpp>
#include <constants_callback.hpp>
#include <event.hpp>
#include <functional>
#include <memory>
#include <unordered_map>

class RouterManager
{
public:
  using Hud = std::unique_ptr<IHud>;

  using Scene = std::unique_ptr<IScene>;

  using HudCollection = std::unordered_map<EHud, Hud>;

  using HudFactory = std::unordered_map<EHud, std::function<Hud ()> >;

  using SceneFactory = std::unordered_map<EScene, std::function<Scene ()> >;

private:
  HudFactory _hudFactory;
  SceneFactory _sceneFactory;

  Scene _currentScene;
  HudCollection _huds;
  EScene _swapEScene{ EScene::Main };
  EScene _currentEScene{ EScene::None };

public:
  template <typename T>
  RouterManager &
  addTransient (const EHud &key)
  {
    static_assert (std::is_base_of_v<IHud, T>);

    _hudFactory[key] = [] () -> Hud { return std::make_unique<T> (); };
    return *this;
  }

  template <typename T>
  RouterManager &
  addTransient (const EScene &key)
  {
    static_assert (std::is_base_of_v<IScene, T>);

    _sceneFactory[key] = [] () -> Scene { return std::make_unique<T> (); };
    return *this;
  }

  void render (WindowArgs &window) noexcept;

  void execute (const IEventArgs &sender) noexcept;

  void dispose () noexcept;

private:
  [[nodiscard]] Hud createHud (const EHud &key) const;

  [[nodiscard]] Scene createScene (const EScene &key) const;
};

#endif // ROUTER_MANAGER_HPP
