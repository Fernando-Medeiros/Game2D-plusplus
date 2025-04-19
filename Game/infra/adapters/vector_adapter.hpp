﻿#ifndef ADAPTER_VECTOR_HPP
#define ADAPTER_VECTOR_HPP

#include "raylib.h"
#include <cstdint>
#include <format>
#include <string>

namespace adapters {

    using Coords = float;
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

	  const Position& rowPosition() const noexcept;
	  const Position& columnPosition() const noexcept;
	  const Coords& verticalPosition() const noexcept;
	  const Coords& horizontalPosition() const noexcept;
	  const std::string toString() const noexcept;

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
		return this->horizontalPosition() == right.horizontalPosition()
		    && this->verticalPosition() == right.verticalPosition()
		    && this->rowPosition() == right.rowPosition()
		    && this->columnPosition() == right.columnPosition();
	  };

	  constexpr operator Vector2() noexcept { return Vector2(_horizontal, _vertical); };

	  constexpr operator Vector2() const noexcept { return Vector2(_horizontal, _vertical); };
    };
} // namespace adapters
#endif
