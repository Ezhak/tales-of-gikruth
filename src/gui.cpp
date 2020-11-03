#include <SFML/Graphics.hpp>
#include <string>

#include "gui.hpp"

sf::Vector2f Gui::getSize() {
    return sf::Vector2f(this->dimensions.x, this->dimensions.y * this->entries.size());
}

int Gui::getEntry(const sf::Vector2f mousePos) {
    // If there are no entries then outside the menu
    if(entries.size() == 0)
        return -1;

    for(int i = 0; i < this->entries.size(); ++i) {
        // Translate point to use the entry's local coordinates
        sf::Vector2f point = mousePos;
        point += this->entries[i].shape.getOrigin();
        point -= this->entries[i].shape.getPosition();

        if(point.x < 0 || point.x > this->entries[i].shape.getScale().x*this->dimensions.x)
            continue;
        if(point.y < 0 || point.y > this->entries[i].shape.getScale().y*this->dimensions.y)
            continue;

        return i;
    }

    return -1;
}

void Gui::setDimensions(sf::Vector2f dimensions)
{
    this->dimensions = dimensions;

    for(auto& entry : entries)
        entry.shape.setSize(dimensions);

    return;
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Draw each entry of the menu
    for(auto entry : this->entries)
        // Draw the entry
        target.draw(entry.shape);

    return;
}

void Gui::show()
{
    float offset = 0.0f;
    // Draw each entry of the menu
    for(auto& entry : this->entries) {
        // Set the origin of the entry
        sf::Vector2f origin = this->getOrigin();
        origin.y -= offset;
        entry.shape.setOrigin(origin);

        // Compute the position of the entry
        entry.shape.setPosition(this->getPosition());

        offset += this->dimensions.y + 20.0f;
    }

    return;
}

// Highlights an entry of the menu
void Gui::highlight(const int entry) {
    for(int i = 0; i < entries.size(); ++i) {
        if(i == entry)
            entries[i].shape.setTexture(entries[i].texHighlight);
        else
            entries[i].shape.setTexture(entries[i].texNormal);
    }

    return;
}

void Gui::press(const int entry) {
    for(int i = 0; i < entries.size(); ++i) {
        if(i == entry)
            entries[i].shape.setTexture(entries[i].texPressed);
    }

    return;
}

void Gui::release(const int entry) {
    for(int i = 0; i < entries.size(); ++i) {
        if(i == entry) 
            entries[i].shape.setTexture(entries[i].texHighlight);
    }

    return;
}

// Return the message bound to the entry
std::string Gui::activate(const int entry) {
    if(entry == -1)
        return "null";

    return entries[entry].message;
}

std::string Gui::activate(sf::Vector2f mousePos) {
    int entry = this->getEntry(mousePos);
    return this->activate(entry);
}
