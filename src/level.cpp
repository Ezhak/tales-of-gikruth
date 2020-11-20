#include <SFML/Graphics.hpp>

#include "level.hpp"

void Level::draw(sf::RenderWindow& window) {
    window.draw(this->map);
}

sf::Sprite& Level::getMap() {
    return this->map;
}

void Level::setMap(sf::Texture& map) {
    this->map.setTexture(map);
}