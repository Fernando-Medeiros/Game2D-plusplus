#ifndef CAMERA_MANAGER_HPP
#define CAMERA_MANAGER_HPP

#include <event.hpp>
#include <viewport_adapter.hpp>

class CameraManager
{
private:
  ViewportAdapter _viewport;

public:
  CameraManager () noexcept = default;

  [[nodiscard]] const ViewportAdapter &getViewport () const noexcept;

  void execute (const IEventArgs &sender) noexcept;

  void dispose () noexcept;
};

#endif // CAMERA_MANAGER_HPP
