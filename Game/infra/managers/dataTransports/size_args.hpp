#ifndef SIZE_ARGS_HPP
#define SIZE_ARGS_HPP

#include <event.hpp>
#include <vector_adapter.hpp>

class SizeArgs : public IEventArgs
{
  VectorAdapter _size, _position;

public:
  SizeArgs (const VectorAdapter &size) noexcept : _size{ size } {}

  SizeArgs (const VectorAdapter &size, const VectorAdapter &position) noexcept
      : _size{ size },
        _position{ position }
  {
  }

  ~SizeArgs () noexcept = default;

  [[nodiscard]] VectorAdapter
  getSize () const noexcept
  {
    return _size;
  }

  [[nodiscard]] VectorAdapter
  getPosition () const noexcept
  {
    return _position;
  }
};

#endif // SIZE_ARGS_HPP
