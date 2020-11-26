#include <SFML/Graphics.hpp>

#include "game_state.hpp"
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

	//Map1's collision
	//Intente laburar la colision aca kjjjjjlksd
	//Creo un vector de colisiones, donde le asigno el array de las ID de los tiles para las colisiones, sacadas del .js del tilemap
	//Lo recorro con un for-each al vector y a todo lo que no sea cero, le resto -1 (porque tiene un offset de 1 los ID de los tiles)
	//Luego eso lo meto con el pushback en el vector con ese calculo (los ultimos 2 parametros son el tamaño de cada tile) 
	//creo un map1Collisions de tipo TileMap  que es una clase agarrada de la documentacion de SFML para laburar la "creacion de mapas" con arrays de IDs de tiles
	//
	int imap1 = 0;
	std::vector<sf::FloatRect>vectorCollisions;
	int collisionsArrayMap1[] = { 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 0, 0, 0, 0, 0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130 };
	for (auto x : vectorCollisions) {
		if (collisionsArrayMap1[imap1] != 0) {
			collisionsArrayMap1[imap1] -= 1;
			vectorCollisions.push_back(sf::FloatRect(imap1 % 20 * 16, imap1 / 20 * 16, 16, 16));
		}
		imap1++;
	}
	TileMap map1Collisions;
	if (!map1Collisions.load("assets/game/maps/map_1.png", sf::Vector2u(16, 16), collisionsArrayMap1, 20, 20)) {
		std::cout << "Error." << std::endl;
	}
	map1Collisions.setPosition(pos);
	map1Collisions.setOrigin(160, 130);
	//Lo dibuje en un lugar erroneo
	this->game->window.draw(map1Collisions);

	//-------
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
	//this->collisions = TileMap(map1Collisions);
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
	return;
}

void GameStatePlay::draw(const sf::Time dt) {
	this->game->window.clear(sf::Color::Black);

	this->game->window.setView(this->guiView);
	this->game->window.draw(this->background);
	
    this->game->window.setView(this->gameView);
    this->level.draw(this->game->window);
	this->player.draw(this->game->window);
	this->enemyOrc.draw(this->game->window);

	this->game->window.setView(this->guiView);
	for (auto gui : this->guiSystem)
    this->game->window.draw(gui.second);

	return;
}
