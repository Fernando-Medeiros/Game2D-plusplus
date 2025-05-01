#include <window_manager.hpp>

WindowManager &
WindowManager::withEventManager (
    const std::shared_ptr<EventManager> &ptr) noexcept
{
  eventManager = ptr;
  return *this;
}

WindowManager &
WindowManager::withResourceManager (
    const std::shared_ptr<ResourceManager> &ptr) noexcept
{
  resourceManager = ptr;
  return *this;
}

void
WindowManager::initialize () noexcept
{
  window = std::make_unique<WindowAdapter> ();

  window->withTitle ("Game 2D")
      .withSize (VectorAdapter (800, 800))
      .withFramerateLimit (30)
      .withResourceManager (resourceManager)
      .build ();
}

void
WindowManager::close () noexcept
{
  window->setDisposed (true);
}

void
WindowManager::dispose () noexcept
{
  eventManager->dispose ();
  resourceManager->dispose ();
}

void
WindowManager::events (const WindowCallback &handler) noexcept
{
  handler (*window);
}

void
WindowManager::render (const WindowCallback &handler) noexcept
{
  while (window->isOpen ())
    {
      window->clear ();
      window->dispatchEvents ();
      handler (*window);
      window->display ();

      if (window->isDisposed ())
        break;
    }

  window->close ();
}
