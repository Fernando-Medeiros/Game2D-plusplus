#ifndef ADAPTER_VIEWPORT_HPP
#define ADAPTER_VIEWPORT_HPP

#include <raylib.h>
#include <string>
#include <vector_adapter.hpp>

using Zoom = float;
using View = Camera2D;

class ViewportAdapter
{
private:
    Zoom _zoom{ 1.0 };
    View _view{};
    VectorAdapter _size{};
    VectorAdapter _center{};
    VectorAdapter _position{};

public:
    ViewportAdapter() noexcept = default;
    ViewportAdapter(const VectorAdapter& size, const VectorAdapter& center) noexcept;
    ~ViewportAdapter() noexcept = default;

    [[nodiscard]] VectorAdapter& rect() noexcept;
    [[nodiscard]] const VectorAdapter& size() const noexcept;
    [[nodiscard]] const VectorAdapter& center() const noexcept;
    [[nodiscard]] const VectorAdapter& position() const noexcept;
    [[nodiscard]] const std::string toString() const noexcept;

    void zoom(Zoom scale) noexcept;
    void reset(VectorAdapter rect) noexcept;
    void size(VectorAdapter size) noexcept;
    void center(VectorAdapter center) noexcept;

    constexpr operator Camera2D() noexcept { return Camera2D{ _size, _center, 0, _zoom }; };

    constexpr operator Camera2D() const noexcept { return Camera2D{ _size, _center, 0, _zoom }; };
};
#endif // !ADAPTER_VIEWPORT_HPP
