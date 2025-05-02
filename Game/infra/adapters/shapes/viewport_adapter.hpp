#ifndef ADAPTER_VIEWPORT_HPP
#define ADAPTER_VIEWPORT_HPP

#include <constants_adapter.hpp>
#include <string>
#include <vector_adapter.hpp>

class ViewportAdapter
{
private:
  Zoom _zoom{ 1.0f };
  VectorAdapter _size, _center, _position;

public:
  ViewportAdapter () noexcept = default;

  ViewportAdapter (const VectorAdapter &size,
                   const VectorAdapter &center) noexcept;

  ~ViewportAdapter () noexcept = default;

  [[nodiscard]] const VectorAdapter &size () const noexcept;

  [[nodiscard]] const VectorAdapter &center () const noexcept;

  [[nodiscard]] const VectorAdapter &position () const noexcept;

  [[nodiscard]] const std::string toString () const noexcept;

  void zoom (Zoom scale) noexcept;

  void size (VectorAdapter size) noexcept;

  void center (VectorAdapter center) noexcept;

  operator const ExtViewport () const noexcept
  {
    const ExtViewport camera{ _size, _center, 0, _zoom };
    return camera;
  };
};
#endif // !ADAPTER_VIEWPORT_HPP
