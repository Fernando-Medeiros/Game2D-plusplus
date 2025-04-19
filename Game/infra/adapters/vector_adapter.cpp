#include <vector_adapter.hpp>

namespace adapters {

    VectorAdapter::VectorAdapter(const Vector2& copy) noexcept :
	  _row{ 0 },
	  _column{ 0 },
	  _vertical{ static_cast<Coords>(copy.y) },
	  _horizontal{ static_cast<Coords>(copy.x) } {
    }

    VectorAdapter::VectorAdapter(Coords x, Coords y) noexcept
	  : _horizontal{ x }, _vertical{ y }, _row{ 0 }, _column{ 0 } {
    }

    VectorAdapter::VectorAdapter(Coords x, Coords y, Position row, Position column) noexcept
	  : _horizontal{ x }, _vertical{ y }, _row{ row }, _column{ column } {
    }

    [[nodiscard]] const Position& VectorAdapter::rowPosition() const noexcept { return _row; };

    [[nodiscard]] const Position& VectorAdapter::columnPosition() const noexcept { return _column; };

    [[nodiscard]] const Coords& VectorAdapter::verticalPosition() const noexcept { return _vertical; };

    [[nodiscard]] const Coords& VectorAdapter::horizontalPosition() const noexcept { return _horizontal; };

    [[nodiscard]] const std::string VectorAdapter::toString() const noexcept
    {
	  return std::format("VA -> H:{0} V:{1} R:{2} C:{3}", _horizontal, _vertical, _row, _column);
    };
}