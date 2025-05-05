#include "../../includes/Windows/Menu.h"

// TODO - Resources //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: MainWindow(const string) -- done
Menu::Menu(const string window_title)
    : title(window_title), start("start"), options("settings"), back("back"),
      exit("exit"), highlight(red), visible(true) {

  //* Textboxes/Buttons
  int button_size = 35;

  //* @note: title
  title.resize(150);

  //* @note: start button
  start.resize(button_size);
  start.setPosition({1280, 940});
  start.setHighlightColor(highlight);

  //* @note: settings button
  options.resize(button_size);
  options.setPosition({1280, 1040});
  options.setHighlightColor(highlight);

  //* @note: back button
  back.resize(button_size);
  back.setPosition({100, 1340});
  back.setHighlightColor(highlight);
  back.toggleVisible(false);

  //* @note: exit button
  exit.resize(button_size);
  exit.setPosition({1280, 1140});
  exit.setHighlightColor(highlight);

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: ~MainWindow(void)
Menu::~Menu(void) { return; }
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Functions //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: draw(RenderWindow&) -- done
void Menu::draw(RenderWindow &window) {
  if (isVisible()) {
    title.draw(window);
    start.draw(window);
    options.draw(window);
    exit.draw(window);
  }
  back.draw(window);
  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: highlights(const Vector2f)
void Menu::highlights(const Vector2f mousePos) {
  //* ++ start ++ *//
  if (start.inLocalBounds(mousePos) && start.isVisible())
    start.toggleHighlight(true);
  else
    start.toggleHighlight(false);

  //* ++ settings ++ *//
  if (options.inLocalBounds(mousePos) && options.isVisible())
    options.toggleHighlight(true);
  else
    options.toggleHighlight(false);

  //* ++ back ++ *//
  if (back.inLocalBounds(mousePos) && back.isVisible())
    back.toggleHighlight(true);
  else
    back.toggleHighlight(false);

  //* ++ exit ++ *//
  if (exit.inLocalBounds(mousePos) && exit.isVisible())
    exit.toggleHighlight(true);
  else
    exit.toggleHighlight(false);

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: events(const Vector2f, RenderWindow&, Game&, Options&)
void Menu::events(const Vector2f mousePos, RenderWindow &window, Game &game,
                  Settings &settings) {
  // TODO - @note: start button clicked | jump to game
  if (start.inLocalBounds(mousePos) && start.isVisible()) {
    //* @note: hide menu/options
    toggleVisible(false);
    settings.toggleVisible(false);

    //* @note: show game
    game.toggleVisible(true);
  }

  // TODO - @note: settings button clicked | jump to settings
  if (options.inLocalBounds(mousePos) && options.isVisible()) {
    //* @note: hide menu/game
    toggleVisible(false);
    game.toggleVisible(false);

    //* @note: show options
    settings.toggleVisible(true);
  }

  // TODO - @note: back button clicked | jump to menu
  if (back.inLocalBounds(mousePos) && back.isVisible()) {
    //* @note: hide game/options
    game.toggleVisible(false);
    settings.toggleVisible(false);

    //* @note: show menu
    toggleVisible(true);
  }

  // TODO - @note: exit button clicked | exit program
  if (exit.inLocalBounds(mousePos) && exit.isVisible()) {
    window.close(); //* @note: close window
  }
}
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Toggles/Switches //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleVisible(const bool)
void Menu::toggleVisible(const bool toggle) {
  if (toggle) {
    visible = true;
    title.toggleVisible(true);
    start.toggleVisible(true);
    options.toggleVisible(true);
    back.toggleVisible(false);
    exit.toggleVisible(true);
  } else {
    visible = false;
    title.toggleVisible(false);
    start.toggleVisible(false);
    options.toggleVisible(false);
    back.toggleVisible(true);
    exit.toggleVisible(false);
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: isVisible(void)
bool Menu::isVisible(void) {
  if (visible)
    return true;

  return false;
}
////////////////////////////////////////////////////////////////////////////////////////
