#include <world_scene.hpp>

void
WorldScene::initialize () noexcept
{
  _text = std::make_unique<TextAdapter> ();

  _text->setText ("Hello World")
      .setFontSize (30)
      .setFontSpacing (3)
      .setFont (EFont::Romulus)
      .setFontColor (EColor::White)
      .setPosition (VectorAdapter (200, 100));
}

void
WorldScene::dispose () noexcept
{
  _text.release ();
}

void
WorldScene::render (WindowArgs &window) noexcept
{
  window.render (*_text);
}
