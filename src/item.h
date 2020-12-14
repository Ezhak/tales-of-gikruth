#pragma once
#ifndef ITEM_HPP
#define ITEM_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

enum class potionType { healthRegen, strengthBoost, speedBoost };
enum class pickUpState { pickedUp, notPickedUp };

class item
{
private:
	sf::Sprite _sprite;
	thor::Animator<sf::Sprite, std::string> _animator;

	potionType type;
	float effectValue;
	float dropChance;

public:
	static std::map<potionType, std::string> itemSpriteFile;

	item() {};
	item(sf::Sprite sprite) { this->_sprite = sprite; };

	void update(const sf::Time dt);
	void create();
	void addFrames(thor::FrameAnimation& animation, int y, int xFirst, int xLast, float duration);
	void playIdle();
	void draw(sf::RenderWindow& window);

	void setEffectValue(float value) { this->effectValue = value; }
	void setDropChance(float value) { this->dropChance = value; }

	sf::Sprite returnSprite() { return this->_sprite; }
	potionType getType() { return this->type; }
	float getEffectValue() { return this->effectValue; }
	float getDropChance() { return this->dropChance; }
};

#endif ITEM_HPP