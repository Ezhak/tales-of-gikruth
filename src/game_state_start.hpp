#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include <map>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "game_state.hpp"
#include "gui.hpp"

class GameStateStart : public GameState {
  public:
    GameStateStart(Game* game);
    virtual ~GameStateStart() { }

    virtual void draw(const sf::Time dt);
    virtual void handleInput();
    virtual void update(const sf::Time dt);
  private:
    void hiscores();
    void startgame();

    sf::SoundBuffer clickSoundBuffer;
    std::map<std::string, Gui> guiSystem;
    sf::Music startTheme;
    sf::Sound sound;
    sf::View view;
};

#endif // GAME_STATE_START_HPP
