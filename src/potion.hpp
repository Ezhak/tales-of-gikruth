#ifndef POTION_HPP
#define POTION_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

class Character;
#include "character.hpp"

enum class potionType { regen, strength, speed };

class Potion {
  public:
    Potion() {}
    Potion(sf::Texture& texture, potionType type);

    sf::Sprite getSprite() { return sprite; }
    void setEffectValue(float value) { this->effectValue = value; }
    void setOrigin(float x, float y) { this->sprite.setOrigin(x, y); }
    void setPosition(float x, float y) { this->sprite.setPosition(x, y); }

    void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
    bool collides(sf::FloatRect rect);
    void draw(sf::RenderWindow& window);
    void effect(Character& player);
    void idle();
    void initAnimation();
    void pick();
    void update(const sf::Time dt);

  protected:
    thor::Animator<sf::Sprite, std::string> animator;
    float effectValue;
    bool picked = false;
    potionType type;
    sf::Sprite sprite;
};

#endif // POTION_HPP
