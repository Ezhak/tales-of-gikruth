#ifndef LEVEL_HPP
#define LEVEL_HPP

class Level {
  private:
    sf::Sprite _sprite;
  public:
    Level() {}
    Level(sf::Sprite& sprite) { this->_sprite = sprite; }

    void draw(sf::RenderWindow& window);
    void update();
};

#endif // LEVEL_HPP