#include "../includes/Windows/MainWindow.h"

// TODO - Resources //
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: MainWindow(const string)
MainWindow::MainWindow(const string window_title)
    : title(window_title), start("start"), settings("settings"), back("back"),
      exit("exit"), highlight(red) {

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
//&* @public: draw(RenderWindow&)
void MainWindow::draw(RenderWindow &window) { return; }
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
//&* @public: 
//* @def:
////////////////////////////////////////////////////////////////////////////////////////

// TODO - Mutators/Accessors //

// TODO - Toggles/Switches //