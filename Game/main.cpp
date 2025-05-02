#include <keyboard_args.hpp>
#include <rectangle_adapter.hpp>
#include <sprite_adapter.hpp>
#include <text_adapter.hpp>
#include <window_adapter.hpp>
#include <window_manager.hpp>

int
main ()
{
  /// TEMP

  auto text{ std::make_unique<TextAdapter> () };
  auto sprite{ std::make_unique<SpriteAdapter> () };
  auto rectangle{ std::make_unique<RectangleAdapter> () };

  text->setText ("Hello World");
  text->setFontSize (22);
  text->setFontColor (EColor::Tomate);
  text->setPosition (VectorAdapter (200, 100));

  rectangle->setSize (VectorAdapter{ 50, 50 });
  rectangle->setPosition (VectorAdapter{ 250, 300 });
  rectangle->setTexture (ETexture::ButtonDefault);
  rectangle->setFillColor (EColor::CornFlowerBlue);

  sprite->setPosition (VectorAdapter (200, 500));
  sprite->setTexture (ETexture::ButtonDefault);

  ///////////////////////////////////////////////////////////////////////////////////

  auto windowManager{ std::make_unique<WindowManager> () };
  auto eventManager{ std::make_shared<EventManager> () };
  auto resourceManager{ std::make_shared<ResourceManager> () };

  windowManager->withEventManager (eventManager)
      .withResourceManager (resourceManager)
      .initialize ();

  windowManager->events (WindowCallback ([&] (WindowArgs &window) {
    EventId eventId;

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
  }));

  windowManager->dispose ();
  return 0;
}
