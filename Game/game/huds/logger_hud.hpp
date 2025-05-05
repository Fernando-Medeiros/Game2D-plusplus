#ifndef LOGGER_HUD_HPP
#define LOGGER_HUD_HPP

#include <I_hud.hpp>

class LoggerHud : public IHud
{
public:
  void dispose () noexcept override;
};

#endif // LOGGER_HUD_HPP
