#include <camera_args.hpp>
#include <camera_manager.hpp>
#include <circle_adapter.hpp>
#include <enum_adapter.hpp>
#include <keyboard_args.hpp>
#include <rectangle_adapter.hpp>
#include <size_args.hpp>
#include <sound_args.hpp>
#include <sound_manager.hpp>
#include <sprite_adapter.hpp>
#include <text_adapter.hpp>
#include <window_adapter.hpp>
#include <window_manager.hpp>

int
main ()
{
  /// TEMP

  auto player{ std::make_unique<CircleAdapter> () };
  auto text{ std::make_unique<TextAdapter> () };
  auto sprite{ std::make_unique<SpriteAdapter> () };
  auto rectangle{ std::make_unique<RectangleAdapter> () };

  player->setRadius (15);
  player->setOutlineSize (5);
  player->setFillColor (EColor::Black);
  player->setOutlineColor (EColor::White);

  text->setText ("Hello World");
  text->setFontSize (30);
  text->setFontSpacing (3);
  text->setFont (EFont::Romulus);
  text->setFontColor (EColor::White);
  text->setPosition (VectorAdapter (200, 100));

  rectangle->setSize (VectorAdapter{ 50, 50 });
  rectangle->setPosition (VectorAdapter{ 250, 300 });
  rectangle->setTexture (ETexture::ButtonDefault);
  rectangle->setFillColor (EColor::CornFlowerBlue);

  sprite->setPosition (VectorAdapter (200, 500));
  sprite->setTexture (ETexture::ButtonDefault);

  ////////////////////////////////////////////////////////////////////////

  auto soundManager{ std::make_shared<SoundManager> () };
  auto eventManager{ std::make_shared<EventManager> () };
  auto windowManager{ std::make_unique<WindowManager> () };
  auto cameraManager{ std::make_shared<CameraManager> () };
  auto resourceManager{ std::make_shared<ResourceManager> () };

  soundManager->withResourceManager (resourceManager);

  windowManager->withSoundManager (soundManager)
      .withEventManager (eventManager)
      .withCameraManager (cameraManager)
      .withResourceManager (resourceManager)
      .initialize ();

  windowManager->events (WindowCallback ([&] (WindowArgs &window) {
    EventId eventId;

    /// WINDOW EVENTS //////////////////////////////////////////////////////

    eventId = window.onKeyPressed.subscribe (
        EventCallback ([&] (const IEventArgs &sender) {
          eventManager->invoke (EEvent::KeyPressed, sender);
        }));

    eventId = window.onTextEntered.subscribe (
        EventCallback ([&] (const IEventArgs &sender) {
          eventManager->invoke (EEvent::TextEntered, sender);
        }));

    eventId = window.onKeyReleased.subscribe (
        EventCallback ([&] (const IEventArgs &sender) {
          eventManager->invoke (EEvent::KeyReleased, sender);
        }));

    eventId = window.onMouseMoved.subscribe (
        EventCallback ([&] (const IEventArgs &sender) {
          eventManager->invoke (EEvent::MouseMoved, sender);
        }));

    eventId = window.onMouseWheelScrolled.subscribe (
        EventCallback ([&] (const IEventArgs &sender) {
          eventManager->invoke (EEvent::MouseWheelScrolled, sender);
        }));

    eventId = window.onMouseButtonPressed.subscribe (
        EventCallback ([&] (const IEventArgs &sender) {
          eventManager->invoke (EEvent::MouseButtonPressed, sender);
        }));

    eventId = window.onMouseButtonReleased.subscribe (
        EventCallback ([&] (const IEventArgs &sender) {
          eventManager->invoke (EEvent::MouseButtonReleased, sender);
        }));

    eventId = window.onResized.subscribe (
        EventCallback ([&] (const IEventArgs &sender) {
          eventManager->invoke (EEvent::CameraCenter, sender);
          eventManager->invoke (EEvent::WindowResized, sender);
        }));

    /// LISTERNERS //////////////////////////////////////////////////////
    eventId = eventManager->subscribe (
        EEvent::CameraCenter, EventCallback ([&] (const IEventArgs &sender) {
          cameraManager->execute (sender);
        }));

    eventId = eventManager->subscribe (
        EEvent::WindowResized, EventCallback ([&] (const IEventArgs &sender) {
          cameraManager->execute (sender);
        }));

    eventId = eventManager->subscribe (
        EEvent::MouseWheelScrolled,
        EventCallback ([&] (const IEventArgs &sender) {
          cameraManager->execute (sender);
        }));

    eventId = eventManager->subscribe (
        EEvent::Sound, EventCallback ([&] (const IEventArgs &sender) {
          soundManager->execute (sender);
        }));

    eventId = eventManager->subscribe (
        EEvent::ExitGame, EventCallback ([&] (const IEventArgs &sender) {
          windowManager->close ();
        }));

    eventId = eventManager->subscribe (
        EEvent::KeyPressed, EventCallback ([&] (const IEventArgs &sender) {
          auto keyboard = sender.toSecurePtr<KeyboardArgs> ();

          if (keyboard == nullptr)
            return;

          if (keyboard->getPressed () == EKeyboardKey::ESCAPE)
            {
              eventManager->invoke (EEvent::ExitGame, sender);
            }
        }));
        
  }));

  windowManager->render (WindowCallback ([&] (WindowArgs &window) {
    window.render (*text);
    window.render (*rectangle);
    window.render (*sprite);
    window.render (*player);
  }));

  windowManager->dispose ();
  return 0;
}
