#include "../includes/Windows/MainWindow.h"

// TODO - Resources //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: MainWindow(const string) -- done
MainWindow::MainWindow(const string window_title)
    : title(window_title), start("start"), settings("settings"), back("back"),
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
  settings.resize(button_size);
  settings.setPosition({1280, 1040});
  settings.setHighlightColor(highlight);

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
MainWindow::~MainWindow(void) { return; }
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Functions //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: draw(RenderWindow&) -- done
void MainWindow::draw(RenderWindow &window) {
  title.draw(window);
  start.draw(window);
  settings.draw(window);
  back.draw(window);
  exit.draw(window);
  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: highlights(const Vector2f)
void MainWindow::highlights(const Vector2f mousePos) {
  //* ++ start ++ *//
  if (start.inLocalBounds(mousePos) && start.isVisible())
    start.toggleHighlight(true);
  else
    start.toggleHighlight(false);
  //* ++ settings ++ *//
  if (settings.inLocalBounds(mousePos) && settings.isVisible())
    settings.toggleHighlight(true);
  else
    settings.toggleHighlight(false);
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
//&* @public: events
int MainWindow::events(const Vector2f mousePos, RenderWindow &window) {
  // TODO - @note: start button clicked | jump to game
  if (start.inLocalBounds(mousePos) && start.isVisible()) {
    title.toggleVisible(false);
    start.toggleVisible(false);
    settings.toggleVisible(false);
    exit.toggleVisible(false);
    back.toggleVisible(true);
    return _start;
  }
  // TODO - @note: settings button clicked | jump to settings
  if (settings.inLocalBounds(mousePos) && settings.isVisible()) {
    title.toggleVisible(false);
    start.toggleVisible(false);
    settings.toggleVisible(false);
    exit.toggleVisible(false);
    back.toggleVisible(true);
    return _settings;
  }
  // TODO - @note: back button clicked | jump to menu
  if (back.inLocalBounds(mousePos) && back.isVisible()) {
    title.toggleVisible(true);
    start.toggleVisible(true);
    settings.toggleVisible(true);
    exit.toggleVisible(true);
    back.toggleVisible(false);
    return _back;
  }
  // TODO - @note: exit button clicked | exit program
  if (exit.inLocalBounds(mousePos) && exit.isVisible()) {
    window.close();
    return _exit;
  }
  return -1; //! @note: something's gone horribly wrong...
}
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Toggles/Switches //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleVisible(const bool)
void MainWindow::toggleVisible(const bool toggle) {
  if (toggle) {
    visible = true;
    title.toggleVisible(true);
    start.toggleVisible(true);
    settings.toggleVisible(true);
    back.toggleVisible(false);
    exit.toggleVisible(true);
  } else {
    visible = false;
    title.toggleVisible(false);
    start.toggleVisible(false);
    settings.toggleVisible(false);
    back.toggleVisible(false);
    exit.toggleVisible(false);
  }

  return;
}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: isVisible(void)
bool MainWindow::isVisible(void) {
  if (visible)
    return true;

  return false;
}
////////////////////////////////////////////////////////////////////////////////////////
