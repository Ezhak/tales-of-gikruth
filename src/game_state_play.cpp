#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_play.hpp"
#include "level.hpp"

void GameStatePlay::draw(const float dt) {
	this->game->window.clear(sf::Color::Black);

	this->game->window.setView(this->guiView);
	this->game->window.draw(this->background);
	
    this->game->window.setView(this->gameView);
    this->level.draw(this->game->window);

	this->game->window.setView(this->guiView);
	for (auto gui : this->guiSystem)
        this->game->window.draw(gui.second);

	return;
}

void GameStatePlay::update(const float dt) {
	// this->level.update();

	return;
}

void GameStatePlay::handleInput() {
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

GameStatePlay::GameStatePlay(Game* game) {
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->guiView.setSize(pos);
	this->gameView.setSize(pos);
	pos *= 0.5f;
	this->guiView.setCenter(pos);
	this->gameView.setCenter(pos);

	this->setBackground(this->game->texmgr.getRef("game_background"));

	this->level = Level();
	this->level.setMap(this->game->texmgr.getRef("map_1"));
	this->level.getMap().setPosition(pos);
	this->level.getMap().setOrigin(160, 130);

	this->gameView.zoom(0.666f);

	this->player = Player();

	// Create gui elements
}