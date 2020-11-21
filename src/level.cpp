#include <SFML/Graphics.hpp>

#include "level.hpp"

void Level::draw(sf::RenderWindow& window) {
    window.draw(this->_sprite);
}
