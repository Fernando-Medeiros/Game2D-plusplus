#ifndef ADAPTER_CONTRACTS_WINDOW_H
#define ADAPTER_CONTRACTS_WINDOW_H

#include "E_color.h"
#include "event.h"
#include <string>
#include <vector_adapter.h>

namespace adapters::contracts {

class IWindow
{
public:
    core::tools::Event<int> onClosed;
    // core::tools::Event<RectAdapter> onResized;
    // core::tools::Event<KeyboardTransport> onTextEntered;
    // core::tools::Event<KeyboardTransport> onKeyPressed;
    // core::tools::Event<KeyboardTransport> onKeyReleased;
    // core::tools::Event<MouseTransport> onMouseMoved;
    // core::tools::Event<MouseTransport> onMouseButtonReleased;
    // core::tools::Event<MouseTransport> onMouseButtonPressed;
    // core::tools::Event<MouseTransport> onMouseWheelScrolled;

    virtual IWindow WithSize(const VectorAdapter<float> &vector);
    virtual IWindow WithTitle(std::string &title);
    virtual IWindow WithFramerateLimit(int &limit);
    virtual IWindow Build();

    virtual bool isOpen() const;
    virtual VectorAdapter<float> &getWindowSize() const;
    // virtual ViewportAdapter getDynamicViewport() const;
    // virtual ViewportAdapter getDefaultViewport() const;
    // virtual ViewportAdapter getCurrentViewport() const;
    // virtual VectorAdapter<float> &getCoords(const VectorAdapter<float> &vector, const ViewportAdapter &viewport) const;
    virtual void resize(const VectorAdapter<float> &vector);
    // virtual void setViewport(const ViewportAdapter<float> &viewport);

    virtual void close();
    virtual void clear(const core::enums::Color &color);
    virtual void display();
    virtual void dispatchEvents();
    // void renderSync(DrawableAdapter &drawable);
};
} // namespace adapters::contracts
#endif
