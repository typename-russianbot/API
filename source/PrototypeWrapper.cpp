#include "../includes/Driver/PrototypeWrapper.h"

// TODO - @protected: Functions
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: pollEvents(const Event, const Vector2f)
void PrototypeWrapper::pollEvents(const Event event, const Vector2f mousePos) {
  //? @note: Close Window
  if (event.type == Event::Closed)
    window.close();
  if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
    window.close();

  //? @note: Mouse Button Pressed
  if (event.type == sf::Event::MouseButtonPressed &&
      event.mouseButton.button == Mouse::Left) {

    //&* @note: start button clicked | jump to game screen
    if (start.inLocalBounds(mousePos)) {
      //&* Hide menu components
      title.hide();
      start.hide();
      exit.hide();

      //&* Show game components
      checkerboard.show();
      back.show();
    }

    //&* @note: exit button clicked
    if (exit.inLocalBounds(mousePos)) {
      window.close();
      return;
    }

    //&* @note: back button clicked | jump back to menu screen
    if (back.inLocalBounds(mousePos)) {
      //&* Hide game components
      checkerboard.hide();
      back.hide();

      //&* Show menu components
    }
  }

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: updateFrame(void)
void PrototypeWrapper::updateFrame(void) {
  //&* @note: wipe current frame
  window.clear(green); //! @note: update to a sprite background or the ability
                       //! to swap backgrounds

  //&* @note: re-draw objects

  //&* textboxes
  title.draw(window);

  //&* buttons
  start.draw(window);
  exit.draw(window);
  back.draw(window);

  //&* checkerboard
  checkerboard.draw(window);

  //&* @note: display updated frame
  window.display();

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: toggleHighlights(const Vector2f)
void PrototypeWrapper::pollHighlights(const Vector2f mousePos) {
  //* @def: highlight start button
  if (start.inLocalBounds(mousePos) && start.isVisible())
    start.toggleHighlight(true);
  else
    start.toggleHighlight(false);

  //* @def: highlight exit button
  if (exit.inLocalBounds(mousePos) && exit.isVisible())
    exit.toggleHighlight(true);
  else
    exit.toggleHighlight(false);

  //* @def: highlight tiles
  checkerboard.toggleHighlight(mousePos);

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - @public: Resources
//////////////////////////////////////////////////////////////////////////////////////////
//* @public: PrototypeWrapper()
PrototypeWrapper::PrototypeWrapper(const string window_title,
                                   const Vector2f dimensions)
    : window(VideoMode::getDesktopMode(), window_title, Style::Fullscreen),
      window_dimensions(dimensions), title(window_title, green), start("start"),
      exit("exit"), back("back"), checkerboard({725, 200}) {
  //&* @def: Initialize RenderWindow

  //&* FrameCap = 120
  window.setFramerateLimit(120);

  //&* KeyRepeatEnabled = true
  window.setKeyRepeatEnabled(true);

  //&* MouseCursorVisible = true
  window.setMouseCursorVisible(true);

  //&* @def: Init RenderWindow Components

  //&* checkerboard
  checkerboard.hide();

  //&* textboxes
  title.resize(150);

  //&* buttons
  start.resize(35);
  start.setPosition({1280, 940});
  start.setHighlightColor(yellow);

  exit.resize(35);
  exit.setPosition({1280, 1015});
  exit.setHighlightColor(yellow);

  back.resize(35);
  back.setPosition({100, 1340});
  back.setHighlightColor(yellow);
  back.hide();

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
