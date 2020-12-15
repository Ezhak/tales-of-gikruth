#ifndef GUI_HPP
#define GUI_HPP

#include <vector>
#include <utility>
#include <string>
#include <cstdarg>

class GuiEntry {
  public:
    GuiEntry() { }
    GuiEntry(const std::string& message, sf::RectangleShape shape, sf::Texture* texNormal, sf::Texture* texHighlight, sf::Texture* texPressed);

    // message to return when activated
    std::string message;

    // handles the appearance
    sf::RectangleShape shape;
    sf::Texture* texHighlight;
    sf::Texture* texNormal;
    sf::Texture* texPressed;
};

class Gui : public sf::Transformable, public sf::Drawable {
  public:
    Gui(sf::Vector2f dimensions, std::vector<GuiEntry> entries);

    // return the message bound to the entry
    std::string activate(const unsigned int entry);
    std::string activate(const sf::Vector2f mousePos);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    // return the entry that the mouse is hovering over
    // -1 if the mouse if outside of the Gui
    int getEntry(const sf::Vector2f mousePos);
    // highlights an entry of the menu
    void highlight(const unsigned int entry);
    // presses an entry of the menu
    void press(const unsigned int entry);
    void release(const unsigned int entry);
    void show();
  private:
    sf::Vector2f dimensions;
    std::vector<GuiEntry> entries;
};

#endif // GUI_HPP
