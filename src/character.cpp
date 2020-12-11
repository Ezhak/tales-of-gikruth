#include "character.hpp"
#include <iostream>

std::map<playerSpriteName, std::string> Character::playerSpritesFile
{
	{ playerSpriteName::dragon, "dragon"},
	{ playerSpriteName::mage, "mage"},
	{ playerSpriteName::knight, "knight"},
};

void Character::update(const sf::Time dt) {
	this->_animator.update(dt);
	this->_animator.animate(this->_sprite);
}

void Character::draw(sf::RenderWindow& window) 
{
	window.draw(this->_sprite);
}

void Character::burnDisk()
{
	FILE* fp;
	fopen_s(&fp, "score.dat", "ab");
	if (!fp) {
		std::cout << "File score.dat error" << std::endl;
		fclose(fp);
	}
	fwrite(this, sizeof this, 1, fp);
	if (ferror(fp)) {
		std::cout << "File burn score.dat error" << std::endl;
		fclose(fp);
		return;
	}
	fclose(fp);
}

bool Character::readFromDisk(int position)
{
	int x;
	FILE* fp;
	fopen_s(&fp, "score.dat", "rb");
	if (!fp) {
		std::cout << "Error to open file score.dat" << std::endl;
		fclose(fp);
		return false;
	}

	fseek(fp, sizeof * this * position, 0);
	x = fread(this, sizeof this, 1, fp);
	fclose(fp);
	if (x == 1) return true;
	return false;
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

void Character::setHealth(float attackPoints)
{
	if (this->_hitPoints > 0)
		this->_hitPoints -= attackPoints;
}

void Character::setScore()
{
	_score += 100;
}

void Character::addTotalStrength(float value)
{
	this->_defensePoints += value;
}

void Character::addHealth(float value)
{
	this->_hitPoints += value;
}

void Character::addVelocity(float value)
{
	this->_velocity += value;
}