#include <format>
#include <string>
#include <vector_adapter.hpp>
#include <viewport_adapter.hpp>

using namespace adapters;

ViewportAdapter::ViewportAdapter(const VectorAdapter& size, const VectorAdapter& center) noexcept
    : _zoom{ 1.0 }
    , _size{ size }
    , _center{ center }
    , _position{ center }
    , _view{ size, center, 0, 1.0 } {
}

[[nodiscard]] VectorAdapter ViewportAdapter::rect() noexcept
{
    return VectorAdapter();
}

[[nodiscard]] const VectorAdapter& ViewportAdapter::size() const noexcept
{
    return _size;
}

[[nodiscard]] const VectorAdapter& ViewportAdapter::center() const noexcept
{
    return _center;
}

[[nodiscard]] const VectorAdapter& ViewportAdapter::position() const noexcept
{
    return _position;
}

void ViewportAdapter::zoom(Zoom zoom) noexcept
{
    _zoom += zoom;
}

void ViewportAdapter::reset(VectorAdapter rect) noexcept
{
    _size = rect;
}

void ViewportAdapter::size(VectorAdapter size) noexcept
{
    _size = size;
}

void ViewportAdapter::center(VectorAdapter center) noexcept
{
    _center = center;
}

const std::string ViewportAdapter::toString() const noexcept
{
    return std::format("Viewport -> {0} {1} {2}", _position.toString(), _center.toString(), _size.toString());
};