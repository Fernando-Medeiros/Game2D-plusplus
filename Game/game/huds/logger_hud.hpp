#ifndef LOGGER_HUD_HPP
#define LOGGER_HUD_HPP

#include <I_hud.hpp>
#include <memory>
#include <rectangle_adapter.hpp>

class LoggerHud : public IHud
{
private:
  std::unique_ptr<RectangleAdapter> _rectangle;

public:
  void initialize () noexcept override;

  void dispose () noexcept override;

  void render (WindowArgs &window) noexcept override;
};

#endif // LOGGER_HUD_HPP
