#ifndef ADAPTER_VECTOR_HPP
#define ADAPTER_VECTOR_HPP

#include "raylib.h"
#include <cstdint>
#include <format>
#include <string>

namespace adapters {

    using position_type = uint8_t;

    template<typename T>
    concept VectorType = std::integral<T> || std::floating_point<T>;

    template<VectorType T>
    class VectorAdapter
    {
    private:
	  T _vertical{ 0 }, _horizontal{ 0 };
	  position_type _row{ 0 }, _column{ 0 };

    public:
	  VectorAdapter() noexcept = default;

	  VectorAdapter(const Vector2& copy) noexcept : _horizontal{ copy.x }, _vertical{ copy.y }, _row{ 0 }, _column{ 0 } {}

	  VectorAdapter(T x, T y, position_type row = 0, position_type column = 0) noexcept : _horizontal{ x }, _vertical{ y }, _row{ row }, _column{ column } {}

	  ~VectorAdapter() noexcept = default;

	  const position_type& rowPosition() const noexcept { return _row; };

	  const position_type& columnPosition() const noexcept { return _column; };

	  const T& verticalPosition() const noexcept { return _vertical; };

	  const T& horizontalPosition() const noexcept { return _horizontal; };

	  constexpr operator Vector2() noexcept { return Vector2(_horizontal, _vertical); };

	  constexpr operator Vector2() const noexcept { return Vector2(_horizontal, _vertical); };

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

	  constexpr VectorAdapter& operator*(const T& value) noexcept
	  {
		_horizontal *= value;
		_vertical *= value;
		return *this;
	  };

	  constexpr VectorAdapter& operator+(const T& value) noexcept
	  {
		_horizontal += value;
		_vertical += value;
		return *this;
	  };

	  constexpr VectorAdapter& operator-(const T& value) noexcept
	  {
		_horizontal -= value;
		_vertical -= value;
		return *this;
	  };

	  constexpr VectorAdapter& operator/(const T& value) noexcept
	  {
		_horizontal /= value;
		_vertical /= value;
		return *this;
	  };

	  constexpr const std::string toString() const noexcept
	  {
		return std::format("VA -> H:{0} V:{1} R:{2} C:{3}", _horizontal, _vertical, _row, _column);
	  };
    };
} // namespace adapters
#endif
