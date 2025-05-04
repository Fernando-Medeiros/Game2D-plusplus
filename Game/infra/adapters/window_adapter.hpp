#ifndef ADAPTER_WINDOW_HPP
#define ADAPTER_WINDOW_HPP

#include <I_window.hpp>

class WindowAdapter : public IWindow
{
public:
  IWindow &withSize (VectorAdapter vector) noexcept override;

  IWindow &withTitle (const std::string &title) noexcept override;

  IWindow &withFrame (int fps) noexcept override;

  IWindow &withFrameLimit (int minFrame, int maxFrame) noexcept override;

  IWindow &withCameraManager (
      const std::shared_ptr<CameraManager> &ptr) noexcept override;

  IWindow &withResourceManager (
      const std::shared_ptr<ResourceManager> &ptr) noexcept override;

  IWindow &build () noexcept override;

  void setDisposed (bool value) noexcept override;

  void setFrameLimit (int value) noexcept override;

  void resize (VectorAdapter vector) noexcept override;

  [[nodiscard]] const VectorAdapter &getWindowSize () const noexcept override;

  [[nodiscard]] const ViewportAdapter &
  getDefaultViewport () const noexcept override;

  [[nodiscard]] const ViewportAdapter &
  getCurrentViewport () const noexcept override;

  [[nodiscard]] const VectorAdapter
  getCoords (const VectorAdapter &vector,
             const ViewportAdapter &viewport) const noexcept override;

  [[nodiscard]] bool isOpen () const noexcept override;

  [[nodiscard]] bool isDisposed () noexcept override;

  [[nodiscard]] bool isFocused () noexcept override;

  void close () noexcept override;

  void clear () noexcept override;

  void beginViewport () noexcept override;

  void endViewport () noexcept override;

  void beginDrawing () noexcept override;

  void endDrawing () noexcept override;

  void dispatchEvents () noexcept override;

  void render (const IDrawable &drawable) noexcept override;
};
#endif
