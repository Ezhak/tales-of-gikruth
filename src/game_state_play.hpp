#ifndef GAME_STATE_PLAY_HPP
#define GAME_STATE_PLAY_HPP

#include <SFML/System.hpp>
#include <string>
#include <map>

#include "game_state.hpp"
#include "gui.hpp"
#include "level.hpp"
#include "player.hpp"

class GameStatePlay : public GameState {
private:
	sf::View gameView;
	sf::View guiView;
    
    Level level;
    Player player;
    
    std::map<std::string, Gui> guiSystem;

public:
	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	GameStatePlay(Game* game);
};

#endif // GAME_STATE_PLAY_HPP