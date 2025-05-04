#ifndef CAMERA_ARGS_HPP
#define CAMERA_ARGS_HPP

#include <event.hpp>
#include <vector_adapter.hpp>

class CameraArgs : public IEventArgs
{
private:
  VectorAdapter _target;

public:
  CameraArgs (const VectorAdapter &target) noexcept : _target{ target } {}

  ~CameraArgs () noexcept = default;

  [[nodiscard]] const VectorAdapter &
  getTarget () const noexcept
  {
    return _target;
  }
};

#endif // CAMERA_ARGS_HPP
