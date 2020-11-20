#ifndef LEVEL_HPP
#define LEVEL_HPP

class Level {
private:
    sf::Sprite map;
public:
    void draw(sf::RenderWindow& window);
    void update();

    sf::Sprite& getMap();
    void setMap(sf::Texture&);

    Level() { }
};

#endif // LEVEL_HPP