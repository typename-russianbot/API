#include "../../includes/Objects/Textbox.h"

// TODO - Resources //
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: TextBox()
Textbox::Textbox(const string nString, const Color nBackground,
                 const Vector2f nPosition)
    : text_color(black), background_color(nBackground), outline_color(black),
      textbox_position(nPosition), textbox_visible(true),
      outline_visible(false) {

  //* @note: Load standard font from resources
  if (!font.loadFromFile(_BungeeSpice)) {
    cerr << "failed to load font" << endl;
    exit(1);
  }

  //* @note: Initialize text

  //* @def: set font, string, color, character size of text component
  text.setFont(font);
  text.setString(nString);
  text.setFillColor(text_color);
  text.setCharacterSize(30);

  //* @def: set position & origin of text component
  text.setPosition(textbox_position);
  text.setOrigin(text.getGlobalBounds().width / 2.f,
                 text.getGlobalBounds().height / 1.2f);

  //* @note: Initialize background

  //* @def: set size & origin of background component
  background.setSize(
      {static_cast<float>(nString.size()) * text.getCharacterSize(),
       text.getCharacterSize() * 1.75f});
  background.setOrigin(
      {background.getSize().x / 2.f, background.getSize().y / 2.f});

  //* @def: set color, position, outline color, & outline thickness
  background.setFillColor(background_color);
  background.setPosition(textbox_position);
  background.setOutlineColor(transparent);
  background.setOutlineThickness(3.f);

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: ~TextBox()
Textbox::~Textbox() { return; }
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - Functions //
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: draw(RenderWindow&)
void Textbox::draw(RenderWindow &window) {
  if (isVisible()) {
    window.draw(background);
    window.draw(text);
  }
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: move(const Vector2f)
void Textbox::move(const Vector2f position) {
  background.move(position);
  text.move(position);
  textbox_position = position;
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: resize(const unsigned int)
void Textbox::resize(const unsigned int size) {
  //? @note: Adjust text character size & origin
  text.setCharacterSize(size);
  text.setOrigin(text.getGlobalBounds().width / 2.f,
                 text.getGlobalBounds().height / 1.2f);

  //? @note: Adjust background size & origin
  background.setSize(
      {static_cast<float>(text.getString().getSize()) * text.getCharacterSize(),
       text.getCharacterSize() * 1.75f});
  background.setOrigin(
      {background.getSize().x / 2.f, background.getSize().y / 2.f});

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: invert(void)
void Textbox::invert(void) {
  //* @note: update trackers
  Color temp = text_color;
  text_color = background_color;
  background_color = temp;

  //* @note: update objects
  text.setFillColor(text_color);
  background.setFillColor(background_color);
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - Toggles //
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleOutline(const bool)
void Textbox::toggleOutline(const bool toggle) {
  if (toggle) {
    outline_visible = true;
    background.setOutlineColor(outline_color);
  } else {
    outline_visible = false;
    background.setOutlineColor(transparent);
  }

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: toggleVisible(const bool)
void Textbox::toggleVisible(const bool toggle) {
  if (toggle) {
    textbox_visible = true;
    text.setFillColor(text_color);
    background.setFillColor(background_color);
  } else {
    textbox_visible = false;
    text.setFillColor(transparent);
    background.setFillColor(transparent);
  }

  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - Mutators //
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setPosition(const Vector2f)
void Textbox::setPosition(const Vector2f position) {
  text.setPosition(position);
  background.setPosition(position);
  textbox_position = position;
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setText(const string)
void Textbox::setText(const string nString) {
  text.setString(nString);
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setOutlineThickness(const float)
void Textbox::setOutlineThickness(const float thickness) {
  background.setOutlineThickness(thickness);
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setBackgroundColor(const Color)
void Textbox::setBackgroundColor(const Color color) {
  background.setFillColor(color);
  background_color = color;
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setTextColor(const Color)
void Textbox::setTextColor(const Color color) {
  text.setFillColor(color);
  text_color = color;
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: setOutlineColor(const Color)
void Textbox::setOutlineColor(const Color color) {
  background.setOutlineColor(color);
  return;
}
//////////////////////////////////////////////////////////////////////////////////////////

// TODO - Accessors //
//////////////////////////////////////////////////////////////////////////////////////////
//&* @public: isVisible(void)
bool Textbox::isVisible(void) {
  if (textbox_visible)
    return true;

  return false;
}
//////////////////////////////////////////////////////////////////////////////////////////
