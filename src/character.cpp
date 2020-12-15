#include "character.hpp"
#include <iostream>

Character::Character(sf::Texture& texture) {
  this->sprite = sf::Sprite(texture);
  this->walkSoundBuffer.loadFromFile("assets/sound/walk.wav");
}

sf::FloatRect Character::getCollisionRect()
{
  sf::FloatRect collisionRect = this->sprite.getGlobalBounds();

  // Reduce boundary height to prevent head overlap
  collisionRect.height /= 4;
  collisionRect.top += (collisionRect.height * 3);

  collisionRect.width /= 3;
  collisionRect.left += collisionRect.width;

  return collisionRect;
}

void Character::addFrames(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration)
{
  const int step = (xFirst < xLast) ? +1 : -1;
  xLast += step; // so xLast is excluded in the range

  for (int x = xFirst; x != xLast; x += step)
    animation.addFrame(duration, sf::IntRect(24 * x, 22 * y, 96 / 4, 44 / 2));
}

void Character::attack(Enemy& enemy, sf::Sound& sound)
{
  enemy.attack(this->attackPoints, sound);
}

bool Character::collides(Enemy& enemy)
{
  return enemy.collides(this->getCollisionRect());
}

bool Character::collides(Potion& potion)
{
  return potion.collides(this->getCollisionRect());
}

bool Character::collides(sf::FloatRect rect)
{
  return this->getCollisionRect().intersects(rect);
}

bool Character::collides(sf::FloatRect rect, movement_type movementType)
{
  sf::FloatRect futureRect = this->getCollisionRect();

  switch (movementType) {
  case movement_type::UP:
    futureRect.top -= this->velocity;
    break;
  case movement_type::DOWN:
    futureRect.top += this->velocity;
    break;
  case movement_type::LEFT:
    futureRect.left -= this->velocity;
    break;
  case movement_type::RIGHT:
    futureRect.left += this->velocity;
    break;
  case movement_type::IDLE:
    break;
  default:
    break;
  }

  return rect.intersects(futureRect);
}

bool Character::dead()
{
  return this->hitPoints <= 0.f;
}

void Character::draw(sf::RenderWindow& window)
{
  window.draw(this->sprite); 
}

void Character::effect(potionType type, float effectValue)
{
  switch(type) {
  case potionType::regen:
    this->hitPoints += effectValue;
    break;
  case potionType::speed:
    this->velocity = effectValue;
    break;
  case potionType::strength:
    this->attackPoints += effectValue;
    break;
  default:
    break;
  }
}

void Character::idle()
{
  this->walking = false;

  if (!this->animator.isPlayingAnimation() || this->animator.getPlayingAnimation() != "idle")
    this->animator.playAnimation("idle");
}

void Character::initAnimation()
{
  // define idle animation
  thor::FrameAnimation idle;
  addFrames(idle, 0, 0, 1);

  // define walk animation
  thor::FrameAnimation walk;
  addFrames(walk, 1, 0, 3);

  // register animations with their corresponding durations
  this->animator.addAnimation("walk", walk, sf::seconds(0.3f));
  this->animator.addAnimation("idle", idle, sf::seconds(0.7f));
}

void Character::injure(float attackPoints, sf::Sound& sound)
{
  std::cout << hitPoints << std::endl;
  sound.setVolume(75.f);
  sound.play();
  this->hitPoints -= attackPoints;
}

void Character::move(movement_type direction)
{
  this->walking = true;

  if (!this->animator.isPlayingAnimation() || this->animator.getPlayingAnimation() != "walk")
    this->animator.playAnimation("walk");

  switch (direction) {
    case movement_type::UP:
      this->sprite.move(0.0f, -this->velocity);
      break;
    case movement_type::DOWN:
      this->sprite.move(0.0f, this->velocity);
      break;
    case movement_type::LEFT:
      // Mirror
      if (this->sprite.getScale().x > 0)
        this->sprite.scale(-1,1);
      this->sprite.move(-this->velocity, 0.0f);
      break;
    case movement_type::RIGHT:
      // Unmirror
      if (this->sprite.getScale().x < 0)
        this->sprite.scale(-1,1);
      this->sprite.move(this->velocity, 0.0f);
      break;
    default:
      break;
  }
}

void Character::update(const sf::Time dt)
{
  this->animator.update(dt);
  this->animator.animate(this->sprite);

  this->timeElapsed += (float)dt.asSeconds();
  if (this->walking && timeElapsed > 0.3f) {
    this->sound.setBuffer(this->walkSoundBuffer);
    this->sound.setVolume(75.f);
    this->sound.play();
    this->timeElapsed = 0.f;
  }
}
