#include "item.h"

std::vector<int> healthRegen = { 5, 0, 0 };
std::vector<int> strengthBoost = { 0, 2, 0 };
std::vector<int> healthBoost = { 5, 0, 5 };

item::item()
{

}

item::~item()
{

}

void item::create()
{

}

void item::draw(sf::RenderWindow& window) 
{
	window.draw(this->_sprite);
}