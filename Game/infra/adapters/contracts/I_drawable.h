#ifndef ADAPTER_CONTRACTS_DRAWABLE_H
#define ADAPTER_CONTRACTS_DRAWABLE_H

#include <E_color.h>
#include <any>
#include <vector_adapter.h>

namespace adapters::contracts {

using Color = const core::enums::Color &;
using Vector = const VectorAdapter<float> &;

class IDrawable
{
public:
    explicit constexpr IDrawable() noexcept = default;
    virtual constexpr ~IDrawable() noexcept = default;

    virtual std::any getDrawable() noexcept;

    virtual IDrawable &setBackgroundColor(Color color) noexcept;
    virtual IDrawable &setBorderColor(Color color) noexcept;
    virtual IDrawable &setBorderSize(Vector vector) noexcept;
    virtual IDrawable &setSize(Vector vector) noexcept;
    virtual IDrawable &setPosition(Vector vector) noexcept;
    virtual IDrawable &setScale(Vector vector) noexcept;
    virtual IDrawable &setRotation(float &rotation) noexcept;

    virtual Color &getBackgroundColor() const noexcept;
    virtual Color &getBorderColor() const noexcept;
    // virtual RectAdapter getBounds() const;
    virtual Vector getBorderSize() const noexcept;
    virtual Vector getSize() const noexcept;
    virtual Vector getPosition() const noexcept;
    virtual Vector getScale() const noexcept;
    virtual float getRotation() const noexcept;
};
} // namespace adapters::contracts
#endif
