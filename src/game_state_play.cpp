#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_start.hpp"
#include "game_state_play.hpp"
#include "level.hpp"
#include "TileMap.h"

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

	int imap1 = 0;
	std::vector<sf::FloatRect>vectorCol;
	int collisionsArrayMap1[] =
	{ 
	130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130
	};
	for (auto x : collisionsArrayMap1) {
		if (collisionsArrayMap1[imap1] != 0) {
			collisionsArrayMap1[imap1] -= 1;
		}
		if (imap1 >= 240) {
			vectorCol.push_back(sf::FloatRect((imap1) % 20 * 16, (imap1) / 20 * 16, 16, 16));
		}
		imap1++;
	}

	TileMap mapCollisions;
	if (!mapCollisions.load("assets/tileset.png", sf::Vector2u(16, 16), collisionsArrayMap1, 20, 20)) {
		std::cout << "Error de Tileset" << std::endl;
	}
	mapCollisions.setPosition(240,170);

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

	this->level = Level(mapSprite);
	this->collisions = TileMap(mapCollisions);
	this->collisions.setVector(vectorCol);
	this->player = Character(playerSprite);
	this->enemyOrc = Enemy(enemyOrcSprite);
	this->player.create();
	this->enemyOrc.create();
	this->gameView.zoom(0.666f);

	// Create gui elements

}

void GameStatePlay::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player.move(movement_type::UP);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player.move(movement_type::DOWN);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player.move(movement_type::LEFT);

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player.move(movement_type::RIGHT);

	else this->player.idle();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->game->changeState(new GameStateStart(game));
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(this->game->window);
		std::cout << localPosition.x << std::endl;
		std::cout << localPosition.y << std::endl;
	}

	this->enemyOrc.idle();

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
	}

	return;
}

void GameStatePlay::update(const sf::Time dt) {
	// this->level.update();
	this->player.update(dt);
	this->enemyOrc.update(dt);
	// Check collisions
	for (auto col : this->collisions.getVector()) {
		if (this->player.getSprite().getGlobalBounds().intersects(col)) {
			std::cout << "collision detected" << std::endl;
			// Fixing positions by collision
			if (this->player.getSprite().getPosition().x - 3 < col.left) {
				this->player.leftCollision();
			}
			if (this->player.getSprite().getPosition().x - 3 > col.left + col.width) {
				this->player.rightCollision();
			}
			if (this->player.getSprite().getPosition().y - 3 < col.top) {
				this->player.upCollision();
			}
			if (this->player.getSprite().getPosition().y - 3 < col.top + col.height) {
				this->player.downCollision();
			}
		}
	}
	return;
}

void GameStatePlay::draw(const sf::Time dt) {
	this->game->window.clear(sf::Color::Black);
	this->game->window.setView(this->guiView);
	this->game->window.draw(this->background);
    //this->game->window.setView(this->gameView);	
	this->game->window.draw(this->collisions);
    this->level.draw(this->game->window);
	this->player.draw(this->game->window);
	this->enemyOrc.draw(this->game->window);

	this->game->window.setView(this->guiView);
	for (auto gui : this->guiSystem)
    this->game->window.draw(gui.second);

	return;
}
