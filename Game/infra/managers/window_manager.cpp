#include <window_manager.hpp>

WindowManager *
WindowManager::withEventManager (
    const std::shared_ptr<EventManager> &ptr) noexcept
{
  eventManager = ptr;
  return this;
}

WindowManager *
WindowManager::withResourceManager (
    const std::shared_ptr<ResourceManager> &ptr) noexcept
{
  resourceManager = ptr;
  return this;
}

void
WindowManager::initialize () noexcept
{
  window = std::make_unique<WindowAdapter> ();
  window->resources = resourceManager;
}

void
WindowManager::dispose () noexcept
{
  window->close ();

  eventManager->dispose ();
  resourceManager->dispose ();

  eventManager.reset ();
  resourceManager.reset ();
}

void
WindowManager::events (const WindowCallback &handler) noexcept
{
  handler (*window);
}

void
WindowManager::render (const WindowCallback &handler) noexcept
{
  window->withTitle ("Game 2D")
      .withSize (VectorAdapter (500, 600))
      .withFramerateLimit (30)
      .build ();

  while (window->isOpen ())
    {
      window->clear ();
      window->dispatchEvents ();
      handler (*window);
      window->display ();
    }
}
