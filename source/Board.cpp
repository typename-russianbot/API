#include "../includes/Objects/Board.h"

// TODO: Resources
////////////////////////////////////////////////////////////////////////////////////////
//* @public: Board()
Board::Board(const Vector2f position) : colorA(white), colorB(black) {
  float x = position.x, y = position.y, xOffset = 0, yOffset = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tiles[i][j].resize(100);
      tiles[i][j].setPosition({x + xOffset, y + yOffset});

      if (i % 2 == 0) {
        if (j % 2 == 0)
          tiles[i][j].setBackgroundColor(colorA);
        else
          tiles[i][j].setBackgroundColor(colorB);
      } else {
        if (j % 2 != 0)
          tiles[i][j].setBackgroundColor(colorA);
        else
          tiles[i][j].setBackgroundColor(colorB);
      }
      yOffset += 150;
    }

    yOffset = 0;
    xOffset += 150;
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: ~Board(void)
Board::~Board(void) { return; }
////////////////////////////////////////////////////////////////////////////////////////

// TODO: Functions
////////////////////////////////////////////////////////////////////////////////////////
//* @public: draw(RenderWindow&)
void Board::draw(RenderWindow &window) {
  if (isVisible()) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        tiles[i][j].draw(window);
      }
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: move(const Vector2f)
void Board::move(const Vector2f position) {
  float x = position.x, y = position.y, xOffset = 0, yOffset = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tiles[i][j].setPosition({x + xOffset, y + yOffset});

      yOffset += 150;
    }

    yOffset = 0;
    xOffset += 150;
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: show(void)
void Board::show(void) {
  board_visible = true;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tiles[i][j].show();
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: hide(void)
void Board::hide(void) {
  board_visible = false;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      tiles[i][j].hide();
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: resize(const unsigned int)
void Board::resize(const unsigned int) { return; }
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: invert(void)
void Board::invert(void) {
  Color temp = colorA;
  colorA = colorB;
  colorB = temp;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0)
          tiles[i][j].setBackgroundColor(colorA);
        else
          tiles[i][j].setBackgroundColor(colorB);
      } else {
        if (j % 2 != 0)
          tiles[i][j].setBackgroundColor(colorA);
        else
          tiles[i][j].setBackgroundColor(colorB);
      }
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////

// TODO: Mutators
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setPattern(const Color, const Color)
void Board::setPattern(const Color A, const Color B) {
  colorA = A;
  colorB = B;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0)
          tiles[i][j].setBackgroundColor(colorA);
        else
          tiles[i][j].setBackgroundColor(colorB);
      } else {
        if (j % 2 != 0)
          tiles[i][j].setBackgroundColor(colorA);
        else
          tiles[i][j].setBackgroundColor(colorB);
      }
    }
  }

  return; 
}
////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
//* @public: setColorA(const Color)
void Board::setColorA(const Color color) {
  colorA = color;
  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: setPosition(const Vector2f)
void Board::setColorB(const Color color) {
  colorB = color;
  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: toggleHighlight(const Vector2f)
void Board::toggleHighlight(const Vector2f mousePos) {
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
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//* @public: toggleVisible(const bool)
void Board::toggleVisible(const bool toggle) {
  if (toggle) {
    board_visible = true;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        tiles[i][j].show();
      }
    }
  } else {
    board_visible = false;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        tiles[i][j].hide();
      }
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////

// TODO: Accessors
////////////////////////////////////////////////////////////////////////////////////////
//* @public: isVisible(void)
bool Board::isVisible() {
  if (board_visible)
    return true;

  return false;
}
////////////////////////////////////////////////////////////////////////////////////////
