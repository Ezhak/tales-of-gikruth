#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

enum class movement_type { IDLE, UP, DOWN, LEFT, RIGHT };

class Character {
private:
	sf::Sprite _sprite;
	thor::Animator<sf::Sprite, std::string> _animator;
	float _hitPoints;
	float _evasionProb;
	float _defensePoints;
	float _attackPoints;
	float _velocity;
public:
	void draw();
	void move(movement_type direction);
	void attack();
	void collision();
	void changeIdleType();
	void create();
	void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration);
	sf::Sprite getShape();
};

#endif // CHARACTER_HPP