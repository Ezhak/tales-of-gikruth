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

	float _hitPoints;
	float _evasionProb;
	float _defensePoints;
	float _attackPoints;
	float _velocity = 1.f;
public:
	Enemy() {}
	Enemy(sf::Sprite& sprite) { this->_sprite = sprite; }

	void update(const sf::Time dt);
	void draw(sf::RenderWindow& window);

	void create();
	void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
	void idle();
	void move();
	void attack();
	void collision();
};

#endif // ENEMY_HPP