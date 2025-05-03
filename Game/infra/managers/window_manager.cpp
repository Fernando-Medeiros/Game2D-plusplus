#include <window_manager.hpp>

WindowManager &
WindowManager::withEventManager (
    const std::shared_ptr<EventManager> &ptr) noexcept
{
  _eventManager = ptr;
  return *this;
}

WindowManager &
WindowManager::withResourceManager (
    const std::shared_ptr<ResourceManager> &ptr) noexcept
{
  _resourceManager = ptr;
  return *this;
}

WindowManager &
WindowManager::withSoundManager (
    const std::shared_ptr<SoundManager> &ptr) noexcept
{
  _soundManager = ptr;
  return *this;
}

void
WindowManager::initialize () noexcept
{
  _window = std::make_unique<WindowAdapter> ();

  _window->withTitle ("Game 2D")
      .withFrame (70)
      .withFrameLimit (30, 144)
      .withSize (VectorAdapter (600, 600))
      .withResourceManager (_resourceManager)
      .build ();
}

void
WindowManager::close () noexcept
{
  _window->setDisposed (true);
}

void
WindowManager::dispose () noexcept
{
  _soundManager->dispose ();
  _eventManager->dispose ();
  _resourceManager->dispose ();
}

void
WindowManager::events (const WindowCallback &handler) noexcept
{
  handler (*_window);
}

void
WindowManager::render (const WindowCallback &handler) noexcept
{
  while (_window->isOpen ())
    {
      if (_window->isDisposed ())
        break;

      _soundManager->update ();

      _window->beginDrawing ();
      _window->clear ();

      if (_window->isFocused ())
        {
          _window->dispatchEvents ();
          handler (*_window);
        }

      _window->endDrawing ();
    }

  _window->close ();
}
