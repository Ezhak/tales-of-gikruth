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
    std::vector<int> vectorScores;
    std::map<std::string, Gui> guiSystem;
    sf::Font font;
    sf::Text text;
    Character _playerScore;
public:
    GameStateHighscore(Game* game);
    ~GameStateHighscore();

    bool readFromDisk(int position);

    void chooseclass();

    Character getCharacter() { return _playerScore; };

    std::vector<int> getVector() { return vectorScores; };

    virtual void handleInput();
    virtual void update(const sf::Time dt);
    virtual void draw(const sf::Time dt);
};

#endif // GAME_STATE_HIGHSCORE_HPP