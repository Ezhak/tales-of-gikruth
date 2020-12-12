#include "item.h"

std::map<potionType, std::string> item::itemSpriteFile
{
	{ potionType::healthRegen, "health_potion" },
	{ potionType::strengthBoost, "strength_potion" },
	{ potionType::speedBoost, "speed_potion" },
};

void item::update(const sf::Time dt) {
	this->_animator.update(dt);
	this->_animator.animate(this->_sprite);
}

void item::create()
{
	//Define idleSpin animation
	thor::FrameAnimation idleSpin;
	addFrames(idleSpin, 0, 0, 1, 1.0f);

	//Register animations with durations
	this->_animator.addAnimation("idleSpin", idleSpin, sf::seconds(0.3f));

}

void item::addFrames(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration) {
	const int step = (xFirst < xLast) ? +1 : -1;
	xLast += step; // so xLast is excluded in the range

	for (int x = xFirst; x != xLast; x += step)
		animation.addFrame(duration, sf::IntRect(10 * x, 20 * y, 20 / 2, 11));
}

void item::playIdle()
{
	this->_animator.playAnimation("idleSpin");
}

void item::draw(sf::RenderWindow& window) 
{
	window.draw(this->_sprite);
}