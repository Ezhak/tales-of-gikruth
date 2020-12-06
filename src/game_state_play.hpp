#ifndef GAME_STATE_PLAY_HPP
#define GAME_STATE_PLAY_HPP


#include <SFML/System.hpp>
#include <string>
#include <map>

#include "game_state.hpp"
#include "gui.hpp"
#include "level.hpp"
#include "TileMap.h"

class GameStatePlay : public GameState {
	private:
		sf::View gameView;
		sf::View guiView;
			
		Level level;
		//
		TileMap collisions;
		//
		Character player;
		Enemy enemyOrc;
			
		std::map<std::string, Gui> guiSystem;

	public:
		GameStatePlay(Game* game);

		virtual void handleInput();
		virtual void update(const sf::Time dt);
		virtual void draw(const sf::Time dt);
		bool canItMove(movement_type type, Character* player);
		bool checkEnemyCollisions(Character* player, Enemy* enemy);
		void attack(Character& player, Enemy& enemy);
		void attack(Enemy& enemy, Character& player);
		TileMap setCollisions(int(*collisionsArrayMap)[400], std::vector<sf::RectangleShape>* vectorCol);
};

#endif // GAME_STATE_PLAY_HPP