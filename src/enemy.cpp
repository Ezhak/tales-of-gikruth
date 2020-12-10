#include "enemy.hpp"
#include <iostream>

std::map<enemySpriteName, std::string> Enemy::enemySpritesFile 
{
	{enemySpriteName::tinyzombie , "tinyzombie"},
	{enemySpriteName::tinyorc, "tinyorc"},
	{enemySpriteName::tinydemon , "tinydemon"},
	{enemySpriteName::skelly , "skelly"},
	{enemySpriteName::orc , "orc"},
	{enemySpriteName::demon , "demon"},
	{enemySpriteName::bossorc , "bossorc"},
	{enemySpriteName::bossdemon , "bossdemon"},
};

void Enemy::update(const sf::Time dt) {
	this->_animator.update(dt);
	this->_animator.animate(this->_sprite);
}

void Enemy::draw(sf::RenderWindow& window) {
		window.draw(this->_sprite);
}

void Enemy::create() {
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

void Enemy::createBoss() {
	// Define idle animation
	thor::FrameAnimation idle;
	addFramesBoss(idle, 0, 0, 1);

	// Define walk animation
	thor::FrameAnimation walk;
	addFramesBoss(walk, 1, 0, 3);

	// Register animations with their corresponding durations
	this->_animator.addAnimation("walk", walk, sf::seconds(0.3f));
	this->_animator.addAnimation("idle", idle, sf::seconds(0.7f));
}

void Enemy::addFrames(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration) {
	const int step = (xFirst < xLast) ? +1 : -1;
	xLast += step; // so xLast is excluded in the range

	for (int x = xFirst; x != xLast; x += step)
		animation.addFrame(duration, sf::IntRect(24 * x, 22 * y, 100 / 4, 50 / 2));
}

void Enemy::addFramesBoss(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration) {
	const int step = (xFirst < xLast) ? +1 : -1;
	xLast += step; // so xLast is excluded in the range

	for (int x = xFirst; x != xLast; x += step)
		animation.addFrame(duration, sf::IntRect(34 * x, 34 * y, 120 / 4, 70 / 2));
}

void Enemy::idle() {
	if (!this->_animator.isPlayingAnimation() ||
		this->_animator.getPlayingAnimation() != "idle")
		this->_animator.playAnimation("idle");
}

void Enemy::setHealth(float attackPoints)
{ 
	if (this-> _hitPoints > 0)
		this-> _hitPoints -= attackPoints;
}

void Enemy::setStatus(healthStatus status)
{
	this->_status = status;
}