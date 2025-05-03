#include "../includes/Driver/PrototypeWrapper.h"

// TODO - Functions //
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: pollEvents(const Event, const Vector2f)
void PrototypeWrapper::pollEvents(const Event event, const Vector2f mousePos) {
  //&* @note: ++ window closed ++
  if (event.type == Event::Closed)
    window.close();
  //&* @note: ++ key pressed ++
  if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
    window.close();
  //&* @note: ++ left mouse pressed ++
  if (event.type == Event::MouseButtonPressed &&
      event.mouseButton.button == Mouse::Left) {
    int menu_button = menu.events(mousePos, window);
    if (menu_button == _start)
      game.toggleVisible(true);
    else if (menu_button == _back)
      game.toggleVisible(false);
    game.events(mousePos, window);
  }
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: updateFrame(void)
void PrototypeWrapper::updateFrame(void) {
  window.clear(black);
  menu.draw(window);
  game.draw(window);
  window.display();
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: pollHighlights(const Vector2f)
void PrototypeWrapper::pollHighlights(const Vector2f mousePos) {
  menu.highlights(mousePos);
  game.highlights(mousePos);
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - Resources //
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: PrototypeWrapper()
PrototypeWrapper::PrototypeWrapper(const string window_title,
                                   const Vector2f dimensions)
    : window(VideoMode::getDesktopMode(), window_title, Style::Fullscreen),
      window_dimensions(dimensions), menu(window_title), game() {
  window.setFramerateLimit(90);
  window.setKeyRepeatEnabled(true);
  window.setMouseCursorVisible(true);
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: ~PrototypeWrapper()
PrototypeWrapper::~PrototypeWrapper(void) { return; }
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - Functions //
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: run(void)
void PrototypeWrapper::run(void) {
  while (window.isOpen()) {
    Event event;
    Vector2f mousePos = static_cast<Vector2f>(Mouse::getPosition());
    while (window.pollEvent(event)) {
      pollEvents(event, mousePos);
      pollHighlights(mousePos);
    }
    updateFrame();
  }
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////