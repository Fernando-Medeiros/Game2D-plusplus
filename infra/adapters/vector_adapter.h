#ifndef ADAPTER_VECTOR_H
#define ADAPTER_VECTOR_H

#include "raylib.h"
#include <cstdint>
#include <format>
#include <string>
#include <tuple>

namespace adapters {

/// Vetor aceita tipos inteiros e com ponto flutuante.
template<typename T>
concept VectorType = std::integral<T> || std::floating_point<T>;

/// Esta classe é responsável por adaptar um vetor bidimensional 
/// de uma biblioteca externa para um vetor bidimensional do jogo.
template<VectorType T>
class VectorAdapter
{
private:
    T Y{0}, X{0};
    uint8_t R{0}, C{0};

public:
    VectorAdapter() = default;
    VectorAdapter(const Vector2 &copy);
    VectorAdapter(const VectorAdapter &copy);
    VectorAdapter(const std::tuple<T, T> &copy);
    VectorAdapter(T &x, T &y, uint8_t &row, uint8_t &column);

    ~VectorAdapter() = default;

    const uint8_t &getRowPos() const { return R; };
    const uint8_t &getColumnPos() const { return C; };

    const T &getVerticalPos() const { return Y; };
    const T &getHorizontalPos() const { return X; };

public:
    operator std::tuple<T, T>() { return {X, Y}; };

    operator Vector2 &() { return *new Vector2(X, Y); };

    VectorAdapter &operator+(const VectorAdapter &right)
    {
        X += right.X;
        Y += right.Y;
        return *this;
    };

    VectorAdapter &operator-(const VectorAdapter &right)
    {
        X -= right.X;
        Y -= right.Y;
        return *this;
    };

    VectorAdapter &operator*(const VectorAdapter &right)
    {
        X *= right.X;
        Y *= right.Y;
        return *this;
    };

    VectorAdapter &operator/(const VectorAdapter &right)
    {
        X /= right.X;
        Y /= right.Y;
        return *this;
    };

    VectorAdapter &operator+(const T &value)
    {
        X += value;
        Y += value;
        return *this;
    };

    VectorAdapter &operator-(const T &value)
    {
        X -= value;
        Y -= value;
        return *this;
    };

    VectorAdapter &operator/(const T &value)
    {
        X /= value;
        Y /= value;
        return *this;
    };

    inline const std::string toString() const
    {
        return std::format("VA -> H:{0} V:{1} R:{2} C:{3}", X, Y, R, C);
    };
};
} // namespace adapters
#endif
