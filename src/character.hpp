#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

class Enemy;
#include "enemy.hpp"
class Potion;
enum class potionType;
#include "potion.hpp"

enum class movement_type { IDLE, UP, DOWN, LEFT, RIGHT };

class Character {
  public:
    Character() { }
    Character(sf::Texture& texture);

    sf::FloatRect getCollisionRect();
    sf::Sprite getSprite() { return sprite; }
    float getVelocity() { return velocity; }
    void setOrigin(float x, float y) { this->sprite.setOrigin(x, y); }
    void setPosition(float x, float y) { this->sprite.setPosition(x, y); }

    void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
    void attack(Enemy& enemy, sf::Sound& sound);
    bool collides(Enemy& enemy);
    bool collides(Potion& potion);
    bool collides(sf::FloatRect rect);
    bool collides(sf::FloatRect rect, movement_type movementType);
    bool dead();
    void draw(sf::RenderWindow& window);
    void effect(potionType type, float effectValue);
    void idle();
    void initAnimation();
    void injure(float attackPoints, sf::Sound& sound);
    void move(movement_type direction);
    void update(const sf::Time dt);
  private:
    thor::Animator<sf::Sprite, std::string> animator;
    float attackPoints = 2.f;
    float defensePoints = 2.f;
    float hitPoints = 20.f;
    sf::Sound sound;
    sf::Sprite sprite;
    float seconds = 0.f;
    float timeElapsed = 0.f;
    float velocity = 1.f;
    bool walking;
    sf::SoundBuffer walkSoundBuffer;
};

#endif // CHARACTER_HPP
