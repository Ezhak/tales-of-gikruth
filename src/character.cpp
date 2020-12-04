#include "character.hpp"
#include <iostream>

void Character::update(const sf::Time dt) {
	this->_animator.update(dt);
	this->_animator.animate(this->_sprite);
}

void Character::draw(sf::RenderWindow& window) {
	window.draw(this->_sprite);
}

void Character::create() {
	// Define idle animation
	thor::FrameAnimation idle;
	addFrames(idle, 0, 0, 1);

	// Define walk animation
	thor::FrameAnimation walk;
	addFrames(walk, 1, 0, 3);

	// Register animations with their corresponding durations
	this->_animator.addAnimation("walk", walk, sf::seconds(0.3f));
	this->_animator.addAnimation("idle", idle, sf::seconds(0.7f));
}

void Character::addFrames(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration) {
	const int step = (xFirst < xLast) ? +1 : -1;
	xLast += step; // so xLast is excluded in the range

	for (int x = xFirst; x != xLast; x += step)
		animation.addFrame(duration, sf::IntRect(24 * x, 22 * y, 96 / 4, 44 / 2));
}

void Character::idle() {
	if (!this->_animator.isPlayingAnimation() ||
			 this->_animator.getPlayingAnimation() != "idle")
  	this->_animator.playAnimation("idle");
}

void Character::move(movement_type direction) {
	if (!this->_animator.isPlayingAnimation() ||
		   this->_animator.getPlayingAnimation() != "walk")
		this->_animator.playAnimation("walk");

	switch (direction) {
		case movement_type::UP:
			this->_sprite.move(0.0f, -this->_velocity);
			break;
		case movement_type::DOWN:
			this->_sprite.move(0.0f, this->_velocity);
			break;
		case movement_type::LEFT:
			// Mirror
			if (this->_sprite.getScale().x > 0)
				this->_sprite.scale(-1,1);
			this->_sprite.move(-this->_velocity, 0.0f);
			break;
		case movement_type::RIGHT:
			// Unmirror
			if (this->_sprite.getScale().x < 0)
				this->_sprite.scale(-1,1);
			this->_sprite.move(this->_velocity, 0.0f);
			break;
		default:
			break;
	}
}

void Character::attack() {
}

void Character::leftCollision() {
	sf::Vector2f posicionActualPlayer = _sprite.getPosition();
	_sprite.setPosition(posicionActualPlayer.x - 1, posicionActualPlayer.y);
}

void Character::rightCollision() {
	sf::Vector2f posicionActualPlayer = _sprite.getPosition();
	_sprite.setPosition(posicionActualPlayer.x + 1, posicionActualPlayer.y);
}

void Character::upCollision() {
	sf::Vector2f posicionActualPlayer = _sprite.getPosition();
	_sprite.setPosition(posicionActualPlayer.x, posicionActualPlayer.y - 1);
}

void Character::downCollision() {
	sf::Vector2f posicionActualPlayer = _sprite.getPosition();
	_sprite.setPosition(posicionActualPlayer.x, posicionActualPlayer.y + 1);
}

void Character::changeIdleType() {
}
