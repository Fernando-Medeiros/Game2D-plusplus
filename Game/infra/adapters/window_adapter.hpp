#ifndef ADAPTER_WINDOW_HPP
#define ADAPTER_WINDOW_HPP

#include <I_window.hpp>

class WindowAdapter : public IWindow
{
public:
  IWindow &withSize (VectorAdapter vector) noexcept override;

  IWindow &withTitle (const std::string &title) noexcept override;

  IWindow &withFramerateLimit (int fps) noexcept override;

  IWindow &withResourceManager (const std::shared_ptr<ResourceManager>
                                    &resourceManager) noexcept override;

  IWindow &build () noexcept override;

  void setDisposed (bool value) noexcept override;

  void setFrameLimit (int value) noexcept override;

  void resize (VectorAdapter vector) noexcept override;

  void setViewport (const ViewportAdapter &viewport) noexcept override;

  [[nodiscard]] const VectorAdapter &getWindowSize () const noexcept override;

  [[nodiscard]] const ViewportAdapter &
  getDynamicViewport () const noexcept override;

  [[nodiscard]] const ViewportAdapter &
  getDefaultViewport () const noexcept override;

  [[nodiscard]] const ViewportAdapter &
  getCurrentViewport () const noexcept override;

  [[nodiscard]] const VectorAdapter
  getCoords (const VectorAdapter &vector,
             const ViewportAdapter &viewport) const noexcept override;

  [[nodiscard]] bool isOpen () const noexcept override;

  [[nodiscard]] bool isDisposed () noexcept override;

  void close () noexcept override;
  void clear () noexcept override;
  void display () noexcept override;
  void dispatchEvents () noexcept override;
  void render (const IDrawable &drawable) noexcept override;
};
#endif
