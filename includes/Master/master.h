#pragma once

//& @dependencies: Standard C++ Library
#include <iostream>
#include <type_traits>
using namespace std;

//& @dependencies: SFML 2.6.1 Library
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowHandle.hpp>
#include <SFML/Window/WindowStyle.hpp>
using namespace sf;

//&* @macro: color
#define transparent Color::Transparent
#define black Color::Black
#define white Color::White
#define red Color::Red
#define blue Color::Blue
#define green Color::Green
#define magenta Color::Magenta
#define cyan Color::Cyan
#define yellow Color::Yellow

//&* @macro: display dimensions
#define _DisplayWidth static_cast<float>(VideoMode::getDesktopMode().width)
#define _DisplayHeight static_cast<float>(VideoMode::getDesktopMode().height)

//&* @macro: fonts
#define _BungeeSpice "resources/fonts/BungeeSpice-Regular.ttf"
#define _Kadwa "resources/fonts/Kadwa-Regular.ttf"
#define _Roboto "resources/fonts/Roboto-Regular.ttf"

//~ @enum: buttons
enum buttons { _start, _settings, _back, _exit };

//~ @enum: TileState
enum TileState { None, Player1, Player2 };

//* @global: Class - Pattern
class Pattern {
private:
  // TODO - Components //
  Color colorA; //&* @var: colorA
  Color colorB; //&* @var: colorB

public:
  // TODO - Resources //
  ////////////////////////////////////////////////////////////////////////////////////////
  //&* @public: Pattern(const Color, const Color)
  //* @def: constructor

  Pattern(const Color = black, const Color = white);
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //&* @public: ~Pattern(void)
  //* @def: destructor

  ~Pattern(void);
  ////////////////////////////////////////////////////////////////////////////////////////

  // TODO - Mutators/Accessors //
  ////////////////////////////////////////////////////////////////////////////////////////
  //&* @public: setPattern(const Color, const Color)
  //* @def: sets colorA & colorB

  void setPattern(const Color, const Color);
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //&* @public: setColorA(const Color)
  //* @def: sets colorA

  void setColorA(const Color);
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //&* @public: setColorB(const Color)
  //* @def: sets colorB

  void setColorB(const Color);
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //&* @public: getPattern(void)
  //* @def: gets Pattern components

  Pattern getPattern(void);
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //&* @public: getColorA(void)
  //* @def: gets colorA

  Color getColorA(void);
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //&* @public: getColorB(void)
  //* @def: gets Pattern colorB

  Color getColorB(void);
  ////////////////////////////////////////////////////////////////////////////////////////
};

//^ @functions:
