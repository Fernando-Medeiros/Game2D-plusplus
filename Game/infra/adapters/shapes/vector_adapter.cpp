#include <format>
#include <vector_adapter.hpp>

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

[[nodiscard]] const Coords& VectorAdapter::vertical() const noexcept { return _vertical; };

[[nodiscard]] const Coords& VectorAdapter::horizontal() const noexcept { return _horizontal; };

[[nodiscard]] const std::string VectorAdapter::toString() const noexcept
{
    return std::format("VA -> H:{0} V:{1} R:{2} C:{3}", _horizontal, _vertical, _row, _column);
};

VectorAdapter &
VectorAdapter::operator+ (const VectorAdapter &right) noexcept
{
  _horizontal += right._horizontal;
  _vertical += right._vertical;
  return *this;
};

VectorAdapter &
VectorAdapter::operator- (const VectorAdapter &right) noexcept
{
  _horizontal -= right._horizontal;
  _vertical -= right._vertical;
  return *this;
};

VectorAdapter &
VectorAdapter::operator* (const VectorAdapter &right) noexcept
{
  _horizontal *= right._horizontal;
  _vertical *= right._vertical;
  return *this;
};

VectorAdapter &
VectorAdapter::operator/ (const VectorAdapter &right) noexcept
{
  _horizontal /= right._horizontal;
  _vertical /= right._vertical;
  return *this;
};

VectorAdapter &
VectorAdapter::operator* (const Coords &value) noexcept
{
  _horizontal *= value;
  _vertical *= value;
  return *this;
};

VectorAdapter &
VectorAdapter::operator+ (const Coords &value) noexcept
{
  _horizontal += value;
  _vertical += value;
  return *this;
};

VectorAdapter &
VectorAdapter::operator- (const Coords &value) noexcept
{
  _horizontal -= value;
  _vertical -= value;
  return *this;
};

VectorAdapter &
VectorAdapter::operator/ (const Coords &value) noexcept
{
  _horizontal /= value;
  _vertical /= value;
  return *this;
};

bool
VectorAdapter::operator== (const VectorAdapter &right) const noexcept
{
  return this->horizontal () == right.horizontal ()
         && this->vertical () == right.vertical ()
         && this->rowPosition () == right.rowPosition ()
         && this->columnPosition () == right.columnPosition ();
};

[[nodiscard]] VectorAdapter::operator ExtVector2 () noexcept
{
  ExtVector2 vector{};
  vector.y = _vertical;
  vector.x = _horizontal;
  return vector;
};

[[nodiscard]] VectorAdapter::operator ExtVector2 () const noexcept
{
  ExtVector2 vector{};
  vector.y = _vertical;
  vector.x = _horizontal;
  return vector;
};
