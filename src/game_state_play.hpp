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

		bool level_1_boolean = true;
			
		Level level;
		Level level2;
		//
		TileMap collisions;
		TileMap collisions2;
		//
		sf::RectangleShape triggerMap1;
		sf::RectangleShape triggerMap2;
		//
		Character player;
		Enemy enemyOrc;
		Enemy enemyTinyZombie;
		Enemy enemyTinyZombie2;
			
		std::map<std::string, Gui> guiSystem;

	public:
		GameStatePlay(Game* game);
		~GameStatePlay();

		void gameMenu();

		virtual void handleInput();
		virtual void update(const sf::Time dt);
		virtual void draw(const sf::Time dt);

		bool canItMove(movement_type type, Character* player);
		bool checkEnemyCollisions(Character* player, Enemy* enemy);
		bool checkHealth(float health);
		bool checkTriggerMap(Character* player, sf::RectangleShape* trigger);

		void attack(Character& player, Enemy& enemy);
		void attack(Enemy& enemy, Character& player);
		void changeToLevel_Two(bool trigger);
		void changeToLevel_One(bool trigger);

		TileMap setCollisions(int(*collisionsArrayMap)[400], std::vector<sf::RectangleShape>* vectorCol);
};

#endif // GAME_STATE_PLAY_HPP