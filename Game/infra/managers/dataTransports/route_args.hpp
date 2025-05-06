#ifndef ROUTE_ARGS_HPP
#define ROUTE_ARGS_HPP

#include <E_hud.hpp>
#include <E_scene.hpp>
#include <event.hpp>
#include <vector_adapter.hpp>

class RouteArgs : public IEventArgs
{
  EHud _hud{ EHud::None };
  EScene _scene{ EScene::None };

public:
  RouteArgs (const EHud &hud) noexcept : _hud{ hud } {}

  RouteArgs (const EScene &scene) noexcept : _scene{ scene } {}

  ~RouteArgs () noexcept = default;

  [[nodiscard]] const EHud &
  getHud () const noexcept
  {
    return _hud;
  }

  [[nodiscard]] const EScene &
  getScene () const noexcept
  {
    return _scene;
  }
};

#endif // ROUTE_ARGS_HPP
