#ifndef ADAPTER_VECTOR_HPP
#define ADAPTER_VECTOR_HPP

#include <constants_adapter.hpp>
#include <string>

class VectorAdapter
{
private:
  Position _row{ 0 }, _column{ 0 };
  Coords _vertical{ 0 }, _horizontal{ 0 };

public:
    VectorAdapter() noexcept = default;

    VectorAdapter (const ExtVector2 &copy) noexcept;

    VectorAdapter (Coords x, Coords y) noexcept;

    VectorAdapter (Coords x, Coords y, Position row, Position column) noexcept;

    ~VectorAdapter () noexcept = default;

    [[nodiscard]] const Position &rowPosition () const noexcept;

    [[nodiscard]] const Position &columnPosition () const noexcept;

    [[nodiscard]] const Coords &vertical () const noexcept;

    [[nodiscard]] const Coords &horizontal () const noexcept;

    [[nodiscard]] const std::string toString () const noexcept;

    VectorAdapter &operator+ (const VectorAdapter &right) noexcept;

    VectorAdapter &operator- (const VectorAdapter &right) noexcept;

    VectorAdapter &operator* (const VectorAdapter &right) noexcept;

    VectorAdapter &operator/ (const VectorAdapter &right) noexcept;

    VectorAdapter &operator* (const Coords &value) noexcept;

    VectorAdapter &operator+ (const Coords &value) noexcept;

    VectorAdapter &operator- (const Coords &value) noexcept;

    VectorAdapter &operator/ (const Coords &value) noexcept;

    bool operator== (const VectorAdapter &right) const noexcept;

    [[nodiscard]] operator ExtVector2 () noexcept;

    [[nodiscard]] operator ExtVector2 () const noexcept;
};
#endif
