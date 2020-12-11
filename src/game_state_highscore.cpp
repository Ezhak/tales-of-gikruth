#include <SFML/Graphics.hpp>

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

    Gui gui = Gui(dimensions, entries);
    gui.setPosition(pos);
    gui.setOrigin(181, 70);
    gui.show();

    this->guiSystem.emplace("menu", gui);
}

GameStateHighscore::~GameStateHighscore()
{

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
    this->game->window.draw(this->background);

    for (auto gui : this->guiSystem)
        this->game->window.draw(gui.second);

    return;
}
