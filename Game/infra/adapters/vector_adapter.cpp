#include <vector_adapter.hpp>

using namespace adapters;

VectorAdapter::VectorAdapter(const Vector2& copy) noexcept
    : _horizontal{ copy.x }, _vertical{ copy.y }, _row{ 0 }, _column{ 0 } {
}

VectorAdapter::VectorAdapter(Coords x, Coords y) noexcept
    : _horizontal{ x }, _vertical{ y }, _row{ 0 }, _column{ 0 } {
}

VectorAdapter::VectorAdapter(Coords x, Coords y, Position row, Position column) noexcept
    : _horizontal{ x }, _vertical{ y }, _row{ row }, _column{ column } {
}

const Position& VectorAdapter::rowPosition() const noexcept { return _row; };

const Position& VectorAdapter::columnPosition() const noexcept { return _column; };

const Coords& VectorAdapter::verticalPosition() const noexcept { return _vertical; };

const Coords& VectorAdapter::horizontalPosition() const noexcept { return _horizontal; };

const std::string VectorAdapter::toString() const noexcept
{
    return std::format("VA -> H:{0} V:{1} R:{2} C:{3}", _horizontal, _vertical, _row, _column);
};