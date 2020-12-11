#pragma once
#ifndef ITEM_HPP
#define ITEM_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

enum class potionType { healthRegen, strengthBoost, speedBoost };

struct potion
{
	potionType type;
	float effectValue;
};

class item
{
private:
	sf::Sprite _sprite;
	thor::Animator<sf::Sprite, std::string> _animator;

	int healthRegen;
	int strengthBoost;
	int totalHealthBoost;

public:
	item();
	~item();

	void create();
	void draw(sf::RenderWindow& window);

	sf::Sprite returnSprite() { return _sprite; };
};

#endif ITEM_HPP