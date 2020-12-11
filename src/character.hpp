#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

enum class movement_type { IDLE, UP, DOWN, LEFT, RIGHT };
enum class playerSpriteName { dragon, knight, mage };

class Character {
	private:
		sf::Sprite _sprite;
		thor::Animator<sf::Sprite, std::string> _animator;

		float _hitPoints = 20.f;
		float _defensePoints = 2.f;
		float _attackPoints = 2.f;
		float _velocity = 1.f;

		int _score = 0;

	public:
		static std::map<playerSpriteName, std::string> playerSpritesFile;

		Character() {};
		Character(sf::Sprite& sprite) { this->_sprite = sprite; }

		void update(const sf::Time dt);
		void draw(sf::RenderWindow& window);

		void burnDisk();
		bool readFromDisk(int position);

		void create();
		void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
		void idle();
		void move(movement_type direction);
		void setHealth(float attackPoints);
		void setScore();

		float getVelocity() { return _velocity; };
		float getAttackPoints() { return _attackPoints; };
		float getHealth() { return _hitPoints; };
		sf::Sprite getSprite() { return _sprite; };
		int getScore() { return _score; };
};

#endif // CHARACTER_HPP