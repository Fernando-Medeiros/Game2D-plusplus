#ifndef ADAPTER_VIEWPORT_HPP
#define ADAPTER_VIEWPORT_HPP

#include <constants_adapter.hpp>
#include <vector_adapter.hpp>

class ViewportAdapter
{
private:
  float _zoom{ 1.0f }, _rotation{ 0.0f };
  VectorAdapter _target, _center, _size;

public:
  ViewportAdapter () noexcept = default;

  ViewportAdapter (const VectorAdapter &size, const VectorAdapter &target,
                   const VectorAdapter &center) noexcept;

  ~ViewportAdapter () noexcept = default;

  [[nodiscard]] const float &getZoom () const noexcept;

  [[nodiscard]] const float &getRotation () const noexcept;

  [[nodiscard]] const VectorAdapter &getSize () const noexcept;

  [[nodiscard]] const VectorAdapter &getTarget () const noexcept;

  [[nodiscard]] const VectorAdapter &getCenter () const noexcept;

  void setZoom (float value) noexcept;

  void setRotation (float value) noexcept;

  void setSize (VectorAdapter vector) noexcept;

  void setTarget (VectorAdapter vector) noexcept;

  void setCenter (VectorAdapter vector) noexcept;

  operator const ExtViewport () const noexcept;
};
#endif // !ADAPTER_VIEWPORT_HPP
