#include <algorithm>
#include <camera_args.hpp>
#include <camera_manager.hpp>
#include <constants_core.hpp>
#include <mouse_args.hpp>
#include <size_args.hpp>

const ViewportAdapter &
CameraManager::getViewport () const noexcept
{
  return _viewport;
}

// TODO :: CORRIGIR O CALCULO DO CENTRO DA CAMERA
void
CameraManager::execute (const IEventArgs &sender) noexcept
{
  if (const auto *args = sender.toSecurePtr<SizeArgs> ())
    {
      _viewport.setSize (args->getSize ());
      _viewport.setTarget (args->getSize () / 2);
      _viewport.setCenter (args->getSize () / 2);
      _viewport.setZoom (-_viewport.getZoom () + 1.0f);
      return;
    }

  if (const auto *args = sender.toSecurePtr<CameraArgs> ())
    {
      auto target = args->getTarget ();
      auto size = _viewport.getSize ();

      auto cameraCenter = target;

      auto y = cameraCenter.vertical ();
      auto x = cameraCenter.horizontal ();

      x = std::clamp<int> (x, 0, WORLD_WIDTH - size.horizontal ());

      y = std::clamp<int> (y, 0, WORLD_HEIGHT - size.vertical ());

      _viewport.setCenter (VectorAdapter (x, y));
      _viewport.setTarget (target);
      return;
    }

  if (const auto *args = sender.toSecurePtr<MouseArgs> ())
    {
      if (args->getPressed () == EMouseButton::SCROLLUP)
        {
          _viewport.setZoom (0.05f);
        }
      if (args->getPressed () == EMouseButton::SCROLLDOWN)
        {
          _viewport.setZoom (-0.05f);
        }
      return;
    }
}

void
CameraManager::dispose () noexcept
{
}
