#include <rect_adapter.hpp>
#include <string>
#include <vector_adapter.hpp>

RectAdapter::RectAdapter(VectorAdapter position, VectorAdapter size) noexcept :
    _size{ size },
    _position{ position },
    _center{ size / 2 } {
}

[[nodiscard]] const VectorAdapter& RectAdapter::size() const noexcept { return _size; };

[[nodiscard]] const VectorAdapter& RectAdapter::center() const noexcept { return _center; };

[[nodiscard]] const VectorAdapter& RectAdapter::position() const noexcept { return _position; };

[[nodiscard]] bool RectAdapter::contains(const VectorAdapter& vector) noexcept {
    const auto x = vector.horizontal(), y = vector.vertical();

    const auto minX = _position.horizontal() - _size.horizontal();
    const auto maxX = _position.horizontal() + _size.horizontal();

    const auto minY = _position.vertical() - _size.vertical();
    const auto maxY = _position.vertical() + _size.vertical();

    return  (x >= minX && x <= maxX) && (y >= minY && y <= maxY);
};

[[nodiscard]] const std::string RectAdapter::toString() const noexcept
{
    return "RA -> P:" + _position.toString() + " S:" + _size.toString();
};
