#include <logger_hud.hpp>

void
LoggerHud::initialize () noexcept
{
  _rectangle = std::make_unique<RectangleAdapter> ();

  _rectangle->setSize (VectorAdapter{ 50, 50 })
      .setPosition (VectorAdapter{ 250, 300 })
      .setTexture (ETexture::ButtonDefault)
      .setFillColor (EColor::CornFlowerBlue);
}

void
LoggerHud::dispose () noexcept
{
  _rectangle.release ();
}

void
LoggerHud::render (WindowArgs &window) noexcept
{
  window.render (*_rectangle);
}
