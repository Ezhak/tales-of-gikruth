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

	sf::Sprite mapSprite;
	mapSprite.setTexture(this->game->texmgr.getRef("map_1"));
	mapSprite.setPosition(pos);
	mapSprite.setOrigin(160, 130);
	//Collisions
	std::vector<sf::RectangleShape>vectorCol;
	TileMap mapCollisions = setCollisions(&collisionsArrayMap1, &vectorCol);

	sf::Sprite mapSprite2;
	mapSprite2.setTexture(this->game->texmgr.getRef("map_2"));
	mapSprite2.setPosition(pos);
	mapSprite2.setOrigin(160, 130);

	sf::Sprite playerSprite;
	playerSprite.setTexture(this->game->texmgr.getRef("dragon"));
	playerSprite.setPosition(300, 275);
	playerSprite.setOrigin(12, 22);

	sf::Sprite enemyOrcSprite;
	enemyOrcSprite.setTexture(this->game->texmgr.getRef("orc"));
	enemyOrcSprite.setPosition(500, 275);
	enemyOrcSprite.setOrigin(12, 22);

	sf::Sprite enemyTinyZombieSprite;
	enemyTinyZombieSprite.setTexture(this->game->texmgr.getRef("tinyzombie"));
	enemyTinyZombieSprite.setPosition(350, 430);
	enemyTinyZombieSprite.setOrigin(12, 22);

	sf::Sprite enemyTinyZombieSprite2;
	enemyTinyZombieSprite2.setTexture(this->game->texmgr.getRef("tinyzombie"));
	enemyTinyZombieSprite2.setPosition(350, 460);
	enemyTinyZombieSprite2.setOrigin(12, 22);

	this->level = Level(mapSprite);
	this->collisions = TileMap(mapCollisions);
	this->collisions.setVector(vectorCol); // Assign vectorCol to collisions vector
	this->enemyOrc = Enemy(enemyOrcSprite);
	this->enemyTinyZombie = Enemy(enemyTinyZombieSprite);
	this->enemyTinyZombie2 = Enemy(enemyTinyZombieSprite2);
	this->player = Character(playerSprite);
	this->player.create();
	this->enemyOrc.create();
	this->enemyTinyZombie.create();
	this->enemyTinyZombie2.create();
	this->gameView.zoom(0.666f);

	// Create gui elements

}

GameStatePlay::~GameStatePlay()
{
	this->player.~Character();
	this->enemyOrc.~Enemy();
	this->enemyTinyZombie.~Enemy();
	this->enemyTinyZombie2.~Enemy();
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
	//Changing the height of the player's bounds to allow it to walk up to the walls without hitting its head.
	futurePlayerRect.height /= 4;
	futurePlayerRect.top += (futurePlayerRect.height * 3);
	//Changing the width.
	futurePlayerRect.width /= 3;
	futurePlayerRect.left += futurePlayerRect.width;

	//Prepparing future position.
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
	
	//Checking collision.
	for (auto col : this->collisions.getVector())
		if (futurePlayerRect.intersects(col.getGlobalBounds()))
			return false;
	// No collision found
	return true;
}

void GameStatePlay::handleInput() {
	//Movement
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
		this->game->changeState(new GameStateStart(this->game));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i localPosition = sf::Mouse::getPosition(this->game->window);
		std::cout << localPosition.x << std::endl;
		std::cout << localPosition.y << std::endl;
	}

	this->enemyOrc.idle();
	this->enemyTinyZombie.idle();
	this->enemyTinyZombie2.idle();

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

		//CharacterAttack
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
		if (event.type == sf::Event::MouseButtonPressed && checkEnemyCollisions(&this->player, &this->enemyTinyZombie2))
		{
			attack(this->player, this->enemyTinyZombie2);
			std::cout << "Player hits enemy tiny zombie number two!" << std::endl;
			std::cout << this->enemyTinyZombie2.getHealth() << std::endl;
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
		//If false, character is dead.	
		return false;
	//If true, character is alive.
	else return true;
}

void GameStatePlay::update(const sf::Time dt) {
	// this->level.update();
	this->player.update(dt);
	this->enemyOrc.update(dt);
	this->enemyTinyZombie.update(dt);
	this->enemyTinyZombie2.update(dt);
	
	if (checkEnemyCollisions(&this->player, &this->enemyOrc)) {
		//attack(this->enemyOrc, this->player);
		//Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyTinyZombie)) {
		//attack(this->enemyTinyZombie, this->player);
		//Debug: std::cout << this->player.getHealth() << std::endl;
	}
	if (checkEnemyCollisions(&this->player, &this->enemyTinyZombie2)) {
		//attack(this->enemyTinyZombie, this->player);
		//Debug: std::cout << this->player.getHealth() << std::endl;
	}
	return;
}

void GameStatePlay::draw(const sf::Time dt) {
	this->game->window.clear(sf::Color::Black);
	this->game->window.setView(this->guiView);
	this->game->window.draw(this->background);
    this->game->window.setView(this->gameView);	
	//this->game->window.draw(this->collisions);
	// Collisions drawin' to debug ^^^
	for (auto col : this->collisions.getVector()) {
		this->game->window.draw(col);
	}
    this->level.draw(this->game->window);

	//Checking positions to see which one is drawn first.
	if (this->player.getSprite().getPosition().y < this->enemyOrc.getSprite().getPosition().y)
	{
		this->player.draw(this->game->window);
		this->enemyOrc.draw(this->game->window);
		this->enemyTinyZombie.draw(this->game->window);
		this->enemyTinyZombie2.draw(this->game->window);
	}
	else
	{
		this->enemyOrc.draw(this->game->window);
		this->enemyTinyZombie.draw(this->game->window);
		this->enemyTinyZombie2.draw(this->game->window);
		this->player.draw(this->game->window);
	}

	this->game->window.setView(this->guiView);
	for (auto gui : this->guiSystem)
    this->game->window.draw(gui.second);

	return;
}
//for character attack
void GameStatePlay::attack(Character& player, Enemy& enemy)
{
	enemy.setHealth(player.getAttackPoints());
}
//for enemy attack
void GameStatePlay::attack(Enemy& enemy, Character& player)
{
	player.setHealth(enemy.getAttackPoints());
}
