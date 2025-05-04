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
  /// TEMP TEST

  auto player{ std::make_unique<CircleAdapter> () };
  auto text{ std::make_unique<TextAdapter> () };
  auto sprite{ std::make_unique<SpriteAdapter> () };
  auto rectangle{ std::make_unique<RectangleAdapter> () };
  auto screen{ std::make_unique<RectangleAdapter> () };
  auto world{ std::make_unique<RectangleAdapter> () };

  screen
      ->setSize (VectorAdapter{ DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT })
      .setPosition (VectorAdapter{ 0, 0 })
      .setFillColor (EColor::CornFlowerBlue);

  world->setSize (VectorAdapter{ (int)WORLD_WIDTH, (int)WORLD_HEIGHT })
      .setPosition (VectorAdapter{ 0, 0 })
      .setFillColor (EColor::DarkSeaGreen);

  player->setRadius (15)
      .setOutlineSize (5)
      .setFillColor (EColor::Black)
      .setOutlineColor (EColor::White);

  text->setText ("Hello World")
      .setFontSize (30)
      .setFontSpacing (3)
      .setFont (EFont::Romulus)
      .setFontColor (EColor::White)
      .setPosition (VectorAdapter (200, 100));

  rectangle->setSize (VectorAdapter{ 50, 50 })
      .setPosition (VectorAdapter{ 250, 300 })
      .setTexture (ETexture::ButtonDefault)
      .setFillColor (EColor::CornFlowerBlue);

  sprite->setPosition (VectorAdapter (200, 500))
      .setTexture (ETexture::ButtonDefault);

  auto TEMP_EVENT_DEBUG =
      [&player] (const std::shared_ptr<EventManager> &eventManager,
                 const IEventArgs &sender) {
        auto keyboard = sender.toSecurePtr<KeyboardArgs> ();

        if (keyboard == nullptr)
          return;

        const int space = 32;
        const auto key = keyboard->getPressed ();
        auto y = player->getPosition ().vertical ();
        auto x = player->getPosition ().horizontal ();

        // SOUND TEST
        if (key == EKeyboardKey::G)
          eventManager->invoke (EEvent::Sound,
                                SoundArgs (ESound::ButtonClicked));

        if (key == EKeyboardKey::H)
          eventManager->invoke (EEvent::Sound, SoundArgs (EMusic::DarkForest));

        // PLAYER MOVEMENT
        if (key == EKeyboardKey::RIGHT)
          x += space;

        else if (key == EKeyboardKey::LEFT)
          x -= space;

        else if (key == EKeyboardKey::UP)
          y -= space;

        else if (key == EKeyboardKey::DOWN)
          y += space;

        player->setPosition (VectorAdapter (x, y));

        eventManager->invoke (EEvent::CameraCenter,
                              CameraArgs (player->getPosition ()));
      };

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

  windowManager->events (WindowCallback ([&eventManager, &cameraManager,
                                          &soundManager, &windowManager,
                                          &TEMP_EVENT_DEBUG] (
                                             WindowArgs &window) {
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
          eventManager->invoke (EEvent::WindowResized, sender);
          eventManager->invoke (EEvent::CameraCenter, sender);
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
          cameraManager->execute (sender);

          auto keyboard = sender.toSecurePtr<KeyboardArgs> ();

          if (keyboard == nullptr)
            return;

          if (keyboard->getPressed () == EKeyboardKey::ESCAPE)
            eventManager->invoke (EEvent::ExitGame, sender);

          TEMP_EVENT_DEBUG (eventManager, sender);
        }));
  }));

  windowManager->render (
      WindowCallback ([&screen, &text, &rectangle, &sprite, &world,
                       &player] (WindowArgs &window) {
        window.render (*screen);
        window.render (*text);
        window.render (*rectangle);
        window.render (*sprite);

        window.beginViewport ();
        window.render (*world);
        window.render (*player);
        window.endViewport ();
      }));

  windowManager->dispose ();
  return 0;
}
