#include <SFML/Graphics.hpp>
#include <string>

#include "gui.hpp"

GuiEntry::GuiEntry(const std::string& message, sf::RectangleShape shape, sf::Texture* texNormal, sf::Texture* texHighlight, sf::Texture* texPressed)
{
  this->message = message;
  this->shape = shape;
  this->texHighlight = texHighlight;
  this->texNormal = texNormal;
  this->texPressed = texPressed;
}

Gui::Gui(sf::Vector2f dimensions, std::vector<GuiEntry> entries)
{
  this->dimensions = dimensions;
  this->entries = entries;
}

// return the message bound to the entry
std::string Gui::activate(const unsigned int entry)
{
  if (entry == (unsigned int)-1)
    return "null";

  return entries[entry].message;
}

std::string Gui::activate(sf::Vector2f mousePos)
{
  int entry = this->getEntry(mousePos);
  return this->activate(entry);
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  // draw each entry of the menu
  for (auto entry : this->entries)
    // draw the entry
    target.draw(entry.shape);

  return;
}

int Gui::getEntry(const sf::Vector2f mousePos)
{
  // if there are no entries then outside the menu
  if (entries.size() == 0)
    return -1;

  for (long unsigned int i = 0; i < this->entries.size(); ++i) {
    // translate point to use the entry's local coordinates
    sf::Vector2f point = mousePos;
    point += this->entries[i].shape.getOrigin();
    point -= this->entries[i].shape.getPosition();

    if (point.x < 0 || point.x > this->dimensions.x)
      continue;
    if (point.y < 0 || point.y > this->dimensions.y)
      continue;

    return i;
  }

  return -1;
}

// highlights an entry of the menu
void Gui::highlight(const unsigned int entry)
{
  for (long unsigned int i = 0; i < entries.size(); ++i) {
    if (i == entry)
      entries[i].shape.setTexture(entries[i].texHighlight);
    else
      entries[i].shape.setTexture(entries[i].texNormal);
  }

  return;
}

void Gui::press(const unsigned int entry)
{
  for (long unsigned int i = 0; i < entries.size(); ++i) {
    if (i == entry)
      entries[i].shape.setTexture(entries[i].texPressed);
  }

  return;
}

void Gui::release(const unsigned int entry)
{
  for(long unsigned int i = 0; i < entries.size(); ++i) {
    if (i == entry) 
      entries[i].shape.setTexture(entries[i].texHighlight);
  }

  return;
}

void Gui::show() {
  float offset = 0.0f;
  // draw each entry of the menu
  for (auto& entry : this->entries) {
    // set the origin of the entry
    sf::Vector2f origin = this->getOrigin();
    origin.y -= offset;
    entry.shape.setOrigin(origin);

    // compute the position of the entry
    entry.shape.setPosition(this->getPosition());

    offset += this->dimensions.y + 20.0f;
  }

  return;
}
