#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"
#include "texture_manager.hpp"
#include "entity.hpp"

void Game::loadEntities() {
    // Animation staticAnim(0, 0, 1.0f);
    // this->tileAtlas["grass"] =
    //     Tile(this->tileSize, 1, texmgr.getRef("grass"),
    //         { staticAnim },
    //         TileType::GRASS, 50, 0, 1);

    return;
}

void Game::loadTextures() {
    texmgr.loadTexture("start",             "assets/menu/start.png");
    texmgr.loadTexture("start_highlight",   "assets/menu/start_highlight.png");
    texmgr.loadTexture("start_press",       "assets/menu/start_press.png");

    texmgr.loadTexture("load",              "assets/menu/load.png");
    texmgr.loadTexture("load_highlight",    "assets/menu/load_highlight.png");
    texmgr.loadTexture("load_press",        "assets/menu/load_press.png");

    texmgr.loadTexture("save",              "assets/menu/save.png");
    texmgr.loadTexture("save_highlight",    "assets/menu/save_highlight.png");
    texmgr.loadTexture("save_press",        "assets/menu/save_press.png");

    texmgr.loadTexture("quit",              "assets/menu/quit.png");
    texmgr.loadTexture("quit_highlight",    "assets/menu/quit_highlight.png");
    texmgr.loadTexture("quit_press",        "assets/menu/quit_press.png");

    texmgr.loadTexture("menu_background",   "assets/menu/background.png");
    texmgr.loadTexture("game_background",   "assets/game/background.png");
    
    texmgr.loadTexture("map_1",             "assets/game/maps/map_1.png");

    texmgr.loadTexture("player_sol",        "assets/game/characters/sol.png");
}

void Game::pushState(GameState* state) {
    this->states.push(state);

    return;
}

void Game::popState() {
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState* state) {
    if (!this->states.empty())
            popState();

    pushState(state);

    return;
}

GameState* Game::peekState() {
    if (this->states.empty())
        return nullptr;

    return this->states.top();
}

void Game::gameLoop() {
    sf::Clock clock;

    while(this->window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (peekState() == nullptr)
            continue;

        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

Game::Game() {
    this->loadTextures();
    this->loadEntities();
        
    this->window.create(sf::VideoMode(800, 600), "Tales Of Gikruth", sf::Style::Titlebar | sf::Style::Close);
    this->window.setFramerateLimit(60);
}

Game::~Game() {
    while(!this->states.empty())
        popState();
}
