#ifndef SIZE_ARGS_HPP
#define SIZE_ARGS_HPP

#include <event.hpp>
#include <rect_adapter.hpp>

class SizeArgs : public EventArgs
{
  RectAdapter _rect;

public:
  SizeArgs (const VectorAdapter &position, const VectorAdapter &size) noexcept
      : _rect{ position, size }
  {
  }

  ~SizeArgs () noexcept = default;

  [[nodiscard]] const RectAdapter &
  getRect () const noexcept
  {
    return _rect;
  }
};

#endif // SIZE_ARGS_HPP
