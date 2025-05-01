#include <color_adapter.hpp>
#include <keyboard_transport.hpp>
#include <magic_enum.hpp>
#include <mouse_transport.hpp>
#include <rectangle_adapter.hpp>
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
WindowAdapter::withFramerateLimit (int value) noexcept
{
  _framerateLimit = value;
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
  InitWindow ((int)getWindowSize ().horizontal (),
              (int)getWindowSize ().vertical (), _title.c_str ());

  InitAudioDevice ();

  setFrameLimit (_framerateLimit);

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
  SetTargetFPS (std::max (_framerateLimit, value));
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
WindowAdapter::display () noexcept
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
  // Check window resize
  int currentWidth = GetScreenWidth ();
  int currentHeight = GetScreenHeight ();

  if (currentWidth != getWindowSize ().horizontal ()
      || currentHeight != getWindowSize ().vertical ())
    {
      onResized.invoke (new RectAdapter (
          VectorAdapter (), VectorAdapter (currentWidth, currentHeight)));
    }

  // Check keyboard input
  for (const KeyboardKey &key : magic_enum::enum_values<KeyboardKey> ())
    {
      std::string strCode
          = static_cast<std::string> (magic_enum::enum_name (key));

      if (IsKeyPressed (key))
        onKeyPressed.invoke (KeyboardTransport (strCode));

      if (IsKeyReleased (key))
        onKeyReleased.invoke (KeyboardTransport (strCode));
    }

  // Check mouse movement
  int mouseX = GetMouseX ();
  int mouseY = GetMouseY ();

  onMouseMoved.invoke (
      MouseTransport (EMouse::None, VectorAdapter (mouseX, mouseY)));

  // Check mouse buttons
  for (const MouseButton &button : magic_enum::enum_values<MouseButton> ())
    {
      if (IsMouseButtonPressed (button))
        onMouseButtonPressed.invoke (
            MouseTransport ((EMouse)button, VectorAdapter (mouseX, mouseY)));

      if (IsMouseButtonReleased (button))
        onMouseButtonReleased.invoke (
            MouseTransport ((EMouse)button, VectorAdapter (mouseX, mouseY)));
    }

  // Check mouse wheel scroll
  float scroll = GetMouseWheelMove ();
  if (scroll != 0)
    {
      onMouseWheelScrolled.invoke (
          MouseTransport ((EMouse)scroll, VectorAdapter (mouseX, mouseY)));
    }

  BeginDrawing ();
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
