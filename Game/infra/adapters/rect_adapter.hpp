#ifndef ADAPTER_RECT_HPP
#define ADAPTER_RECT_HPP

#include <string>
#include <vector_adapter.hpp>

class RectAdapter
{
private:
    VectorAdapter _position, _size, _center;

public:
    RectAdapter() noexcept = default;
    RectAdapter(VectorAdapter position, VectorAdapter size) noexcept;
    ~RectAdapter() noexcept = default;

    [[nodiscard]] const VectorAdapter& size() const noexcept;
    [[nodiscard]] const std::string toString() const noexcept;
    [[nodiscard]] const VectorAdapter& center() const noexcept;
    [[nodiscard]] const VectorAdapter& position() const noexcept;
    [[nodiscard]] bool contains(const VectorAdapter& vector) noexcept;
};
#endif