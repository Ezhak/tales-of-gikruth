#include "character.hpp"

void Character::draw() {

}

void Character::move() {

}

void Character::attack() {

}

void Character::collision() {

}

void Character::changeIdleType() {

}

void Character::addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration) {
	duration = 1.f;
	const int step = (yFirst < yLast) ? +1 : -1;
	yLast += step; // so yLast is excluded in the range

	for (int y = yFirst; y != yLast; y += step)
		animation.addFrame(duration, sf::IntRect(16 * x, 16 * y, 60 / 4, 81 / 3));
}

void Character::create() {

	// Load image that contains animation steps
	sf::Image image;
	if (!image.loadFromFile("assets/pj.png"))
		return;
	image.createMaskFromColor(sf::Color::White);

	// Create texture based on sf::Image
	sf::Texture texture;
	if (!texture.loadFromImage(image))
		return;

	// Create sprite which is animated
	sf::Sprite sprite(texture);
	sprite.setPosition(100.f, 100.f);

	// Define walk animation
	thor::FrameAnimation walk;
	addFrames(walk, 0, 2, 2, 1.f);
	addFrames(walk, 1, 2, 2, 1.f);
	addFrames(walk, 2, 2, 2, 1.f);
	addFrames(walk, 3, 2, 2, 1.f);

	// Define static frame for stand animation
	thor::FrameAnimation idle;
	addFrames(idle, 0, 0, 0, 1.f);
	addFrames(idle, 1, 0, 0, 1.f);

	// Register animations with their corresponding durations
	thor::Animator<sf::Sprite, std::string> animator;
	animator.addAnimation("walk", walk, sf::seconds(1.f));
	animator.addAnimation("idle", idle, sf::seconds(1.f));

}

sf::Sprite Character::getShape() {
	return _sprite;
}
