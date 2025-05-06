#include "../../includes/Objects/Board.h"

// TODO - Resources //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: Board(const Vector2f)
Board::Board(const Vector2f position) : pattern(white, black), visible(false) {
  float x = position.x, y = position.y, xOffset = 0, yOffset = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j].resize(125);
      grid[i][j].setPosition({x + xOffset, y + yOffset});

      if (i % 2 == 0) {
        if (j % 2 == 0)
          grid[i][j].setBackgroundColor(pattern.getColorA());
        else
          grid[i][j].setBackgroundColor(pattern.getColorB());
      } else {
        if (j % 2 != 0)
          grid[i][j].setBackgroundColor(pattern.getColorA());
        else
          grid[i][j].setBackgroundColor(pattern.getColorB());
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
//&* @public: ~Board(void)
Board::~Board(void) { return; }
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Functions //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: draw(RenderWindow&)
void Board::draw(RenderWindow &window) {
  if (isVisible()) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        grid[i][j].draw(window);
      }
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: move(const Vector2f)
void Board::move(const Vector2f position) {
  float x = position.x, y = position.y, xOffset = 0, yOffset = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j].setPosition({x + xOffset, y + yOffset});

      yOffset += grid[i][j].getSize() + grid[i][j].getSize() / 2.f;
    }

    yOffset = 0;
    xOffset += grid[i][0].getSize() + grid[i][0].getSize() / 2.f;
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: resize(const float)
void Board::resize(const float size) {
  float x = grid[0][0].getPosition().x, y = grid[0][0].getPosition().y,
        xOffset = 0, yOffset = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      grid[i][j].setSize(size);
      grid[i][j].setPosition({x + xOffset, y + yOffset});

      yOffset += grid[i][j].getSize() + grid[i][j].getSize() / 2.f;
    }

    yOffset = 0;
    xOffset += grid[i][0].getSize() + grid[i][0].getSize() / 2.f;
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: invert(void)
void Board::invert(void) {
  Color temp = pattern.getColorA();
  pattern.setColorA(pattern.getColorB());
  pattern.setColorB(temp);

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0)
          grid[i][j].setBackgroundColor(pattern.getColorA());
        else
          grid[i][j].setBackgroundColor(pattern.getColorB());
      } else {
        if (j % 2 != 0)
          grid[i][j].setBackgroundColor(pattern.getColorA());
        else
          grid[i][j].setBackgroundColor(pattern.getColorB());
      }
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Toggles //

// TODO - Mutators/Accessors //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setPattern(const Color, const Color)
void Board::setPattern(const Pattern newPattern) {
  pattern = newPattern;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0)
          grid[i][j].setBackgroundColor(pattern.getColorA());
        else
          grid[i][j].setBackgroundColor(pattern.getColorB());
      } else {
        if (j % 2 != 0)
          grid[i][j].setBackgroundColor(pattern.getColorA());
        else
          grid[i][j].setBackgroundColor(pattern.getColorB());
      }
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setCell(const Vector2u, const TileState, const int)
void Board::setCell(const Vector2u cell, const TileState owner,
                    const int pawn) {
  grid[cell.x][cell.y].setOwner(owner);
  grid[cell.x][cell.y].setPawn(pawn);
  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: getPattern(void)
const Pattern Board::getPattern(void) { return pattern; }
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: getCell(const Vector2u)
const Tile Board::getCell(const Vector2u cell) { return grid[cell.x][cell.y]; }
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Toggles/Switches //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleHighlight(const Vector2f)
void Board::toggleHighlight(const Vector2f mousePos) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (grid[i][j].inLocalBounds(mousePos) && grid[i][j].isVisible())
        grid[i][j].toggleHighlight(true);
      else
        grid[i][j].toggleHighlight(false);
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleVisible(const bool)
void Board::toggleVisible(const bool toggle) {
  if (toggle) {
    visible = true;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        grid[i][j].toggleVisible(true);
      }
    }
  } else {
    visible = false;
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        grid[i][j].toggleVisible(false);
      }
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: isVisible(void)
bool Board::isVisible() {
  if (visible)
    return true;

  return false;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: inLocalBounds(const Vector2f)
bool Board::inLocalBounds(const Vector2f mousePos) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (grid[i][j].inLocalBounds(mousePos) && isVisible()) {
        return true;
      }
    }
  }

  return false;
}
////////////////////////////////////////////////////////////////////////////////////////
