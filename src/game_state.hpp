#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.hpp"

class GameState {
  public:
    virtual ~GameState() { }

    Game* game;

    virtual void draw(const sf::Time dt) = 0;
    virtual void handleInput() = 0;
    virtual void update(const sf::Time dt) = 0;
  protected:
    sf::Sprite background;
};

#endif // GAME_STATE_HPP
