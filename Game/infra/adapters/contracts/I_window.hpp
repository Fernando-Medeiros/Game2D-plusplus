#ifndef ADAPTER_CONTRACTS_WINDOW_HPP
#define ADAPTER_CONTRACTS_WINDOW_HPP

#include <E_color.hpp>
#include <I_drawable.hpp>
#include <camera_manager.hpp>
#include <event.hpp>
#include <memory>
#include <resource_manager.hpp>
#include <string>
#include <vector_adapter.hpp>
#include <viewport_adapter.hpp>

class IWindow
{
protected:
  std::shared_ptr<CameraManager> _cameraManager;
  std::shared_ptr<ResourceManager> _resourceManager;
  ViewportAdapter _inicialViewport;
  VectorAdapter _screenSize;
  EColor _color{ EColor::Gray };
  ETexture _favicon{ ETexture::NONE };
  std::string _title;
  int _maxFrame, _minFrame, _frame;
  bool _disposed;

public:
  Event onClosed;
  Event onResized;
  Event onMouseMoved;
  Event onKeyPressed;
  Event onKeyReleased;
  Event onTextEntered;
  Event onMouseWheelScrolled;
  Event onMouseButtonPressed;
  Event onMouseButtonReleased;

  IWindow () noexcept = default;

  virtual ~IWindow () noexcept = default;

  virtual IWindow &withSize (VectorAdapter vector) noexcept = 0;

  virtual IWindow &withTitle (const std::string &title) noexcept = 0;

  virtual IWindow &withFrameLimit (int minFrame, int maxFrame) noexcept = 0;

  virtual IWindow &withFrame (int value) noexcept = 0;

  virtual IWindow &
  withCameraManager (const std::shared_ptr<CameraManager> &ptr) noexcept
      = 0;

  virtual IWindow &
  withResourceManager (const std::shared_ptr<ResourceManager> &ptr) noexcept
      = 0;

  virtual IWindow &build () noexcept = 0;

  virtual void setDisposed (bool value) noexcept = 0;

  virtual void setFrameLimit (int value) noexcept = 0;

  virtual void resize (VectorAdapter vector) noexcept = 0;

  [[nodiscard]] virtual const VectorAdapter &getWindowSize () const noexcept
      = 0;

  [[nodiscard]] virtual const ViewportAdapter &
  getDefaultViewport () const noexcept
      = 0;

  [[nodiscard]] virtual const ViewportAdapter &
  getCurrentViewport () const noexcept
      = 0;

  [[nodiscard]] virtual const VectorAdapter
  getCoords (const VectorAdapter &vector,
             const ViewportAdapter &viewport) const noexcept
      = 0;

  [[nodiscard]] virtual bool isOpen () const noexcept = 0;

  [[nodiscard]] virtual bool isDisposed () noexcept = 0;

  [[nodiscard]] virtual bool isFocused () noexcept = 0;

  virtual void close () noexcept = 0;

  virtual void clear () noexcept = 0;

  virtual void beginViewport () noexcept = 0;

  virtual void endViewport () noexcept = 0;

  virtual void beginDrawing () noexcept = 0;

  virtual void endDrawing () noexcept = 0;

  virtual void dispatchEvents () noexcept = 0;

  virtual void render (const IDrawable &drawable) noexcept = 0;
};
#endif
