#ifndef LEVEL_HPP
#define LEVEL_HPP

class Level {
private:
    sf::Sprite map;
public:
    void draw(sf::RenderWindow& window);
    void update();

    Level() { }
};

#endif // LEVEL_HPP