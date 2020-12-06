#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

class Enemy
{
private:
	sf::Sprite _sprite;
	thor::Animator<sf::Sprite, std::string> _animator;

	float _hitPoints = 15.f;
	float _evasionProb;
	float _defensePoints = 3.f;
	float _attackPoints = 4.f;
	float _velocity = 1.f;
public:
	Enemy() {}
	Enemy(sf::Sprite& sprite) { this->_sprite = sprite; }

	void update(const sf::Time dt);
	void draw(sf::RenderWindow& window);

	void create();
	void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
	void idle();
	void setHealth(float attackPoints);

	sf::Sprite getSprite() { return _sprite; };
	float getHealth() { return _hitPoints; };
	float getAttackPoints() { return _attackPoints; };
};

#endif // ENEMY_HPP