#include <color_adapter.hpp>
#include <constants_adapter.hpp>
#include <enum_adapter.hpp>
#include <keyboard_args.hpp>
#include <magic_enum/magic_enum.hpp>
#include <mouse_args.hpp>
#include <rectangle_adapter.hpp>
#include <size_args.hpp>
#include <sprite_adapter.hpp>
#include <text_adapter.hpp>
#include <window_adapter.hpp>

IWindow &
WindowAdapter::withSize (VectorAdapter vector) noexcept
{
  _screenSize = vector;
  _inicialViewport = ViewportAdapter (vector / 2, vector);
  _dynamicViewport = ViewportAdapter (vector / 2, vector);
  return *this;
};

IWindow &
WindowAdapter::withTitle (const std::string &title) noexcept
{
  _title = title;
  return *this;
};

IWindow &
WindowAdapter::withFrame (int value) noexcept
{
  _frame = value;
  return *this;
}

IWindow &
WindowAdapter::withFrameLimit (int minFrame, int maxFrame) noexcept
{
  _minFrame = minFrame;
  _maxFrame = maxFrame;
  return *this;
}

IWindow &
WindowAdapter::withResourceManager (
    const std::shared_ptr<ResourceManager> &resourceManager) noexcept
{
  _resourceManager = resourceManager;
  return *this;
};

IWindow &
WindowAdapter::build () noexcept
{
  SetConfigFlags (FLAG_VSYNC_HINT);

  InitWindow ((int)getWindowSize ().horizontal (),
              (int)getWindowSize ().vertical (), _title.c_str ());

  InitAudioDevice ();

  setFrameLimit (_frame);

  SetExitKey (KeyboardKey::KEY_F1);

  return *this;
}

void
WindowAdapter::setDisposed (bool value) noexcept
{
  _disposed = true;
};

void
WindowAdapter::setFrameLimit (int value) noexcept
{
  _frame = std::max (std::min (value, _maxFrame), _minFrame);

  SetTargetFPS (_frame);
};

void
WindowAdapter::resize (VectorAdapter vector) noexcept
{
  _screenSize = vector;
  SetWindowSize (_screenSize.horizontal (), _screenSize.vertical ());
};

void
WindowAdapter::setViewport (const ViewportAdapter &viewport) noexcept
{
  _screenSize = viewport.size ();
  SetWindowSize (_screenSize.horizontal (), _screenSize.vertical ());
};

[[nodiscard]] bool
WindowAdapter::isOpen () const noexcept
{
  return !WindowShouldClose ();
}

bool
WindowAdapter::isDisposed () noexcept
{
  return _disposed;
}

bool
WindowAdapter::isFocused () noexcept
{
  return IsWindowFocused ();
};

[[nodiscard]] const VectorAdapter &
WindowAdapter::getWindowSize () const noexcept
{
  return _screenSize;
};

[[nodiscard]] const ViewportAdapter &
WindowAdapter::getDynamicViewport () const noexcept
{
  return _dynamicViewport;
};

[[nodiscard]] const ViewportAdapter &
WindowAdapter::getDefaultViewport () const noexcept
{
  return _inicialViewport;
};

[[nodiscard]] const ViewportAdapter &
WindowAdapter::getCurrentViewport () const noexcept
{
  return _dynamicViewport;
};

[[nodiscard]] const VectorAdapter
WindowAdapter::getCoords (const VectorAdapter &vector,
                          const ViewportAdapter &viewport) const noexcept
{
  return GetScreenToWorld2D (_screenSize, _dynamicViewport);
};

void
WindowAdapter::close () noexcept
{
  CloseWindow ();
};

void
WindowAdapter::beginDrawing () noexcept
{
  BeginDrawing ();
};

void
WindowAdapter::endDrawing () noexcept
{
  EndDrawing ();
};

void
WindowAdapter::clear () noexcept
{
  ClearBackground (toColor (_color));
};

void
WindowAdapter::dispatchEvents () noexcept
{
  int mouseX = GetMouseX ();
  int mouseY = GetMouseY ();
  float scroll = GetMouseWheelMove ();
  int currentWidth = GetScreenWidth ();
  int currentHeight = GetScreenHeight ();

  if (currentWidth != getWindowSize ().horizontal ()
      || currentHeight != getWindowSize ().vertical ())
    {
      onResized.invoke (SizeArgs (
          VectorAdapter (), VectorAdapter (currentWidth, currentHeight)));
    }

  if (auto key = GetKeyPressed (); key != 0)
    {
      auto keyPressed = (KeyboardKey)(key);

      for (auto &keyDown : constants::combinedKeys)
        if (IsKeyDown (keyDown))
          if (IsKeyPressed (keyPressed))
            onKeyPressed.invoke (KeyboardArgs (toKeyboardKey (keyPressed),
                                               toKeyboardKey (keyDown)));

      if (IsKeyPressed (keyPressed))
        onKeyPressed.invoke (KeyboardArgs (toKeyboardKey (keyPressed)));

      if (IsKeyReleased (keyPressed))
        onKeyReleased.invoke (KeyboardArgs (toKeyboardKey (keyPressed)));
    }

  onMouseMoved.invoke (
      MouseArgs (EMouse::None, VectorAdapter (mouseX, mouseY)));

  for (const MouseButton &button : magic_enum::enum_values<MouseButton> ())
    {
      if (IsMouseButtonPressed (button))
        onMouseButtonPressed.invoke (
            MouseArgs ((EMouse)button, VectorAdapter (mouseX, mouseY)));

      if (IsMouseButtonReleased (button))
        onMouseButtonReleased.invoke (
            MouseArgs ((EMouse)button, VectorAdapter (mouseX, mouseY)));
    }

  if (scroll != 0)
    {
      onMouseWheelScrolled.invoke (
          MouseArgs ((EMouse)scroll, VectorAdapter (mouseX, mouseY)));
    }
};

void
WindowAdapter::render (const IDrawable &adapter) noexcept
{
  const VectorAdapter &size = adapter.getSize ();
  const VectorAdapter &position = adapter.getPosition ();

  if (const auto *rectangleAdapter
      = dynamic_cast<const RectangleAdapter *> (&adapter))
    {

      const EColor &backgroundColor = adapter.getBackgroundColor ();

      DrawRectangle (position.horizontal (), position.vertical (),
                     size.horizontal (), size.vertical (),
                     toColor (backgroundColor));

      if (rectangleAdapter->getTexture () != ETexture::None)
        {
          const auto &texture
              = _resourceManager
                    ->load<std::unique_ptr<TextureAdapterResource> > (
                        rectangleAdapter->getTexture ());

          DrawTexture (*texture, position.horizontal (), position.vertical (),
                       WHITE);
        }
      return;
    }

  if (const auto *spriteAdapter
      = dynamic_cast<const SpriteAdapter *> (&adapter))
    {
      const auto &texture
          = _resourceManager->load<std::unique_ptr<TextureAdapterResource> > (
              spriteAdapter->getTexture ());

      DrawTexture (*texture, position.horizontal (), position.vertical (),
                   WHITE);
      return;
    }

  if (const auto *textAdapter = dynamic_cast<const TextAdapter *> (&adapter))
    {
      const EColor &textColor = textAdapter->getFontColor ();

      DrawText (textAdapter->getText ().c_str (), position.horizontal (),
                position.vertical (), textAdapter->getFontSize (),
                toColor (textColor));
    }
};
