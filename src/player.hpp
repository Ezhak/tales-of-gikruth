#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>
#include "character.hpp"

class Player : public Character{
public:
	Player() {};
	Player(Character character, sf::Vector2f position) {
	
	};
	Player(Character character, sf::Vector2f position ,float velocity) {
		
	};
	//change_character() {};
};

#endif // PLAYER_HPP