#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

class Character {
private:
	sf::Sprite _sprite;
	thor::AnimationMap _animationMap;
	thor::Animator<sf::Sprite, std::string> _animator;
	float _hitPoints;
	float _evasionProb;
	float _defensePoints;
	float _attackPoints;
public:
	void draw();
	void move();
	void attack();
	void collision();
	void changeIdleType();
	void create();
	sf::Sprite getShape();
};

#endif // CHARACTER_HPP