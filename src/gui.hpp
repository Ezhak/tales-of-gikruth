#ifndef GUI_HPP
#define GUI_HPP

#include <vector>
#include <utility>
#include <string>
#include <cstdarg>

class GuiEntry {
public:
    // Handles appearance of the entry
    sf::RectangleShape shape;
    sf::Texture* texHighlight;
    sf::Texture* texNormal;
    sf::Texture* texPressed;

    // String returned when the entry is activated
    std::string message;

    GuiEntry(const std::string& message, sf::RectangleShape shape,
             sf::Texture* texNormal, sf::Texture* texHighlight, sf::Texture* texPressed) {
        this->message = message;
        this->shape = shape;
        this->texHighlight = texHighlight;
        this->texNormal = texNormal;
        this->texPressed = texPressed;
    }

    GuiEntry() { }
};

class Gui : public sf::Transformable, public sf::Drawable {
private:
    sf::Vector2f dimensions;
    std::vector<GuiEntry> entries;

public:
    // Constructor
    Gui(sf::Vector2f dimensions, std::vector<GuiEntry> entries) {
        this->dimensions = dimensions;
        this->entries = entries;
    }

    // Return the entry that the mouse is hovering over. Returns
    // -1 if the mouse if outside of the Gui
    int getEntry(const sf::Vector2f mousePos);

    // Draw the menu
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void show();

    // Highlights an entry of the menu
    void highlight(const int entry);

    // Presses an entry of the menu
    void press(const int entry);
    void release(const int entry);

    // Return the message bound to the entry
    std::string activate(const int entry);
    std::string activate(const sf::Vector2f mousePos);
};

#endif // GUI_HPP
