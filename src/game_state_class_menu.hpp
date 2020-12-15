#ifndef GAME_STATE_CLASS_MENU_HPP
#define GAME_STATE_CLASS_MENU_HPP

#include <map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "game_state.hpp"
#include "game_state_start.hpp"
#include "gui.hpp"

class GameStateClassMenu : public GameState {
  public:
    GameStateClassMenu(Game* game, sf::Music* theme);
    virtual ~GameStateClassMenu() { }

    virtual void draw(const sf::Time dt);
    virtual void handleInput();
    virtual void update(const sf::Time dt);
  private:
    void startgame(std::string className);

    std::map<std::string, Gui> guiSystem;
    sf::Music* startTheme;
    sf::Sound sound;
    sf::SoundBuffer spawnSoundBuffer;
    sf::View view;
};

#endif // GAME_STATE_CLASS_MENU_HPP
