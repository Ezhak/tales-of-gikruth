#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
    }
    std::vector<sf::RectangleShape>vectorCollisions; //
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
    void setVector(std::vector<sf::RectangleShape> vector) { vectorCollisions = vector; }; //
    std::vector<sf::RectangleShape>getVector() { return vectorCollisions; }; //

};

