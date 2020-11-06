#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

class Character() {
	private:
		sf::Sprite _sprite;
		thor::AnimationMap _animationMap;
		thor::Animator _animator;
		float _hitPoints;
		float _evasionProb;
		float _defensePoints;
		float _attackPoints;
	public:
		void draw();
		void move();
		void attack();
		void collision;
		void changeIdleType();
		void create();
		void getShape();
};