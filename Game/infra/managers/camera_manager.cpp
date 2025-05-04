#include <algorithm>
#include <camera_args.hpp>
#include <camera_manager.hpp>
#include <constants_core.hpp>
#include <keyboard_args.hpp>
#include <mouse_args.hpp>
#include <size_args.hpp>

const ViewportAdapter &
CameraManager::getViewport () const noexcept
{
  return _viewport;
}

void
CameraManager::execute (const IEventArgs &sender) noexcept
{
  if (const auto *args = sender.toSecurePtr<SizeArgs> ())
    {
      const auto size = args->getSize ();

      _viewport.setSize (size);
      _viewport.setTarget (size / 2);
      _viewport.setZoom (DEFAULT_ZOOM);
      return;
    }

  if (const auto *args = sender.toSecurePtr<CameraArgs> ())
    {
      const auto target = args->getTarget ();
      const auto size = _viewport.getSize ();

      int baseY = size.vertical () / 2;
      int baseX = size.horizontal () / 2;

      int centerX
          = std::clamp<int> (target.horizontal (), baseX, WORLD_WIDTH - baseX);

      int centerY
          = std::clamp<int> (target.vertical (), baseY, WORLD_HEIGHT - baseY);

      _viewport.setTarget (VectorAdapter (centerX, centerY));
      return;
    }

  const auto *mouse = sender.toSecurePtr<MouseArgs> ();
  const auto *keyboard = sender.toSecurePtr<KeyboardArgs> ();

  if (mouse || keyboard)
    {
      const auto &zoom = _viewport.getZoom ();

      const EMouseButton button
          = mouse != nullptr ? mouse->getPressed () : EMouseButton::NONE;

      const EKeyboardKey key
          = keyboard != nullptr ? keyboard->getPressed () : EKeyboardKey::NONE;

      if (button == EMouseButton::SCROLLUP || key == EKeyboardKey::Z)
        if (zoom + ZOOM_VALUE <= MAX_ZOOM)
          _viewport.setZoom (zoom + ZOOM_VALUE);

      if (button == EMouseButton::SCROLLDOWN || key == EKeyboardKey::X)
        if (zoom - ZOOM_VALUE >= MIN_ZOOM)
          _viewport.setZoom (zoom - ZOOM_VALUE);
    }
}

void
CameraManager::dispose () noexcept
{
}
