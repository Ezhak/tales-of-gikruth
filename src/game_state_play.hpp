#ifndef GAME_STATE_PLAY_HPP
#define GAME_STATE_PLAY_HPP

#include <map>
#include <SFML/System.hpp>
#include <string>

#include "game_state.hpp"
#include "gui.hpp"
#include "level.hpp"

class GameStatePlay : public GameState {
  public:
    GameStatePlay(Game* game, std::string className);
    virtual ~GameStatePlay() { }

    virtual void draw(const sf::Time dt);
    virtual void handleInput();
    void initLevel(sf::Vector2f position, std::string className);
    void nextLevel();
    virtual void update(const sf::Time dt);
  private:
    sf::SoundBuffer attackSoundBuffer;
    std::string className;
    sf::View gameView;
    sf::View guiView;
    std::map<std::string, Gui> guiSystem;
    Level level;
    const static int mapTiles = 20;
    sf::Music playTheme;
    Character player;
    sf::Vector2f position;
    sf::Sound sound;
    const static int tileSize = 16;
    float timeElapsed = 0.f;
};

#endif // GAME_STATE_PLAY_HPP
