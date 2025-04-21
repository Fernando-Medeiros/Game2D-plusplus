#ifndef ADAPTER_CONTRACTS_WINDOW_HPP
#define ADAPTER_CONTRACTS_WINDOW_HPP

#include "I_drawable.hpp"
#include <E_color.hpp>
#include <event.hpp>
#include <memory>
#include <string>
#include <vector_adapter.hpp>
#include <viewport_adapter.hpp>

class IWindow
{
protected:
    std::string _title{""};
    int _framerateLimit{30};
    EColor color{EColor::Black};
    VectorAdapter _screenSize;
    ViewportAdapter _inicialViewport;
    ViewportAdapter _dynamicViewport;

public:
    std::unique_ptr<Event> onClosed;
    std::unique_ptr<Event> onResized;
    std::unique_ptr<Event> onTextEntered;
    std::unique_ptr<Event> onKeyPressed;
    std::unique_ptr<Event> onKeyReleased;
    std::unique_ptr<Event> onMouseMoved;
    std::unique_ptr<Event> onMouseButtonReleased;
    std::unique_ptr<Event> onMouseButtonPressed;
    std::unique_ptr<Event> onMouseWheelScrolled;

    IWindow() noexcept = default;

    virtual ~IWindow() noexcept = default;

    virtual IWindow &withSize(VectorAdapter vector) noexcept = 0;
    virtual IWindow &withTitle(std::string title) noexcept = 0;
    virtual IWindow &withFramerateLimit(int value) noexcept = 0;
    virtual IWindow &build() noexcept = 0;

    virtual void setFrameLimit(int value) noexcept = 0;
    virtual void resize(VectorAdapter vector) noexcept = 0;
    virtual void setViewport(const ViewportAdapter &viewport) noexcept = 0;

    [[nodiscard]] virtual bool isOpen() const noexcept = 0;
    [[nodiscard]] virtual const VectorAdapter &getWindowSize() const noexcept = 0;
    [[nodiscard]] virtual const ViewportAdapter &getDynamicViewport() const noexcept = 0;
    [[nodiscard]] virtual const ViewportAdapter &getDefaultViewport() const noexcept = 0;
    [[nodiscard]] virtual const ViewportAdapter &getCurrentViewport() const noexcept = 0;
    [[nodiscard]] virtual const VectorAdapter getCoords(
        const VectorAdapter &vector, const ViewportAdapter &viewport) const noexcept
        = 0;

    virtual void close() noexcept = 0;
    virtual void clear() noexcept = 0;
    virtual void display() noexcept = 0;
    virtual void dispatchEvents() noexcept = 0;
    virtual void renderSync(IDrawable &drawable) noexcept = 0;
};
#endif
