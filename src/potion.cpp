#include "potion.hpp"
#include <iostream>

Potion::Potion(sf::Texture& texture, potionType type)
{
  this->type = type;
  this->sprite = sf::Sprite(texture);
}

void Potion::addFrames(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration)
{
  const int step = (xFirst < xLast) ? +1 : -1;
  xLast += step; // so xLast is excluded in the range

  for (int x = xFirst; x != xLast; x += step)
    animation.addFrame(duration, sf::IntRect(10 * x, 20 * y, 20 / 2, 11));
}

bool Potion::collides(sf::FloatRect rect)
{
  return this->sprite.getGlobalBounds().intersects(rect);
}

void Potion::pick() {
  this->picked = true;
}

void Potion::draw(sf::RenderWindow& window)
{
  if (!this->picked)
    window.draw(this->sprite);
}

void Potion::effect(Character& player) {
  player.effect(this->type, this->effectValue);
}

void Potion::idle()
{
  // if (!this->animator.isPlayingAnimation() || this->animator.getPlayingAnimation() != "idle")
  // this->animator.playAnimation("idle");
}

void Potion::initAnimation()
{
  // define idle animation
  thor::FrameAnimation idle;
  addFrames(idle, 0, 0, 1, 1.f);

  // register animations with their corresponding durations
  this->animator.addAnimation("idle", idle, sf::seconds(0.7f));
}

void Potion::update(const sf::Time dt)
{
  // this->animator.update(dt);
  // this->animator.animate(this->sprite);
}

