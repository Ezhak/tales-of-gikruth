#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "game_state.hpp"
#include "gui.hpp"

class GameStateStart : public GameState {
  private:
    sf::View view;

    std::map<std::string, Gui> guiSystem;

    void startgame();
  public:
    GameStateStart(Game* game);
    ~GameStateStart();

    virtual void handleInput();
    virtual void update(const sf::Time dt);
    virtual void draw(const sf::Time dt);
};

#endif // GAME_STATE_START_HPP
