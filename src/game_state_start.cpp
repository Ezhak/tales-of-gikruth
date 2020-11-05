#include <SFML/Graphics.hpp>

#include "game_state_start.hpp"
#include "game_state.hpp"

void GameStateStart::draw(const float dt) {
    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    for(auto gui : this->guiSystem)
        this->game->window.draw(gui.second);

    return;
}

void GameStateStart::update(const float dt) {
}

void GameStateStart::handleInput() {
    sf::Event event;
    sf::Vector2f mousePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->view);

    while (this->game->window.pollEvent(event)) {
        switch (event.type) {
        // Close the window
        case sf::Event::Closed:
            this->game->window.close();
            break;
        // Highlight menu items
        case sf::Event::MouseMoved:
            this->guiSystem.at("menu").highlight(this->guiSystem.at("menu").getEntry(mousePos));
            break;
        // Click on menu items
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
                this->guiSystem.at("menu").press(this->guiSystem.at("menu").getEntry(mousePos));
            break;
        // Release menu items
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left) {
                std::string msg = this->guiSystem.at("menu").activate(mousePos);

                if (msg == "load_game")
                    this->loadgame();

                if (msg == "quit_game")
                    this->game->window.close();
            }
            break;
        // Close the window (Escape)
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                this->game->window.close();
            break;
        default:
            break;
        }
    }

    return;
}

void GameStateStart::loadgame() {
    // this->game->pushState(new GameStatePlay(this->game));

    return;
}

GameStateStart::GameStateStart(Game* game) {
    this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);

    sf::RectangleShape shape;
    sf::Vector2f dimensions(363, 70);
    shape.setSize(dimensions);

    GuiEntry start = GuiEntry("start_game", shape, &this->game->texmgr.getRef("start"),
                                                   &this->game->texmgr.getRef("start_highlight"),
                                                   &this->game->texmgr.getRef("start_press"));

    GuiEntry load = GuiEntry("load_game", shape, &this->game->texmgr.getRef("load"),
                                                 &this->game->texmgr.getRef("load_highlight"),
                                                 &this->game->texmgr.getRef("load_press"));

    GuiEntry save = GuiEntry("save_game", shape, &this->game->texmgr.getRef("save"),
                                                 &this->game->texmgr.getRef("save_highlight"),
                                                 &this->game->texmgr.getRef("save_press"));

    GuiEntry quit = GuiEntry("quit_game", shape, &this->game->texmgr.getRef("quit"),
                                                 &this->game->texmgr.getRef("quit_highlight"),
                                                 &this->game->texmgr.getRef("quit_press"));

    std::vector<GuiEntry> entries{start, load, save, quit};

    Gui menu = Gui(dimensions, entries);

    this->guiSystem.emplace("menu", menu);

    this->guiSystem.at("menu").setPosition(pos);
    this->guiSystem.at("menu").setOrigin(181, 155);
    this->guiSystem.at("menu").show();
}
