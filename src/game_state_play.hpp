#ifndef GAME_STATE_PLAY_HPP
#define GAME_STATE_PLAY_HPP


#include <SFML/System.hpp>
#include <string>
#include <map>

#include "game_state.hpp"
#include "gui.hpp"
#include "level.hpp"
#include "TileMap.h"

enum class flipped { yup, nop };

struct enemyMap
{
	enemySpriteName type;
	sf::Vector2f position;
	flipped flip;
};

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
		// Level 1
		Enemy enemyOrc;
		Enemy enemyTinyZombie;
		Enemy enemyTinyZombie2;
		// Level 2
		Enemy enemyDemon;
		Enemy enemyDemon2;
		Enemy enemySkelly;
		Enemy enemySkelly2;
		Enemy enemyTinyOrc;
		Enemy enemyTinyDemon;
		Enemy enemyBossDemon;
		Enemy enemyBossOrc;

		std::map<std::string, Gui> guiSystem;

	public:
		GameStatePlay(Game* game, std::string player);
		~GameStatePlay();

		void gameMenu();

		virtual void handleInput();
		virtual void update(const sf::Time dt);
		virtual void draw(const sf::Time dt);

		bool canItMove(movement_type type, Character* player);
		bool checkEnemyCollisions(Character* player, Enemy* enemy);
		bool checkHealth(float health);
		bool checkTriggerMap(Character* player, sf::RectangleShape* trigger);
		bool checkEnemyWipeout(std::vector<Enemy> enemyVector);

		void attack(Character& player, Enemy& enemy);
		void attack(Enemy& enemy, Character& player);
		void changeToLevel_Two(bool trigger, bool wipeout);
		void changeToLevel_One(bool trigger, bool wipeout);
		void setEnemySpriteVector();
		void setCharacterSpriteVector();
		void fillEnemyVector(std::vector<enemyMap> vectorMap, std::vector<Enemy> &vectorEnemy);
		void changeHealthStatus(std::vector<Enemy> &enemyVector, healthStatus status);

		TileMap setCollisions(int(*collisionsArrayMap)[400], std::vector<sf::RectangleShape>* vectorCol);
		Enemy createEnemy(enemyMap map);
		sf::Sprite createSprite(enemySpriteName name);
		sf::Sprite createSprite(playerSpriteName name);
};

#endif // GAME_STATE_PLAY_HPP