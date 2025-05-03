#include "../includes/Objects/Player.h"

// TODO - Resources //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: Player(Board&, const Color)
Player::Player(Board &checkerboard, const Color color)
    : remaining_pawns(12), pawn_color(color) {

  toggleStatus(true);

  //&* @def: define pawn properties
  for (auto i = 0; i < 12; i++) {
    pawns[i].setRadius(50);
    pawns[i].setOutlineColor(pawn_color);
    pawns[i].setBackgroundColor(black);
    pawns[i].toggleVisible(false);
  }

  //&* @def: set pawn positions
  int pawn = 0;

  if (color == blue) {
    for (unsigned int i = 0; i < 3; i++) {
      Tile cell;

      for (unsigned int j = 0; j < 8; j++) {
        if (i % 2 == 0 && j % 2 == 0) {
          cell = checkerboard.getCell({i, j});
          pawns[pawn].setPosition(
              {cell.getPosition().x + 12.f, cell.getPosition().y + 12.f});
          pawn++;
        } else if (i % 2 != 0 && j % 2 != 0) {
          cell = checkerboard.getCell({i, j});
          pawns[pawn].setPosition(
              {cell.getPosition().x + 12.f, cell.getPosition().y + 12.f});
          pawn++;
        }
      }
    }
  } else {
    for (unsigned int i = 5; i < 8; i++) {
      Tile cell;

      for (unsigned int j = 0; j < 8; j++) {
        if (i % 2 == 0 && j % 2 == 0) {
          cell = checkerboard.getCell({i, j});
          pawns[pawn].setPosition(
              {cell.getPosition().x + 12.f, cell.getPosition().y + 12.f});
          pawn++;
        } else if (i % 2 != 0 && j % 2 != 0) {
          cell = checkerboard.getCell({i, j});
          pawns[pawn].setPosition(
              {cell.getPosition().x + 12.f, cell.getPosition().y + 12.f});
          pawn++;
        }
      }
    }
  }
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: ~Player(void)
Player::~Player(void) { return; }
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Functions //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: draw(RenderWindow&)
void Player::draw(RenderWindow &window) {
  for (auto i = 0; i < 12; i++) {
    if (active_pawns[i] == true)
      pawns[i].draw(window);
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: movePawn(cosnt unsigned int, const Vector2f)
void Player::movePawn(const unsigned int pawn, const Vector2f pos) {
  pawns[pawn].move(pos);
  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: removePawn(const int)
void Player::removePawn(const int cell) {
  active_pawns[cell] = false;
  remaining_pawns--;

  return;
}
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Toggles //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleVisible(const bool)
void Player::toggleVisible(const bool toggle) {
  if (toggle) {
    for (int i = 0; i < 12; i++) {
      pawns[i].toggleVisible(true);
    }
  } else {
    for (int i = 0; i < 12; i++) {
      pawns[i].toggleVisible(false);
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleStatus(const bool)
void Player::toggleStatus(const bool toggle) {
  if (toggle) {
    for (int i = 0; i < 12; i++) {
      active_pawns[i] = true;
    }
  } else {
    for (auto i = 0; i < 12; i++) {
      active_pawns[i] = false;
    }
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Mutators //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setPawnColor(const Color)
void Player::setPawnColor(const Color color) {
  for (int i = 0; i < 12; i++) {
    pawns[i].setBackgroundColor(color);
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Accessors //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: getPawnsRemaining(void)
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: getPawnColor(void)
Color Player::getPawnColor(void) { return pawn_color; }
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public:
//* @def:

////////////////////////////////////////////////////////////////////////////////////////