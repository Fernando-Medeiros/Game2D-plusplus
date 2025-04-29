#pragma once
#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <event_manager.hpp>
#include <window_adapter.hpp>

using WindowArgs = WindowAdapter;
using WindowCallbackWrapper = void (WindowArgs &);
using WindowCallback = std::function<WindowCallbackWrapper>;

class WindowManager
{
private:
  std::unique_ptr<WindowAdapter> window;
  std::shared_ptr<EventManager> eventManager;
  std::shared_ptr<ResourceManager> resourceManager;

public:
  WindowManager *
  withEventManager (const std::shared_ptr<EventManager> &ptr) noexcept;

  WindowManager *
  withResourceManager (const std::shared_ptr<ResourceManager> &ptr) noexcept;

  void initialize () noexcept;

  void dispose () noexcept;

  void events (const WindowCallback &handler) noexcept;

  void render (const WindowCallback &handler) noexcept;
};

#endif // WINDOW_MANAGER_HPP
