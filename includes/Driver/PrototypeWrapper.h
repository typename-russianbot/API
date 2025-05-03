#pragma once
#include "../Objects/Board.h"
#include "../Objects/Button.h"
#include "../Objects/Pawn.h"
#include "../Objects/Player.h"
#include "../Objects/Textbox.h"

//& Class - PrototypeWrapper
class PrototypeWrapper {
private:
  //&* RenderWindow
  RenderWindow window;             //&* @var: window
  ContextSettings window_settings; //&* @var: window_settings
  Vector2f window_dimensions;      //&* @var: window_dimensions

  //&* Components

  //&* Textboxes & Buttons
  Textbox title;   //&* @var: title
  Button start;    //&* @var: start
  Button settings; //&* @var: settings
  Button exit;     //&* @var: exit
  Button back;     //&* @var: back

  //&* Board & players
  Board checkerboard; //&* @var: checkerboard
  Player player1;     //&* @var: player1
  Player player2;     //&* @var: player2

  //&* Trackers
  Color highlight_color; //&* @var: highlight_color

protected:
  // TODO - @protected: Functions
  ////////////////////////////////////////////////////////////////////////////////////////
  //^ @protected: pollEvents(const Event, const Vector2f)
  //^ @def: RenderWindow event polling

  void pollEvents(const Event, const Vector2f);
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //^ @protected: updateFrame(void)
  //^ @def: clears prev frame & draws updated frame data

  void updateFrame(void);
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //^ @protected: pollHighlights(const Vector2f)
  //^ @def: RenderWindow highlight polling

  void pollHighlights(const Vector2f);
  ////////////////////////////////////////////////////////////////////////////////////////

public:
  // TODO: Resources
  ////////////////////////////////////////////////////////////////////////////////////////
  //* @public: PrototypeWrapper(const string, const Vector2f)
  //* @def: constructor

  PrototypeWrapper(const string = "PrototypeWrapper",
                   const Vector2f = {static_cast<float>(_DisplayWidth),
                                     static_cast<float>(_DisplayHeight)});
  ////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////
  //* @public: ~PrototypeWrapper(void)
  //* @def: destructor

  ~PrototypeWrapper(void);
  ////////////////////////////////////////////////////////////////////////////////////////

  // TODO: Functions
  ////////////////////////////////////////////////////////////////////////////////////////
  //* @public: run(void)
  //* @def: program driver
  void run(void);
  ////////////////////////////////////////////////////////////////////////////////////////
};