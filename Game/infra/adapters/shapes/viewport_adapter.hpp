#ifndef ADAPTER_VIEWPORT_HPP
#define ADAPTER_VIEWPORT_HPP

#include <constants_adapter.hpp>
#include <constants_core.hpp>
#include <vector_adapter.hpp>

class ViewportAdapter
{
private:
  float _zoom{ DEFAULT_ZOOM }, _rotation{ 0.0f };
  VectorAdapter _target{ DEFAULT_SCREEN_WIDTH / 2, DEFAULT_SCREEN_HEIGHT / 2 },
      _center{ DEFAULT_SCREEN_WIDTH / 2, DEFAULT_SCREEN_HEIGHT / 2 },
      _size{ DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT };

public:
  ViewportAdapter () noexcept = default;

  ViewportAdapter (const VectorAdapter &size,
                   const VectorAdapter &target) noexcept;

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

  operator const ExtViewport () const noexcept;
};
#endif // !ADAPTER_VIEWPORT_HPP
