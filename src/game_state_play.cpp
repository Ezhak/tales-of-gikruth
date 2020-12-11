#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_start.hpp"
#include "game_state_play.hpp"
#include "level.hpp"
#include "TileMap.h"
#include "enemy.hpp"
#include "character.hpp"

int collisionsArrayMap1[400] =
{
130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130
};

int collisionsArrayMap2[400] =
{
130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130
};

std::vector<sf::Sprite> enemySpriteVector;
std::vector<sf::Sprite> playerSpriteVector;

std::vector<enemyMap> enemyMap1 =
{
	{ enemySpriteName::orc, sf::Vector2f(500, 275), flipped::yup },
	{ enemySpriteName::skelly, sf::Vector2f(350, 430), flipped::nop },
	{ enemySpriteName::skelly, sf::Vector2f(350, 460), flipped::nop },
};

std::vector<enemyMap> enemyMap2 =
{
	{ enemySpriteName::demon, sf::Vector2f(380, 250), flipped::yup }, 
	{ enemySpriteName::demon, sf::Vector2f(340, 250), flipped::yup }, 
	{ enemySpriteName::skelly, sf::Vector2f(300, 250), flipped::nop }, 
	{ enemySpriteName::skelly, sf::Vector2f(300, 280), flipped::yup },
	{ enemySpriteName::tinyorc, sf::Vector2f(340, 320), flipped::yup },
	{ enemySpriteName::tinydemon, sf::Vector2f(380, 280), flipped::yup },
	{ enemySpriteName::bossdemon, sf::Vector2f(340, 280), flipped::yup },
	{ enemySpriteName::bossorc, sf::Vector2f(480, 250), flipped::nop },
};

std::vector<Enemy> enemyVectorMap1;
std::vector<Enemy> enemyVectorMap2;

GameStatePlay::GameStatePlay(Game* game, std::string player) {
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->guiView.setSize(pos);
	this->gameView.setSize(pos);
	pos *= 0.5f;
	this->guiView.setCenter(pos);
	this->gameView.setCenter(pos);

	this->background.setTexture(this->game->texmgr.getRef("game_background"));

	// Level 1

	sf::Sprite mapSprite;
	mapSprite.setTexture(this->game->texmgr.getRef("map_1"));
	mapSprite.setPosition(pos);
	mapSprite.setOrigin(160, 130);

	// Trigger Sprite to switch Level 1 to Level 2 

	sf::RectangleShape trigger;
	trigger.setFillColor(sf::Color::Cyan);
	trigger.setSize(sf::Vector2f(10.f, 3.f));
	trigger.setPosition(287, 450);
	trigger.setOrigin(12, 22);
	
	// Trigger Sprite to switch Level 2 to Level 1

	sf::RectangleShape trigger2;
	trigger2.setFillColor(sf::Color::Cyan);
	trigger2.setSize(sf::Vector2f(10.f, 3.f));
	trigger2.setPosition(527, 260);
	trigger2.setOrigin(12, 22);

	// Collisions Level 1 

	std::vector<sf::RectangleShape>vectorCol;
	TileMap mapCollisions = setCollisions(&collisionsArrayMap1, &vectorCol);

	// Level 2

	sf::Sprite mapSprite2;
	mapSprite2.setTexture(this->game->texmgr.getRef("map_2"));
	mapSprite2.setPosition(pos);
	mapSprite2.setOrigin(160, 130);

	// Collisions Level 2

	std::vector<sf::RectangleShape>vectorCol2;
	TileMap mapCollisions2 = setCollisions(&collisionsArrayMap2, &vectorCol2);
	
	//Set player and enemy sprite vector
	setCharacterSpriteVector();
	setEnemySpriteVector();

	// Players (Classes)

	sf::Sprite playerSprite;
	playerSprite.setTexture(this->game->texmgr.getRef(player));
	playerSprite.setPosition(300, 275);
	playerSprite.setOrigin(12, 22);


	// Enemies Sprites Level 1
	fillEnemyVector(enemyMap1, enemyVectorMap1);

	// Enemies Sprites Level 2
	fillEnemyVector(enemyMap2, enemyVectorMap2);
	
	// Assigns
	// LevelSprites
	this->level = Level(mapSprite);
	this->level2 = Level(mapSprite2);
	
	// LevelCollisions
	this->collisions = TileMap(mapCollisions);
	this->collisions2 = TileMap(mapCollisions2);
	
	// SettingCollisionVectors
	this->collisions.setVector(vectorCol); // Assign vectorCol to collisions vector
	this->collisions2.setVector(vectorCol2);
	
	// Triggers
	this->triggerMap1 = sf::RectangleShape(trigger);
	this->triggerMap2 = sf::RectangleShape(trigger2);
	
	// Enemies TODO: DRAW VECTOR
		//Level1
		//Level2
	// Player
	this->player = Character(playerSprite);
	// Creator
	this->player.create();
	// Zoom
	this->gameView.zoom(0.666f);

	// Create gui elements

}

GameStatePlay::~GameStatePlay()
{
	this->player.~Character();
	this->enemyOrc.~Enemy();
	this->enemyTinyZombie.~Enemy();
	this->enemyTinyZombie2.~Enemy();
	this->enemyDemon.~Enemy();
	this->enemyDemon2.~Enemy();
	this->enemySkelly.~Enemy();
	this->enemySkelly2.~Enemy();
	this->enemyTinyOrc.~Enemy();
	this->enemyTinyDemon.~Enemy();
	this->enemyBossDemon.~Enemy();
	this->enemyBossOrc.~Enemy();
}

bool GameStatePlay::canItMove(movement_type type, Character *player)
{
	sf::FloatRect futurePlayerRect = player->getSprite().getGlobalBounds();
	// Changing the height of the player's bounds to allow it to walk up to the walls without hitting its head.
	futurePlayerRect.height /= 4;
	futurePlayerRect.top += (futurePlayerRect.height * 3);
	// Changing the width.
	futurePlayerRect.width /= 3;
	futurePlayerRect.left += futurePlayerRect.width;

	// Prepparing future position.
	switch (type)
	{
	case movement_type::UP:
		futurePlayerRect.top -= player->getVelocity();
		break;
	case movement_type::DOWN:
		futurePlayerRect.top += player->getVelocity();
		break;
	case movement_type::LEFT:
		futurePlayerRect.left -= player->getVelocity();
		break;
	case movement_type::RIGHT:
		futurePlayerRect.left += player->getVelocity();
		break;
	}
	
	// Checking collision.
	if (level_1_boolean)
	{
		for (auto col : collisions.getVector())
			if (futurePlayerRect.intersects(col.getGlobalBounds()))
				return false;
	}
	else
	{
		for (auto col : collisions2.getVector())
			if (futurePlayerRect.intersects(col.getGlobalBounds()))
				return false;
	}
	// No collision found
	return true;
}

void GameStatePlay::handleInput() {

	// Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canItMove(movement_type::UP, &this->player))
		this->player.move(movement_type::UP);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canItMove(movement_type::DOWN, &this->player))
		this->player.move(movement_type::DOWN);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && canItMove(movement_type::LEFT, &this->player))
		this->player.move(movement_type::LEFT);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && canItMove(movement_type::RIGHT, &this->player))
		this->player.move(movement_type::RIGHT);

	else this->player.idle();

	//Debug: Mouse-click position
	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i localPosition = sf::Mouse::getPosition(this->game->window);
		std::cout << localPosition.x << std::endl;
		std::cout << localPosition.y << std::endl;
	}*/
	//

	if (level_1_boolean)
	{
		for (unsigned i = 0; i < enemyVectorMap1.size(); i++)
			enemyVectorMap1[i].idle();
	}
	else
	{
		for (unsigned i = 0; i < enemyVectorMap2.size(); i++)
			enemyVectorMap2[i].idle();
	}

	sf::Event event;

    sf::Vector2f guiPos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->guiView);
	sf::Vector2f gamePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->gameView);

	while(this->game->window.pollEvent(event)) {
		switch(event.type) {
			// Close the window
		case sf::Event::Closed:
			this->game->window.close();
			break;
		default: break;
		}

		// CharacterAttack
		if (level_1_boolean)
		{
			for (unsigned i = 0; i < enemyVectorMap1.size(); i++)
				if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &enemyVectorMap1[i]) && enemyVectorMap1[i].getHealthStatus() == healthStatus::alive)
				{
					attack(this->player, enemyVectorMap1[i]);
					std::cout << "Player hits enemy orc!" << std::endl;
					this->player.setScore();
					std::cout << enemyVectorMap1[i].getHealth() << std::endl;
					std::cout << this->player.getScore() << std::endl;
				}
		}
		else
		{
			for (unsigned i = 0; i < enemyVectorMap2.size(); i++)
				if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &enemyVectorMap2[i]) && enemyVectorMap2[i].getHealthStatus() == healthStatus::alive)
				{
					attack(this->player, enemyVectorMap2[i]);
					std::cout << "Player hits enemy orc!" << std::endl;
					this->player.setScore();
					std::cout << enemyVectorMap2[i].getHealth() << std::endl;
					std::cout << this->player.getScore() << std::endl;
				}
		}
	}

	return;
}

bool GameStatePlay::checkEnemyCollisions(Character *player, Enemy *enemy)
{
	// Check collisions with Enemy
	if (player->getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds()))
	{
		return true;
	}
	else return false;
}

bool GameStatePlay::checkHealth(float health)
{
	if (health <= 0)
		// If false, character is dead.	
		return false;
	// If true, character is alive.
	else return true;
}

bool GameStatePlay::checkTriggerMap(Character* player, sf::RectangleShape* trigger)
{
	// Check collision with Trigger to switch map
	if (player->getSprite().getGlobalBounds().intersects(trigger->getGlobalBounds())) {
		return true;
	}
	else return false;
}

bool GameStatePlay::checkEnemyWipeout(std::vector<Enemy> enemyVector)
{
	for (unsigned i = 0; i < enemyVector.size(); i++)
	{
		//if enemies in level are still alive, cannot leave.
		if (enemyVector[i].getHealthStatus() == healthStatus::alive) return false;
	}
	//no enemies left alive.
	return true;
}

void GameStatePlay::update(const sf::Time dt) {

	// this->level.update();
	this->player.update(dt);

	int timeElapsed = 0;

	timeElapsed += (int)dt.asMicroseconds();

	if(timeElapsed % 120 == 0) {
		//std::cout << "Time" << std::endl;
	}

	// CheckCharacterHealth if dead, go back to start menu.
	// And save your score in a file.
	if (!checkHealth(this->player.getHealth()))
	{
		this->burnDisk();
		this->game->pushState(new GameStateStart(this->game));
		std::cout << "You lose :( But your score has saved ... :)" << std::endl;
	}

	//CheckEnemyHealth if health is below or equal to 0, changeHealthStatus to 'dead'.
	changeHealthStatus(enemyVectorMap1, healthStatus::dead);
	changeHealthStatus(enemyVectorMap2, healthStatus::dead);

	if (level_1_boolean)
	{
		for (unsigned i = 0; i < enemyVectorMap1.size(); i++)
		{
			enemyVectorMap1[i].update(dt);
			if (checkEnemyCollisions(&this->player, &enemyVectorMap1[i]) && (enemyVectorMap1[i].getHealthStatus() == healthStatus::alive))
			{
				if (timeElapsed % 120 == 0)
				{
					attack(enemyVectorMap1[i], this->player);
					std::cout << this->player.getHealth() << std::endl;
				}
			}
		}
	}
	else // Level 2 Collisions Check & NPC Attack System
 	{
		for (unsigned i = 0; i < enemyVectorMap2.size(); i++)
		{
			enemyVectorMap2[i].update(dt);
			if (checkEnemyCollisions(&this->player, &enemyVectorMap2[i]) && (enemyVectorMap2[i].getHealthStatus() == healthStatus::alive))
			{
				if (timeElapsed % 120 == 0) {
					attack(enemyVectorMap2[i], this->player);
					std::cout << this->player.getHealth() << std::endl;
				}
			}
		}
	}

	changeToLevel_Two(checkTriggerMap(&this->player, &this->triggerMap1), checkEnemyWipeout(enemyVectorMap1));
	changeToLevel_One(checkTriggerMap(&this->player, &this->triggerMap2), checkEnemyWipeout(enemyVectorMap2));

	return;
}

void GameStatePlay::draw(const sf::Time dt) {
	this->game->window.clear(sf::Color::Black);
	this->game->window.setView(this->guiView);
	this->game->window.draw(this->background);
    this->game->window.setView(this->gameView);	
	// Collisions drawin' to debug:
	// this->game->window.draw(this->collisions);
	
   
	if (!level_1_boolean) {
		this->level2.draw(this->game->window);
		//DEBUG: Show map collisions
		//for (auto col : this->collisions2.getVector())
		//	this->game->window.draw(col);
	}
	else {
		this->level.draw(this->game->window);
		//DEBUG: Show map collisions
		//for (auto col : this->collisions.getVector()) 
		//	this->game->window.draw(col);
	}

	// Debug: draw the blue trigger tile:
	//this->game->window.draw(this->triggerMap1);
	//this->game->window.draw(this->triggerMap2);

	// Checking positions to see which one is drawn first.
	
	this->player.draw(this->game->window);
	if (level_1_boolean)
	{
		for (unsigned i = 0; i < enemyVectorMap1.size(); i++)
		{
			if (enemyVectorMap1[i].getHealthStatus() == healthStatus::alive) enemyVectorMap1[i].draw(this->game->window);
		}
	}
	else {
		for (unsigned i = 0; i < enemyVectorMap2.size(); i++)
		{
			if (enemyVectorMap2[i].getHealthStatus() == healthStatus::alive) enemyVectorMap2[i].draw(this->game->window);
		}
	}

	this->game->window.setView(this->guiView);
	for (auto gui : this->guiSystem)
    this->game->window.draw(gui.second);

	return;
}


// For character attack
void GameStatePlay::attack(Character& player, Enemy& enemy)
{
	enemy.setHealth(player.getAttackPoints());
}
// For enemy attack
void GameStatePlay::attack(Enemy& enemy, Character& player)
{
	player.setHealth(enemy.getAttackPoints());
}

void GameStatePlay::gameMenu()
{
	//this->game->changeState(new GameStateStart(this->game));
	this->game->peekState();
	this->game->changeState(new GameStateStart(this->game));
}

void GameStatePlay::burnDisk()
{
	FILE* fp;
	fopen_s(&fp, "score.dat", "ab");
	if (!fp) {
		std::cout << "File score.dat error" << std::endl;
		fclose(fp);
	}
	fwrite(this, sizeof this, 1, fp);
	if (ferror(fp)) {
		std::cout << "File burn score.dat error" << std::endl;
		fclose(fp);
		return;
	}
	fclose(fp);
}

bool GameStatePlay::readFromDisk(int position)
{
	int x;
	FILE* fp;
	fopen_s(&fp, "score.dat", "rb");
	if (!fp) {
		std::cout << "Error to open file score.dat" << std::endl;
		fclose(fp);
		return false;
	}

	fseek(fp, sizeof * this * position, 0);
	x = fread(this, sizeof this, 1, fp);
	fclose(fp);
	if (x == 1) return true;
	return false;
}

void GameStatePlay::changeToLevel_Two(bool trigger, bool wipeout)
{
	if (!trigger || !wipeout) return;
	this->level_1_boolean = false;
}

void GameStatePlay::changeToLevel_One(bool trigger, bool wipeout)
{
	if (!trigger || !wipeout) return;
	this->burnDisk();
	this->level_1_boolean = true;
	std::cout << "Game over! You did it well, pal :) Your score has saved." << std::endl;
}

TileMap GameStatePlay::setCollisions(int (*collisionsArrayMap)[400], std::vector<sf::RectangleShape>*vectorCol)
{
	// imap1 Is literally i iterator
	int imap1 = 0;

	// Asign collision shapes to draw later
	for (auto x : *collisionsArrayMap) {
		if ((*collisionsArrayMap)[imap1] != 0) {
			(*collisionsArrayMap)[imap1] -= 1;
			sf::RectangleShape colShape;
			colShape.setFillColor(sf::Color::Blue);
			colShape.setSize(sf::Vector2f(16.f, 16.f));
			colShape.setPosition((imap1 % 20 * 16) + 240.f, (imap1 / 20 * 16) + 170.f); // 240 X and 170 Y
			(*vectorCol).push_back(colShape);
		}
		imap1++;
	}
	// Draw a second layer where the collisions are
	TileMap mapCollisions;
	if (!mapCollisions.load("assets/tileset.png", sf::Vector2u(16, 16), *collisionsArrayMap, 20, 20)) {
		std::cout << "Tileset Error" << std::endl;
	}
	mapCollisions.setPosition(240,170);

	return mapCollisions;
}
//For enemies
sf::Sprite GameStatePlay::createSprite(enemySpriteName name)
{
	sf::Sprite sprite;
	sprite.setTexture(this->game->texmgr.getRef(Enemy::enemySpritesFile[name]));
	sprite.setOrigin(12, 22);

	return sprite;
}
//For characters
sf::Sprite GameStatePlay::createSprite(playerSpriteName name)
{
	sf::Sprite sprite;
	sprite.setTexture(this->game->texmgr.getRef(Character::playerSpritesFile[name]));
	sprite.setOrigin(12, 22);

	return sprite;
}

void GameStatePlay::setEnemySpriteVector()
{
	for (unsigned i = 0; i < Enemy::enemySpritesFile.size(); i++)
	{
		enemySpriteVector.push_back(createSprite((enemySpriteName)i));
	}
}

void GameStatePlay::setCharacterSpriteVector()
{
	for (unsigned i = 0; i < Character::playerSpritesFile.size(); i++)
	{
		playerSpriteVector.push_back(createSprite((playerSpriteName)i));
	}
}

Enemy GameStatePlay::createEnemy(enemyMap map)
{
	sf::Sprite sprite = enemySpriteVector[(int)map.type];
	sprite.setPosition(map.position);
	sprite.setScale(map.flip == flipped::yup ? sf::Vector2f(-1, 1) : sf::Vector2f(1, 1));

	Enemy enemy = Enemy(sprite);

	if (map.type == enemySpriteName::bossdemon || map.type == enemySpriteName::bossorc)
		enemy.createBoss();
	else
		enemy.create();

	return enemy;
}

void GameStatePlay::fillEnemyVector(std::vector<enemyMap> vectorMap, std::vector<Enemy> &vectorEnemy)
{
	for (unsigned i = 0; i < vectorMap.size(); i++)
	{
		vectorEnemy.push_back(createEnemy(vectorMap[i]));
	}
}

void GameStatePlay::changeHealthStatus(std::vector<Enemy> &enemyVector, healthStatus status)
{
	for (unsigned i = 0; i < enemyVector.size(); i++)
	{
		if (!checkHealth(enemyVector[i].getHealth())) enemyVector[i].setStatus(status);
	}
}