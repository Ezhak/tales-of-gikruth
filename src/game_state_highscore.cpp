#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_state_highscore.h"
#include "game_state_class_menu.h"
#include "game_state_start.hpp"
#include "game_state_play.hpp"
#include "game_state.hpp"

GameStateHighscore::GameStateHighscore(Game* game)
{
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    this->background.setTexture(this->game->texmgr.getRef("highscore_menu"));

    sf::RectangleShape shape;
    sf::Vector2f dimensions(180, 70);
    shape.setSize(dimensions);

    std::vector<GuiEntry> entries{};

    sf::Font font;

    if (!font.loadFromFile("assets/menu/fuente.ttf"))
    {
        std::cout << "Font load error" << std::endl;
    }

    sf::Text scoreText;

    scoreText.setFont(font);
    scoreText.setString("Testing");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Red);

    this->text = scoreText;
    this->font = font;

    //
    Character player;

    Gui gui = Gui(dimensions, entries);
    gui.setPosition(pos);
    gui.setOrigin(181, 70);
    gui.show();

    this->guiSystem.emplace("menu", gui);
    
    //

    int position = 0;
    
    while (player.readFromDisk(position++)) {
        std::cout << "score: " << player.getScore() << std::endl;
    }

    //std::reverse(this->getVector().begin(), this->getVector().end());
    /*
    for (int i = 0; i < this->getVector().size(); i++)
    {
        std::cout << this->getVector()[i] << std::endl;
    }
    */

}

GameStateHighscore::~GameStateHighscore()
{

}

bool GameStateHighscore::readFromDisk(int position)
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

void GameStateHighscore::chooseclass()
{
    this->game->pushState(new GameStateClassMenu(this->game));
}

void GameStateHighscore::update(const sf::Time dt) {

}

void GameStateHighscore::handleInput() {
    sf::Event event;
    sf::Vector2f mousePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->view);

    while (this->game->window.pollEvent(event)) {
        switch (event.type) {
            // Close the window
        case sf::Event::Closed:
            this->game->window.close();
            break;
            // If you press ESC you will play the game :)
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                this->chooseclass();
            break;
        default:
            break;
        }
    }

    return;
}

void GameStateHighscore::draw(const sf::Time dt) {
    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    //this->game->window.draw(this->text);

    this->game->window.draw(this->background);

    for (auto gui : this->guiSystem)
        this->game->window.draw(gui.second);

    return;
}
