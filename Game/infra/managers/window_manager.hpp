#pragma once
#ifndef WINDOW_MANAGER_HPP
#define WINDOW_MANAGER_HPP

#include <camera_manager.hpp>
#include <event_manager.hpp>
#include <router_manager.hpp>
#include <sound_manager.hpp>
#include <window_adapter.hpp>

using WindowArgs = WindowAdapter;
using WindowCallbackWrapper = void (WindowArgs &);
using WindowCallback = std::function<WindowCallbackWrapper>;

class WindowManager
{
private:
  std::unique_ptr<WindowAdapter> _window;
  std::shared_ptr<EventManager> _eventManager;
  std::shared_ptr<SoundManager> _soundManager;
  std::shared_ptr<RouterManager> _routerManager;
  std::shared_ptr<CameraManager> _cameraManager;
  std::shared_ptr<ResourceManager> _resourceManager;

public:
  WindowManager &
  withEventManager (const std::shared_ptr<EventManager> &ptr) noexcept;

  WindowManager &
  withSoundManager (const std::shared_ptr<SoundManager> &ptr) noexcept;

  WindowManager &
  withRouterManager (const std::shared_ptr<RouterManager> &ptr) noexcept;

  WindowManager &
  withCameraManager (const std::shared_ptr<CameraManager> &ptr) noexcept;

  WindowManager &
  withResourceManager (const std::shared_ptr<ResourceManager> &ptr) noexcept;

  void initialize () noexcept;

  void close () noexcept;

  void dispose () noexcept;

  void events (const WindowCallback &handler) noexcept;

  void render (const WindowCallback &handler) noexcept;
};

#endif // WINDOW_MANAGER_HPP
