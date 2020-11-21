#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.hpp"

class GameState {
  protected:
	  sf::Sprite background;
  public:
    Game* game;

    virtual void handleInput() = 0;
    virtual void update(const sf::Time dt) = 0;
    virtual void draw(const sf::Time dt) = 0;
};

#endif // GAME_STATE_HPP
