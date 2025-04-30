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

    //&* @note: start button clicked
    if (start.inLocalBounds(mousePos)) {
      cout << "Start Button Pressed" << endl;
      if (!tiles[0][0].isVisible()) {
        for (int i = 0; i < 8; i++) {
          for (int j = 0; j < 8; j++) {
            tiles[i][j].show();
          }
        }
      } else {
        for (int i = 0; i < 8; i++) {
          for (int j = 0; j < 8; j++) {
            tiles[i][j].show();
          }
        }
      }
    }

    //&* @note: exit button clicked
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
  //&* @note: wipe current frame
  window.clear(black);

  //&* @note: re-draw objects
  title.draw(window);
  start.draw(window);
  exit.draw(window);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tiles[i][j].draw(window);
    }
  }

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
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (tiles[i][j].inLocalBounds(mousePos) && tiles[i][j].isVisible())
        tiles[i][j].toggleHighlight(true);
      else
        tiles[i][j].toggleHighlight(false);
    }
  }

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
      exit("exit") {
  //&* @def: Initialize RenderWindow
  window.setFramerateLimit(120);      //* @note: Cap Framerate
  window.setKeyRepeatEnabled(true);   //* @note: Enable Key Repeat
  window.setMouseCursorVisible(true); //* @note: Enable Mouse Cursor Visibility

  //&* @def: Initialize Objects
  //* Board Tiles
  float x = 500, y = 500;

  //* rows
  for (int i = 0; i < 8; i++) {
    //* cols
    for (int j = 0; j < 8; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0)
          tiles[i][j].setBackgroundColor(white);
        else
          tiles[i][j].setBackgroundColor(black);
      } else {
        if (j % 2 != 0)
          tiles[i][j].setBackgroundColor(white);
        else
          tiles[i][j].setBackgroundColor(black);
      }
    }
  }

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
