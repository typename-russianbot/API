#include "../../includes/Windows/Settings.h"

// TODO - Resources //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: Settings(void)
Settings::Settings(void)
    : title("Settings"), backgrounds("Backgrounds"), boards("Checkerboards"),
      pawns("Pawns"), highlight(red), visible(false) {
  int button_size = 35;

  //* @note: textboxes
  title.resize(75);
  title.setPosition({1280, 200});

  //* @note: buttons
  backgrounds.resize(button_size);
  backgrounds.setPosition({1280, 400});
  backgrounds.setHighlightColor(highlight);

  boards.resize(button_size);
  boards.setPosition({1280, 500});
  boards.setHighlightColor(highlight);

  pawns.resize(button_size);
  pawns.setPosition({1280, 600});
  pawns.setHighlightColor(highlight);

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: ~Settings(void)
Settings::~Settings(void) { return; }
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Functions //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: draw(RenderWindow&)
void Settings::draw(RenderWindow &window) {
  if (isVisible()) {
    title.draw(window);
    backgrounds.draw(window);
    boards.draw(window);
    pawns.draw(window);
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: highlights(const Vector2f)
void Settings::highlights(const Vector2f mousePos) {
  //* ++ backgrounds ++ *//
  if (backgrounds.inLocalBounds(mousePos) && isVisible())
    backgrounds.toggleHighlight(true);
  else
    backgrounds.toggleHighlight(false);

  //* ++ checkerboards ++ *//
  if (boards.inLocalBounds(mousePos) && isVisible())
    boards.toggleHighlight(true);
  else
    boards.toggleHighlight(false);

  //* ++ pawns ++ *//
  if (pawns.inLocalBounds(mousePos) && isVisible())
    pawns.toggleHighlight(true);
  else
    pawns.toggleHighlight(false);

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: events(const Vector2f, RenderWindow&)
void Settings::events(const Vector2f, RenderWindow &) { return; }
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Toggles/Switches //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleVisible(const bool)
void Settings::toggleVisible(const bool toggle) {
  if (toggle) {
    title.toggleVisible(true);
    backgrounds.toggleVisible(true);
    boards.toggleVisible(true);
    pawns.toggleVisible(true);
    visible = true;

  } else {
    title.toggleVisible(false);
    backgrounds.toggleVisible(false);
    boards.toggleVisible(false);
    pawns.toggleVisible(false);
    visible = false;
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: isVisible(void)
bool Settings::isVisible(void) {
  if (visible)
    return true;

  return false;
}
////////////////////////////////////////////////////////////////////////////////////////