#include "item.h"



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