#ifndef ADAPTER_VIEWPORT_H
#define ADAPTER_VIEWPORT_H

#include <vector_adapter.h>

namespace adapters {

using View = Camera2D;
using ZoomType = float;
using String = std::string;
using Rect = VectorAdapter<float>;
using Vector = VectorAdapter<float>;

/// Estrutura responsável por adaptar a janela de renderização de uma biblioteca externa para a janela do jogo.
class ViewportAdapter
{
private:
    View _view;
    Vector _size;
    Vector _center;
    Vector _position;
    ZoomType _zoom{1.0};

public:
    ViewportAdapter() noexcept;
    ViewportAdapter(const Vector &center, const Vector &size) noexcept;

    ~ViewportAdapter() noexcept = default;

    [[nodiscard]] Rect getRect() noexcept;
    [[nodiscard]] const Vector &getSize() const noexcept;
    [[nodiscard]] const Vector &getCenter() const noexcept;
    [[nodiscard]] const Vector &getPosition() const noexcept;

    void reset(Rect rect) noexcept;
    void setZoom(const ZoomType &scale) noexcept;
    void setSize(const Vector &size) noexcept;
    void setCenter(const Vector &center) noexcept;

    constexpr operator Camera2D() noexcept { return Camera2D(_size, _center, 0, _zoom); };

    constexpr operator Camera2D() const noexcept { return Camera2D(_size, _center, 0, _zoom); };

    constexpr const String toString() const noexcept
    {
        return std::format("Viewport -> {0} {1} {2}",
                           _position.toString(),
                           _center.toString(),
                           _size.toString());
    };
};
} // namespace adapters
#endif // !ADAPTER_VIEWPORT_H
