#include <vector_adapter.hpp>
#include <viewport_adapter.hpp>

ViewportAdapter::ViewportAdapter (const VectorAdapter &size,
                                  const VectorAdapter &target,
                                  const VectorAdapter &center) noexcept
    : _zoom{ 1.0 },
      _size{ size },
      _target{ target },
      _center{ center }
{
}

const float &
ViewportAdapter::getZoom () const noexcept
{
  return _zoom;
}

const float &
ViewportAdapter::getRotation () const noexcept
{
  return _rotation;
}

const VectorAdapter &
ViewportAdapter::getSize () const noexcept
{
  return _size;
}

[[nodiscard]] const VectorAdapter &
ViewportAdapter::getTarget () const noexcept
{
  return _target;
}

[[nodiscard]] const VectorAdapter &
ViewportAdapter::getCenter () const noexcept
{
  return _center;
}

void
ViewportAdapter::setZoom (float value) noexcept
{
  _zoom += value;
}

void
ViewportAdapter::setRotation (float value) noexcept
{
  _rotation = value;
}

void
ViewportAdapter::setSize (VectorAdapter vector) noexcept
{
  _size = vector;
}

void
ViewportAdapter::setTarget (VectorAdapter vector) noexcept
{
  _target = vector;
}

void
ViewportAdapter::setCenter (VectorAdapter vector) noexcept
{
  _center = vector;
}

ViewportAdapter::operator const ExtViewport () const noexcept
{
  const ExtViewport camera{ _center, _target, _rotation, _zoom };
  return camera;
};
