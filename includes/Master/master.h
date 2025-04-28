#pragma once

//& @dependencies: Standard C++ Library
#include <iostream>
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

//&* @macro: window dimensions
#define _DisplayWidth static_cast<float>(VideoMode::getDesktopMode().width)
#define _DisplayHeight static_cast<float>(VideoMode::getDesktopMode().height)

//&* @macro: fonts
#define _BungeeSpice "resources/fonts/BungeeSpice-Regular.ttf"
#define _Kadwa "resources/fonts/Kadwa-Regular.ttf"
#define _Roboto "resources/fonts/Roboto-Regular.ttf"

//^ @functions: