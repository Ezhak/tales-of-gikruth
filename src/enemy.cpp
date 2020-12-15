#include "enemy.hpp"
#include <iostream>

void Enemy::addFrames(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration)
{
  const int step = (xFirst < xLast) ? +1 : -1;
  xLast += step; // so xLast is excluded in the range

  for (int x = xFirst; x != xLast; x += step)
    animation.addFrame(duration, sf::IntRect(24 * x, 22 * y, 100 / 4, 50 / 2));
}

void Enemy::attack(float attackPoints, sf::Sound& sound) {
  if (this->hitPoints > 0) {
    sound.setVolume(75.f);
    sound.play();
    std::cout << this->hitPoints << " -> ";
    this->hitPoints -= attackPoints;
    std::cout << this->hitPoints << std::endl;
  }
}

bool Enemy::collides(sf::FloatRect rect)
{
  return this->sprite.getGlobalBounds().intersects(rect);
}

bool Enemy::dead() {
  return this->hitPoints <= 0;
}

void Enemy::draw(sf::RenderWindow& window)
{
  if (this->hitPoints > 0)
    window.draw(this->sprite);
}

void Enemy::flip()
{
  this->sprite.setScale(sf::Vector2f(-1, 1));
}

void Enemy::idle()
{
  if (!this->animator.isPlayingAnimation() || this->animator.getPlayingAnimation() != "idle")
    this->animator.playAnimation("idle");
}

void Enemy::initAnimation()
{
  // define idle animation
  thor::FrameAnimation idle;
  addFrames(idle, 0, 0, 1);

  // register animations with their corresponding durations
  this->animator.addAnimation("idle", idle, sf::seconds(0.7f));
}

void Enemy::injure(Character& player, sf::Sound& sound)
{
  if (this->hitPoints > 0) {
    player.injure(this->attackPoints, sound);
  }
}

void Enemy::update(const sf::Time dt)
{
  this->animator.update(dt);
  this->animator.animate(this->sprite);
}

