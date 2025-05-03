#include "../includes/Driver/PrototypeWrapper.h"

// TODO - @protected: Functions
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: pollEvents(const Event, const Vector2f)
void PrototypeWrapper::pollEvents(const Event event, const Vector2f mousePos) {
  //&* @note: close window
  if (event.type == Event::Closed)
    window.close();

  //&* @note: left mouse button pressed
  if (event.type == sf::Event::MouseButtonPressed &&
      event.mouseButton.button == Mouse::Left) {
    int button = menu.events(mousePos, window);

    if (button == 1)
      game.toggleVisible(true);
    else if (button == 3)
      game.toggleVisible(false);
  }
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: updateFrame(void)
void PrototypeWrapper::updateFrame(void) {
  //&* @note: wipe current frame
  window.clear(black); //! @note: update to a sprite background or the ability
                       //! to swap backgrounds

  //&* MainWindow
  menu.draw(window);

  //&* GameWindow
  game.draw(window);

  //&* @note: display updated frame
  window.display();

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: pollHighlights(const Vector2f)
void PrototypeWrapper::pollHighlights(const Vector2f mousePos) {
  if (menu.isVisible())
    menu.highlights(mousePos);

  if (game.isVisible())
    game.highlights(mousePos);

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - @public: Resources
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: PrototypeWrapper()
PrototypeWrapper::PrototypeWrapper(const string window_title,
                                   const Vector2f dimensions)
    : window(VideoMode::getDesktopMode(), window_title, Style::Fullscreen),
      window_dimensions(dimensions), menu(window_title), game() {
  //&* @def: Initialize RenderWindow
  window.setFramerateLimit(90);       //&* FrameCap = 90
  window.setKeyRepeatEnabled(true);   //&* KeyRepeatEnabled = true
  window.setMouseCursorVisible(true); //&* MouseCursorVisible = true

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: ~PrototypeWrapper()
PrototypeWrapper::~PrototypeWrapper(void) { return; }
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - @public: Functions
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: run(void)
void PrototypeWrapper::run(void) {
  //&* @note: initialize RenderWindow
  while (window.isOpen()) {
    Event event;
    Vector2f mousePos = static_cast<Vector2f>(Mouse::getPosition());

    //&* @note: event polling
    while (window.pollEvent(event)) {
      pollEvents(event, mousePos);
    }

    //&* @note: highlight buttons & update frame
    pollHighlights(mousePos);
    updateFrame();
  }

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////