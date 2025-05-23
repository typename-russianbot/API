#pragma once
#include "../Master/master.h"

//& Class - Textbox
class Textbox {
private:
  //&* Components
  Font font;                 //&* @var: font
  Text text;                 //&* @var: text
  RectangleShape background; //&* @var: background

  //&* Trackers
  Color text_color;          //&* @var: text_color
  Color background_color;    //&* @var: background_color
  Color outline_color;       //&* @var: outline_color
  Vector2f textbox_position; //&* @var: textbox_position
  bool textbox_visible;      //&* @var: textbox_visible
  bool outline_visible;      //&* @var: outline_visible

  //&* Friends
  friend class Button; //&* @class: Button
protected:
public:
  // TODO - Resources //
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: TextBox(const string, const Color, const Vector2f)
  //* @def: Constructor

  Textbox(const string = "sample text", const Color = white,
          const Vector2f = {1280, 720});
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: ~TextBox(void)
  //* @def: Destructor

  ~Textbox(void);
  //////////////////////////////////////////////////////////////////////////////////

  // TODO - Functions //
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: draw(RenderWindow&)
  //* @def: draws textbox

  void draw(RenderWindow &);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: move(const Vector2f)
  //* @def: moves textbox

  void move(const Vector2f);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: resize(const unsigned int)
  //* @def: resizes textbox

  void resize(const unsigned int);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: invert(void)
  //* @def: swaps the background color & the text color

  void invert(void);
  //////////////////////////////////////////////////////////////////////////////////

  // TODO - Toggles //
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: toggleOutline(const bool)
  //* @def: true = visible, false = hidden

  void toggleOutline(const bool);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: toggleVisible(const bool)
  //* @def: true = visible, false = hidden

  void toggleVisible(const bool);
  //////////////////////////////////////////////////////////////////////////////////

  // TODO - Mutators //
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: setPosition(const Vector2f)
  //* @def: sets textbox position

  void setPosition(const Vector2f);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: setText(const string)
  //* @def: sets text string

  void setText(const string);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: setOutlineThickness(const float)
  //* @def: sets background outline thickness

  void setOutlineThickness(const float);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: setBackgroundColor(const Color)
  //* @def: sets background fill color

  void setBackgroundColor(const Color);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: setTextColor(const Color)
  //* @def: sets text fill color

  void setTextColor(const Color);
  //////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: setOutlineColor(const Color)
  //* @def: sets background outline color

  void setOutlineColor(const Color);
  //////////////////////////////////////////////////////////////////////////////////

  // TODO - Accessors //
  //////////////////////////////////////////////////////////////////////////////////
  //&* @public: isVisible(void)
  //* @def: returns true if visible

  bool isVisible(void);
  //////////////////////////////////////////////////////////////////////////////////
};