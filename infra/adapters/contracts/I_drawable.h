#ifndef ADAPTER_CONTRACTS_DRAWABLE_H
#define ADAPTER_CONTRACTS_DRAWABLE_H

#include "E_color.h"
#include "vector_adapter.h"

namespace adapters::contracts {

class IDrawable
{
public:
    virtual ~IDrawable() = default;

    virtual int getDrawable();

    virtual IDrawable &setBackgroundColor(const core::enums::Color &color);
    virtual IDrawable &setBorderColor(const core::enums::Color &color);
    virtual IDrawable &setBorderSize(const VectorAdapter<float> &vector);
    virtual IDrawable &setSize(const VectorAdapter<float> &vector);
    virtual IDrawable &setPosition(const VectorAdapter<float> &vector);
    virtual IDrawable &setScale(const VectorAdapter<float> &vector);
    virtual IDrawable &setRotation(float &rotation);

    virtual const core::enums::Color &getBackgroundColor() const;
    virtual const core::enums::Color &getBorderColor() const;
    // virtual RectAdapter getBounds() const;
    virtual VectorAdapter<float> &getBorderSize() const;
    virtual VectorAdapter<float> &getSize() const;
    virtual VectorAdapter<float> &getPosition() const;
    virtual VectorAdapter<float> &getScale() const;
    virtual float getRotation() const;
};
} // namespace adapters::contracts
#endif
