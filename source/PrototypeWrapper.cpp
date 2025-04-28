#include "../includes/Driver/PrototypeWrapper.h"

// TODO - @protected: Functions
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: pollEvents(const Event, const Vector2f)
void PrototypeWrapper::pollEvents(const Event event, const Vector2f mousePos) {

  //! @note: Close window
  if (event.type == Event::Closed)
    window.close();
  if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
    window.close();

  //? @note: Detect Button input
  if (event.type == sf::Event::MouseButtonPressed &&
      event.mouseButton.button == Mouse::Left) {

    //* @note: start button clicked
    if (start.inLocalBounds(mousePos)) {
      cout << "Start Button Pressed" << endl;
    }

    //* exit button clicked
    if (exit.inLocalBounds(mousePos)) {
      cout << "Exit Button Pressed" << endl;
      window.close();
      return;
    }
  }

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: updateFrame(void)
void PrototypeWrapper::updateFrame(void) {
  //* @note: wipe previous frame
  window.clear(black);

  //* @note: draw objects
  title.draw(window);
  start.draw(window);
  exit.draw(window);

  //* @note: display updated frame
  window.display();

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: toggleHighlights(const Vector2f)
void PrototypeWrapper::pollHighlights(const Vector2f mousePos) {

  //* @def: start button toggle
  if (start.inLocalBounds(mousePos) && start.isVisible())
    start.toggleHighlight(true);
  else
    start.toggleHighlight(false);

  //* @def: exit button toggle
  if (exit.inLocalBounds(mousePos) && start.isVisible())
    exit.toggleHighlight(true);
  else
    exit.toggleHighlight(false);

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - @public: Resources
//////////////////////////////////////////////////////////////////////////////////////////
//* @public: PrototypeWrapper()
PrototypeWrapper::PrototypeWrapper(const string window_title,
                                   const Vector2f dimensions)
    : window(VideoMode::getDesktopMode(), window_title, Style::Fullscreen), window_dimensions(dimensions), title(window_title, green), start("start"),
      exit("exit")
      {

  //&* @def: Initialize RenderWindow
  window.setFramerateLimit(120);      //* @note: Cap Framerate
  window.setKeyRepeatEnabled(true);   //* @note: Enable Key Repeat
  window.setMouseCursorVisible(true); //* @note: Enable Mouse Cursor Visibility

  //&* @def: Initialize Objects

  //* program title
  title.resize(150);

  //* start button
  start.resize(35);
  start.setPosition({1280, 940});
  start.setHighlightColor(yellow);

  //* exit button
  exit.resize(35);
  exit.setPosition({1280, 1015});
  exit.setHighlightColor(yellow);
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//* @public: ~PrototypeWrapper()
PrototypeWrapper::~PrototypeWrapper(void) { return; }
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - @public: Functions
//////////////////////////////////////////////////////////////////////////////////////////
//* @public: run(void)
void PrototypeWrapper::run(void) {
  //* @note: initialize RenderWindow
  while (window.isOpen()) {
    Event event;
    Vector2f mousePos = static_cast<Vector2f>(Mouse::getPosition());

    //* @note: event polling
    while (window.pollEvent(event)) {
      pollEvents(event, mousePos);
    }

    //* @note: highlight buttons & update frame
    pollHighlights(mousePos);
    updateFrame();
  }

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//* @public:
//////////////////////////////////////////////////////////////////////////////////////////
