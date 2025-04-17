#include <viewport_adapter.h>

using namespace adapters;

ViewportAdapter::ViewportAdapter() noexcept
    : _zoom(1.0)
    , _size()
    , _center()
    , _position()
    , _view()
{}

ViewportAdapter::ViewportAdapter(const Vector &center, const Vector &size) noexcept
    : _zoom(1.0)
    , _size(size)
    , _center(center)
    , _position(center)
    , _view(size, center, 0, 1.0)
{}

Rect ViewportAdapter::getRect() noexcept
{
    return Rect();
}

const Vector &ViewportAdapter::getSize() const noexcept
{
    return _size;
}

const Vector &ViewportAdapter::getCenter() const noexcept
{
    return _center;
}

const Vector &ViewportAdapter::getPosition() const noexcept
{
    return _position;
}

void ViewportAdapter::setZoom(const ZoomType &zoom) noexcept
{
    _zoom += zoom;
}

void ViewportAdapter::setSize(const Vector &size) noexcept
{
    _size = size;
}

void ViewportAdapter::setCenter(const Vector &center) noexcept
{
    _center = center;
}
