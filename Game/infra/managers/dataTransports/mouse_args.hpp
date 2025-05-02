#ifndef MOUSE_ARGS_H
#define MOUSE_ARGS_H

#include <E_mouse.hpp>
#include <event.hpp>
#include <vector_adapter.hpp>

struct MouseArgs : public IEventArgs
{
private:
  EMouseButton _pressedButton;
  VectorAdapter _position;

public:
  MouseArgs (const EMouseButton &button, const VectorAdapter &position) noexcept
      : _position{ position },
        _pressedButton{ button } {};

  ~MouseArgs () noexcept = default;

  [[nodiscard]] const VectorAdapter &
  getPosition () const noexcept
  {
    return _position;
  };

  [[nodiscard]] const EMouseButton &
  getPressed () const noexcept
  {
    return _pressedButton;
  };
};
#endif // MOUSE_ARGS_H
