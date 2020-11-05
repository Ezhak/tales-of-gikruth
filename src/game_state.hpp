#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.hpp"

class GameState {
protected:
	sf::Sprite background;
public:
    Game* game;

    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;

    void setBackground(sf::Texture& texture) {
        this->background.setTexture(texture);
    }
};

#endif // GAME_STATE_HPP
