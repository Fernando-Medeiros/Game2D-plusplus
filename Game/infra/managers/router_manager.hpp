#ifndef ROUTER_MANAGER_HPP
#define ROUTER_MANAGER_HPP

#include <E_hud_route.hpp>
#include <E_scene_route.hpp>
#include <I_hud.hpp>
#include <I_scene.hpp>
#include <functional>
#include <memory>
#include <unordered_map>

class RouterManager
{
public:
  using Hud = std::unique_ptr<IHud>;

  using Scene = std::unique_ptr<IScene>;

  using SceneCollection
      = std::unordered_map<ESceneRoute, std::function<Scene ()> >;

  using HudCollection = std::unordered_map<EHudRoute, std::function<Hud ()> >;

private:
  HudCollection _hudFactory;
  SceneCollection _sceneFactory;

public:
  template <typename T>
  RouterManager &
  addTransient (const EHudRoute &key)
  {
    static_assert (std::is_base_of_v<IHud, T>);

    _hudFactory[key] = [] () -> Hud { return std::make_unique<T> (); };
    return *this;
  }

  template <typename T>
  RouterManager &
  addTransient (const ESceneRoute &key)
  {
    static_assert (std::is_base_of_v<IScene, T>);

    _sceneFactory[key] = [] () -> Scene { return std::make_unique<T> (); };
    return *this;
  }

  void dispose () noexcept;

private:
  [[nodiscard]] Hud createHud (const EHudRoute &key) const;

  [[nodiscard]] Scene createScene (const ESceneRoute &key) const;
};

#endif // ROUTER_MANAGER_HPP
