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

  SetExitKey (ExtKeyboardKey::KEY_F1);

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
  CloseAudioDevice ();
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
  int screenWidth = GetScreenWidth ();
  int screenHeight = GetScreenHeight ();
  float scrollPosition = GetMouseWheelMove ();
  VectorAdapter mousePosition = GetMousePosition ();

  /// Evento para alterar a largura e altura da janela...
  if (screenWidth != getWindowSize ().horizontal ()
      || screenHeight != getWindowSize ().vertical ())
    {
      onResized.invoke (SizeArgs (VectorAdapter (screenWidth, screenHeight)));
    }

  /// Evento para enviar as teclas pressionadas...
  if (auto key = GetKeyPressed (); key != 0)
    {
      auto keyPressed = magic_enum::enum_cast<ExtKeyboardKey> (key).value_or (
          ExtKeyboardKey::KEY_NULL);

      for (auto &keyDown : COMBINED_KEYBOARD_KEYS)
        if (IsKeyDown (keyDown))
          if (IsKeyPressed (keyPressed))
            onKeyPressed.invoke (KeyboardArgs (toKeyboardKey (keyPressed),
                                               toKeyboardKey (keyDown)));

      if (IsKeyPressed (keyPressed))
        onKeyPressed.invoke (KeyboardArgs (toKeyboardKey (keyPressed)));

      if (IsKeyReleased (keyPressed))
        onKeyReleased.invoke (KeyboardArgs (toKeyboardKey (keyPressed)));
    }

  /// Evento para enviar a posição do mouse e o botão pressionado...
  if (mousePosition.horizontal () <= screenWidth
      && mousePosition.vertical () <= screenHeight
      && mousePosition.horizontal () >= 0 && mousePosition.vertical () >= 0)
    {
      for (auto &mouseButton : MOUSE_BUTTONS)
        {
          if (IsMouseButtonPressed (mouseButton))
            onMouseButtonPressed.invoke (
                MouseArgs (toMouseKey (mouseButton),
                           VectorAdapter (mousePosition.horizontal (),
                                          mousePosition.vertical ())));

          if (IsMouseButtonReleased (mouseButton))
            onMouseButtonReleased.invoke (
                MouseArgs (toMouseKey (mouseButton),
                           VectorAdapter (mousePosition.horizontal (),
                                          mousePosition.vertical ())));
        }

      auto mouseButton = scrollPosition == 0   ? EMouseButton::NONE
                         : scrollPosition == 1 ? EMouseButton::SCROLLUP
                                               : EMouseButton::SCROLLDOWN;

      auto sender
          = MouseArgs (mouseButton, VectorAdapter (mousePosition.horizontal (),
                                                   mousePosition.vertical ()));
      onMouseMoved.invoke (sender);

      if (mouseButton != EMouseButton::NONE)
        onMouseWheelScrolled.invoke (sender);
    }
};

void
WindowAdapter::render (const IDrawable &adapter) noexcept
{
  if (const auto *rectangle = adapter.toSecurePtr<IRectangle> ())
    {
      const EColor &fillColor = rectangle->getFillColor ();
      const VectorAdapter &size = rectangle->getSize ();
      const VectorAdapter &position = rectangle->getPosition ();

      DrawRectangle (position.horizontal (), position.vertical (),
                     size.horizontal (), size.vertical (),
                     toColor (fillColor));

      if (const auto &textureEnum = rectangle->getTexture ();
          textureEnum != ETexture::NONE)
        {
          const auto &texture
              = _resourceManager->load<ResourceManager::TextureResource> (
                  textureEnum);

          DrawTexture (*texture, position.horizontal (), position.vertical (),
                       WHITE);
        }
      return;
    }

  if (const auto *sprite = adapter.toSecurePtr<ISprite> ())
    {
      const VectorAdapter &size = sprite->getSize ();
      const VectorAdapter &position = sprite->getPosition ();

      if (const auto &textureEnum = sprite->getTexture ();
          textureEnum != ETexture::NONE)
        {
          const auto &texture
              = _resourceManager->load<ResourceManager::TextureResource> (
                  textureEnum);

          DrawTexture (*texture, position.horizontal (), position.vertical (),
                       WHITE);
        }
      return;
    }

  if (const auto *text = adapter.toSecurePtr<IText> ())
    {
      const EColor &fontColor = text->getFontColor ();
      const VectorAdapter &size = text->getSize ();
      const VectorAdapter &position = text->getPosition ();

      DrawText (text->getText ().c_str (), position.horizontal (),
                position.vertical (), text->getFontSize (),
                toColor (fontColor));
    }
};
