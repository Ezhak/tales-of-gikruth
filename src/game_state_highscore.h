#ifndef GAME_STATE_HIGHSCORE_HPP
#define GAME_STATE_HIGHSCORE_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "game_state.hpp"
#include "game_state_start.hpp"
#include "gui.hpp"

class GameStateHighscore : public GameState
{
private:
    sf::View view;

    std::map<std::string, Gui> guiSystem;
public:
    GameStateHighscore(Game* game);
    ~GameStateHighscore();

    void chooseclass();

    virtual void handleInput();
    virtual void update(const sf::Time dt);
    virtual void draw(const sf::Time dt);
};

#endif // GAME_STATE_HIGHSCORE_HPP