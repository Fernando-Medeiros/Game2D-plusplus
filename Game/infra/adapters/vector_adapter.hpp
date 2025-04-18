#ifndef ADAPTER_VECTOR_HPP
#define ADAPTER_VECTOR_HPP

#include "raylib.h"
#include <cstdint>
#include <format>
#include <string>

namespace adapters {

    using String = std::string;
    using PositionType = uint8_t;

    template<typename T>
    concept VectorType = std::integral<T> || std::floating_point<T>;

    template<VectorType T>
    class VectorAdapter
    {
    private:
	  T Y{ 0 }, X{ 0 };
	  PositionType R{ 0 }, C{ 0 };

    public:
	  VectorAdapter() noexcept = default;

	  VectorAdapter(const Vector2& copy) noexcept;

	  VectorAdapter(const T& x,
		const T& y,
		const PositionType& row,
		const PositionType& column) noexcept;

	  ~VectorAdapter() noexcept = default;

	  const PositionType& getRowPos() const noexcept { return R; };

	  const PositionType& getColumnPos() const noexcept { return C; };

	  const T& getVerticalPos() const noexcept { return Y; };

	  const T& getHorizontalPos() const noexcept { return X; };

	  constexpr operator Vector2() noexcept { return Vector2(X, Y); };

	  constexpr operator Vector2() const noexcept { return Vector2(X, Y); };

	  constexpr VectorAdapter& operator+(const VectorAdapter& right) noexcept
	  {
		X += right.X;
		Y += right.Y;
		return *this;
	  };

	  constexpr VectorAdapter& operator-(const VectorAdapter& right) noexcept
	  {
		X -= right.X;
		Y -= right.Y;
		return *this;
	  };

	  constexpr VectorAdapter& operator*(const VectorAdapter& right) noexcept
	  {
		X *= right.X;
		Y *= right.Y;
		return *this;
	  };

	  constexpr VectorAdapter& operator/(const VectorAdapter& right) noexcept
	  {
		X /= right.X;
		Y /= right.Y;
		return *this;
	  };

	  constexpr VectorAdapter& operator*(const T& value) noexcept
	  {
		X *= value;
		Y *= value;
		return *this;
	  };

	  constexpr VectorAdapter& operator+(const T& value) noexcept
	  {
		X += value;
		Y += value;
		return *this;
	  };

	  constexpr VectorAdapter& operator-(const T& value) noexcept
	  {
		X -= value;
		Y -= value;
		return *this;
	  };

	  constexpr VectorAdapter& operator/(const T& value) noexcept
	  {
		X /= value;
		Y /= value;
		return *this;
	  };

	  constexpr const String toString() const noexcept
	  {
		return std::format("VA -> H:{0} V:{1} R:{2} C:{3}", X, Y, R, C);
	  };
    };
} // namespace adapters
#endif
