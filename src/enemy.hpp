#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

class Character;
#include "character.hpp"
#include "potion.hpp"

class Enemy {
public:
  Enemy() {}
  Enemy(sf::Texture& texture) { this->sprite = sf::Sprite(texture); }

  bool getDropped() { return this->dropped; }
  sf::Vector2f getPosition() { return this->sprite.getPosition(); }
  sf::Sprite getSprite() { return this->sprite; }
  void setDropped() { this->dropped = true; }
  void setOrigin(float x, float y) { this->sprite.setOrigin(x, y); }
  void setPosition(float x, float y) { this->sprite.setPosition(x, y); }
  
  void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
  void attack(float attackPoints, sf::Sound& sound);
  bool collides(sf::FloatRect rect);
  bool dead();
  void draw(sf::RenderWindow& window);
  void flip();
  void idle();
  void initAnimation();
  void injure(Character& player, sf::Sound& sound);
  void update(const sf::Time dt);
protected:
  thor::Animator<sf::Sprite, std::string> animator;
  float attackPoints = 4.f;
  float defensePoints = 4.f;
  bool dropped = false;
  float hitPoints = 16.f;
  sf::Sprite sprite;
};

#endif // ENEMY_HPP
