#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <Thor/Animations.hpp>

class Entity {
    
    public:
        sf::Sprite sprite;
        thor::Animator<sf::Sprite, std::string> animator;
        void draw();

};

#endif // ENTITY_HPP