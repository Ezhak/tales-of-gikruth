#include "boss.hpp"

Boss::Boss(sf::Texture& texture) : Enemy(texture)
{
  this->attackPoints = 8.f;
  this->defensePoints = 6.f;
  this->hitPoints = 48.f;
}

void Boss::addFrames(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration)
{
	const int step = (xFirst < xLast) ? +1 : -1;
	xLast += step; // so xLast is excluded in the range

  for (int x = xFirst; x != xLast; x += step)
    animation.addFrame(duration, sf::IntRect(34 * x, 34 * y, 120 / 4, 70 / 2));
}

void Boss::initAnimation()
{
	// define idle animation
	thor::FrameAnimation idle;
	addFrames(idle, 0, 0, 1);

	// register animations with their corresponding durations
	this->animator.addAnimation("idle", idle, sf::seconds(0.7f));
}
