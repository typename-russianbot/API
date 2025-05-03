#include "../includes/Driver/PrototypeWrapper.h"

// TODO - @protected: Functions
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: pollEvents(const Event, const Vector2f)
void PrototypeWrapper::pollEvents(const Event event, const Vector2f mousePos) {
  //&* @note: close window
  if (event.type == Event::Closed)
    window.close();

  if (event.type == sf::Event::MouseButtonPressed &&
      event.mouseButton.button == Mouse::Left) {
    int button = main_window.events(mousePos, window);

    if (button == 1) {
      checkerboard.toggleVisible(true);
      player1.toggleVisible(true);
      player2.toggleVisible(true);
    } else if (button == 3) {
      checkerboard.toggleVisible(false);
      player1.toggleVisible(false);
      player2.toggleVisible(false);
    }
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
  main_window.draw(window);

  //&* checkerboard
  checkerboard.draw(window);

  //&* players
  player1.draw(window);
  player2.draw(window);

  //&* @note: display updated frame
  window.display();

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: toggleHighlights(const Vector2f)
void PrototypeWrapper::pollHighlights(const Vector2f mousePos) {
  main_window.highlights(mousePos);

  //&* @def: highlight tiles
  checkerboard.toggleHighlight(mousePos);

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - @public: Resources
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: PrototypeWrapper()
PrototypeWrapper::PrototypeWrapper(const string window_title,
                                   const Vector2f dimensions)
    : window(VideoMode::getDesktopMode(), window_title, Style::Fullscreen),
      window_dimensions(dimensions), main_window(window_title),
      checkerboard({725, 175}), player1(checkerboard, blue),
      player2(checkerboard, yellow), highlight_color(red) {
  //&* @def: Initialize RenderWindow
  window.setFramerateLimit(90);       //&* FrameCap = 90
  window.setKeyRepeatEnabled(true);   //&* KeyRepeatEnabled = true
  window.setMouseCursorVisible(true); //&* MouseCursorVisible = true

  //&* @def: Init RenderWindow Components

  //&* checkerboard -- static, we never need to make changes to the board
  checkerboard.toggleVisible(false);
  checkerboard.setPattern(red, white);
  checkerboard.resize(125);
  Tile tile = checkerboard.getCell({3, 0});
  player1.movePawn(0, tile.getPosition());

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