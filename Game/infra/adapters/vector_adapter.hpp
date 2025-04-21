#ifndef ADAPTER_VECTOR_HPP
#define ADAPTER_VECTOR_HPP

#include "raylib.h"
#include <cstdint>
#include <string>

using Coords = uint16_t;
using Position = uint8_t;

class VectorAdapter
{
private:
    Position _row{ 0 }, _column{ 0 };
    Coords _vertical{ 0 }, _horizontal{ 0 };

public:
    VectorAdapter() noexcept = default;
    VectorAdapter(const Vector2& copy) noexcept;
    VectorAdapter(Coords x, Coords y) noexcept;
    VectorAdapter(Coords x, Coords y, Position row, Position column) noexcept;
    ~VectorAdapter() noexcept = default;

    [[nodiscard]] const Position& rowPosition() const noexcept;
    [[nodiscard]] const Position& columnPosition() const noexcept;
    [[nodiscard]] const Coords& vertical() const noexcept;
    [[nodiscard]] const Coords& horizontal() const noexcept;
    [[nodiscard]] const std::string toString() const noexcept;

    constexpr VectorAdapter& operator+(const VectorAdapter& right) noexcept
    {
	  _horizontal += right._horizontal;
	  _vertical += right._vertical;
	  return *this;
    };

    constexpr VectorAdapter& operator-(const VectorAdapter& right) noexcept
    {
	  _horizontal -= right._horizontal;
	  _vertical -= right._vertical;
	  return *this;
    };

    constexpr VectorAdapter& operator*(const VectorAdapter& right) noexcept
    {
	  _horizontal *= right._horizontal;
	  _vertical *= right._vertical;
	  return *this;
    };

    constexpr VectorAdapter& operator/(const VectorAdapter& right) noexcept
    {
	  _horizontal /= right._horizontal;
	  _vertical /= right._vertical;
	  return *this;
    };

    constexpr VectorAdapter& operator*(const Coords& value) noexcept
    {
	  _horizontal *= value;
	  _vertical *= value;
	  return *this;
    };

    constexpr VectorAdapter& operator+(const Coords& value) noexcept
    {
	  _horizontal += value;
	  _vertical += value;
	  return *this;
    };

    constexpr VectorAdapter& operator-(const Coords& value) noexcept
    {
	  _horizontal -= value;
	  _vertical -= value;
	  return *this;
    };

    constexpr VectorAdapter& operator/(const Coords& value) noexcept
    {
	  _horizontal /= value;
	  _vertical /= value;
	  return *this;
    };

    bool operator==(const VectorAdapter& right) const noexcept
    {
	  return this->horizontal() == right.horizontal()
		&& this->vertical() == right.vertical()
		&& this->rowPosition() == right.rowPosition()
		&& this->columnPosition() == right.columnPosition();
    };

    [[nodiscard]] constexpr operator Vector2() noexcept {
	  Vector2 vector{};
	  vector.y = _vertical;
	  vector.x = _horizontal;
	  return vector;
    };

    [[nodiscard]] constexpr operator Vector2() const noexcept {
	  Vector2 vector{};
	  vector.y = _vertical;
	  vector.x = _horizontal;
	  return vector;
    };
};
#endif
