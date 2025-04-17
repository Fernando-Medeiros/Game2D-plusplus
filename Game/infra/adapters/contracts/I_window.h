#ifndef ADAPTER_CONTRACTS_WINDOW_H
#define ADAPTER_CONTRACTS_WINDOW_H

#include <E_color.h>
#include <event.h>
#include <string>
#include <vector_adapter.h>
#include <viewport_adapter.h>

namespace adapters::contracts {

using String = std::string;
using Event = core::tools::Event;
using Color = const core::enums::Color &;
using Vector = const VectorAdapter<float> &;
using Viewport = const ViewportAdapter &;

class IWindow
{
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

    explicit constexpr IWindow() noexcept = default;
    virtual constexpr ~IWindow() noexcept = default;

    virtual IWindow &WithSize(Vector vector) noexcept;
    virtual IWindow &WithTitle(String &title) noexcept;
    virtual IWindow &WithFramerateLimit(int &limit) noexcept;
    virtual IWindow &Build() noexcept;

    constexpr virtual bool isOpen() const noexcept;
    constexpr virtual void resize(Vector vector) noexcept;
    constexpr virtual void setViewport(Viewport viewport) noexcept;
    constexpr virtual Vector getWindowSize() const noexcept;
    constexpr virtual Viewport getDynamicViewport() const noexcept;
    constexpr virtual Viewport getDefaultViewport() const noexcept;
    constexpr virtual Viewport getCurrentViewport() const noexcept;
    constexpr virtual Vector getCoords(Vector vector, Viewport viewport) const noexcept;

    virtual void close() noexcept;
    virtual void clear(Color color) noexcept;
    virtual void display() noexcept;
    virtual void dispatchEvents() noexcept;
    // virtual void renderSync(DrawableAdapter &drawable) noexcept;
};
} // namespace adapters::contracts
#endif
