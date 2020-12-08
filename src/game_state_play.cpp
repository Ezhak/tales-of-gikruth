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

GameStatePlay::GameStatePlay(Game* game) {
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
	
	// Players (Classes)

	sf::Sprite playerSprite;
	playerSprite.setTexture(this->game->texmgr.getRef("dragon"));
	playerSprite.setPosition(300, 275);
	playerSprite.setOrigin(12, 22);


	// Enemies Sprites Level 1

	sf::Sprite enemyOrcSprite;
	enemyOrcSprite.setTexture(this->game->texmgr.getRef("orc"));
	enemyOrcSprite.setPosition(500, 275);
	enemyOrcSprite.setOrigin(12, 22);
	enemyOrcSprite.setScale(-1, 1);

	sf::Sprite enemyTinyZombieSprite;
	enemyTinyZombieSprite.setTexture(this->game->texmgr.getRef("tinyzombie"));
	enemyTinyZombieSprite.setPosition(350, 430);
	enemyTinyZombieSprite.setOrigin(12, 22);

	sf::Sprite enemyTinyZombieSprite2;
	enemyTinyZombieSprite2.setTexture(this->game->texmgr.getRef("tinyzombie"));
	enemyTinyZombieSprite2.setPosition(350, 460);
	enemyTinyZombieSprite2.setOrigin(12, 22);

	// Enemies Sprites Level 2

	sf::Sprite enemyDemonSprite;
	enemyDemonSprite.setTexture(this->game->texmgr.getRef("demon"));
	enemyDemonSprite.setPosition(380, 250);
	enemyDemonSprite.setOrigin(12, 22);
	enemyDemonSprite.setScale(-1, 1);

	sf::Sprite enemyDemonSprite2;
	enemyDemonSprite2.setTexture(this->game->texmgr.getRef("demon"));
	enemyDemonSprite2.setPosition(340, 250);
	enemyDemonSprite2.setOrigin(12, 22);
	enemyDemonSprite2.setScale(-1, 1);

	sf::Sprite enemySkellySprite;
	enemySkellySprite.setTexture(this->game->texmgr.getRef("skelly"));
	enemySkellySprite.setPosition(300, 250);
	enemySkellySprite.setOrigin(12, 22);

	sf::Sprite enemySkellySprite2;
	enemySkellySprite2.setTexture(this->game->texmgr.getRef("skelly"));
	enemySkellySprite2.setPosition(300, 280);
	enemySkellySprite2.setOrigin(12, 22);

	sf::Sprite enemyTinyOrcSprite;
	enemyTinyOrcSprite.setTexture(this->game->texmgr.getRef("tinyorc"));
	enemyTinyOrcSprite.setPosition(340, 320);
	enemyTinyOrcSprite.setOrigin(12, 22);
	enemyTinyOrcSprite.setScale(-1, 1);

	sf::Sprite enemyTinyDemonSprite;
	enemyTinyDemonSprite.setTexture(this->game->texmgr.getRef("tinydemon"));
	enemyTinyDemonSprite.setPosition(380, 280);
	enemyTinyDemonSprite.setOrigin(12, 22);
	enemyTinyDemonSprite.setScale(-1, 1);

	sf::Sprite enemyBossDemonSprite;
	enemyBossDemonSprite.setTexture(this->game->texmgr.getRef("bossdemon"));
	enemyBossDemonSprite.setPosition(340, 280);
	enemyBossDemonSprite.setOrigin(12, 22);
	enemyBossDemonSprite.setScale(-1, 1);

	sf::Sprite enemyBossOrcSprite;
	enemyBossOrcSprite.setTexture(this->game->texmgr.getRef("bossorc"));
	enemyBossOrcSprite.setPosition(480, 250);
	enemyBossOrcSprite.setOrigin(12, 22);

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
	
	// Enemies
		//Level1
	this->enemyOrc = Enemy(enemyOrcSprite);
	this->enemyTinyZombie = Enemy(enemyTinyZombieSprite);
	this->enemyTinyZombie2 = Enemy(enemyTinyZombieSprite2);
	
	//TODO: Enemies Level2
		//
	// Player
	this->player = Character(playerSprite);
	this->enemyDemon = Enemy(enemyDemonSprite);
	this->enemyDemon2 = Enemy(enemyDemonSprite2);
	this->enemySkelly = Enemy(enemySkellySprite);
	this->enemySkelly2 = Enemy(enemySkellySprite2);
	this->enemyTinyOrc = Enemy(enemyTinyOrcSprite);
	this->enemyTinyDemon = Enemy(enemyTinyDemonSprite);
	this->enemyBossDemon = Enemy(enemyBossDemonSprite);
	this->enemyBossOrc = Enemy(enemyBossOrcSprite);
	// Creator
	this->player.create();
	this->enemyOrc.create();
	this->enemyTinyZombie.create();
	this->enemyTinyZombie2.create();
	this->enemyDemon.create();
	this->enemyDemon2.create();
	this->enemySkelly.create();
	this->enemySkelly2.create();
	this->enemyTinyOrc.create();
	this->enemyTinyDemon.create();
	this->enemyBossDemon.createBoss();
	this->enemyBossOrc.createBoss();
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		gameMenu();

	//Debug: Mouse-click position
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i localPosition = sf::Mouse::getPosition(this->game->window);
		std::cout << localPosition.x << std::endl;
		std::cout << localPosition.y << std::endl;
	}
	//

	this->enemyOrc.idle();
	this->enemyTinyZombie.idle();
	this->enemyTinyZombie2.idle();
	this->enemyDemon.idle();
	this->enemyDemon2.idle();
	this->enemySkelly.idle();
	this->enemySkelly2.idle();
	this->enemyTinyOrc.idle();
	this->enemyTinyDemon.idle();
	this->enemyBossDemon.idle();
	this->enemyBossOrc.idle();

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
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyOrc))
		{
			attack(this->player, this->enemyOrc);
			std::cout << "Player hits enemy orc!" << std::endl;
			std::cout << this->enemyOrc.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyTinyZombie))
		{
			attack(this->player, this->enemyTinyZombie);
			std::cout << "Player hits enemy tiny zombie!" << std::endl;
			std::cout << this->enemyTinyZombie.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyDemon))
		{
			attack(this->player, this->enemyDemon);
			std::cout << "Player hits enemy Demon!" << std::endl;
			std::cout << this->enemyDemon.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyDemon2))
		{
			attack(this->player, this->enemyDemon2);
			std::cout << "Player hits enemy demon number two!" << std::endl;
			std::cout << this->enemyDemon2.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemySkelly))
		{
			attack(this->player, this->enemySkelly);
			std::cout << "Player hits enemy skelly!" << std::endl;
			std::cout << this->enemySkelly.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemySkelly2))
		{
			attack(this->player, this->enemySkelly2);
			std::cout << "Player hits enemy tiny zombie number two!" << std::endl;
			std::cout << this->enemySkelly2.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyTinyOrc))
		{
			attack(this->player, this->enemyTinyOrc);
			std::cout << "Player hits enemy tiny orc!" << std::endl;
			std::cout << this->enemyTinyOrc.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyTinyDemon))
		{
			attack(this->player, this->enemyTinyDemon);
			std::cout << "Player hits enemy tiny demon!" << std::endl;
			std::cout << this->enemyTinyDemon.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyBossDemon))
		{
			attack(this->player, this->enemyBossDemon);
			std::cout << "Player hits enemy boss demon! BE CAREFUL" << std::endl;
			std::cout << this->enemyBossDemon.getHealth() << std::endl;
		}
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyBossOrc))
		{
			attack(this->player, this->enemyBossOrc);
			std::cout << "Player hits enemy boss orc! BE CAREFUL" << std::endl;
			std::cout << this->enemyBossOrc.getHealth() << std::endl;
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

void GameStatePlay::update(const sf::Time dt) {

	// this->level.update();
	this->player.update(dt);
	this->enemyOrc.update(dt);
	this->enemyTinyZombie.update(dt);
	this->enemyTinyZombie2.update(dt);
	this->enemyDemon.update(dt);
	this->enemyDemon2.update(dt);
	this->enemySkelly.update(dt);
	this->enemySkelly2.update(dt);
	this->enemyTinyOrc.update(dt);
	this->enemyTinyDemon.update(dt);
	this->enemyBossDemon.update(dt);
	this->enemyBossOrc.update(dt);


	if (checkEnemyCollisions(&this->player, &this->enemyOrc)) {
		// attack(this->enemyOrc, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyTinyZombie)) {
		// attack(this->enemyTinyZombie, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyTinyZombie2)) {
		// attack(this->enemyTinyZombie2, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyDemon)) {
		// attack(this->enemyDemon, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyDemon2)) {
		// attack(this->enemyDemon2, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemySkelly)) {
		// attack(this->enemySkelly, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemySkelly2)) {
		// attack(this->enemySkelly2, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyTinyOrc)) {
		// attack(this->enemyTinyOrc, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyTinyDemon)) {
		// attack(this->enemyTinyDemon, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyBossDemon)) {
		// attack(this->enemyBossDemon, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyBossOrc)) {
		// attack(this->enemyBossOrc, this->player);
		// Debug: std::cout << this->player.getHealth() << std::endl;
	}

	changeToLevel_Two(checkTriggerMap(&this->player, &this->triggerMap1));
	changeToLevel_One(checkTriggerMap(&this->player, &this->triggerMap2));
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
	if (this->player.getSprite().getPosition().y < this->enemyOrc.getSprite().getPosition().y)
	{
		this->player.draw(this->game->window);
		if (level_1_boolean)
		{
			this->enemyOrc.draw(this->game->window);
			this->enemyTinyZombie.draw(this->game->window);
			this->enemyTinyZombie2.draw(this->game->window);
		}
		else {
			this->enemyDemon.draw(this->game->window);
			this->enemyDemon2.draw(this->game->window);
			this->enemySkelly.draw(this->game->window);
			this->enemySkelly2.draw(this->game->window);
			this->enemyTinyOrc.draw(this->game->window);
			this->enemyTinyDemon.draw(this->game->window);
			this->enemyBossDemon.draw(this->game->window);
			this->enemyBossOrc.draw(this->game->window);
		}
	}
	else
	{
		if (level_1_boolean)
		{
			this->enemyOrc.draw(this->game->window);
			this->enemyTinyZombie.draw(this->game->window);
			this->enemyTinyZombie2.draw(this->game->window);
		}
		else {
			this->enemyDemon.draw(this->game->window);
			this->enemyDemon2.draw(this->game->window);
			this->enemySkelly.draw(this->game->window);
			this->enemySkelly2.draw(this->game->window);
			this->enemyTinyOrc.draw(this->game->window);
			this->enemyTinyDemon.draw(this->game->window);
			this->enemyBossDemon.draw(this->game->window);
			this->enemyBossOrc.draw(this->game->window);
		}
		this->player.draw(this->game->window);
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

void GameStatePlay::changeToLevel_Two(bool trigger)
{
	if (!trigger) return;
	this->level_1_boolean = false;
}

void GameStatePlay::changeToLevel_One(bool trigger)
{
	if (!trigger) return;
	this->level_1_boolean = true;
}