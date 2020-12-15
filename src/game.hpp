#ifndef GAME_HPP
#define GAME_HPP

#include <map>
#include <SFML/Graphics.hpp>
#include <stack>
#include <string>
#include <Thor/Animations.hpp>

#include "boss.hpp"
#include "character.hpp"
#include "enemy.hpp"
#include "potion.hpp"
#include "texture_manager.hpp"

class GameState;

class Game {
  public:
    Game();
    ~Game();

    void changeState(GameState* state);
    void gameLoop();
    GameState* peekState();
    void popState();
    void pushState(GameState* state);

    std::map<std::string, Character> characterAtlas;
    sf::Sprite background;
    std::map<std::string, Boss> bossAtlas;
    std::map<std::string, Enemy> enemyAtlas;
    std::map<std::string, Potion> potionAtlas;
    std::map<std::string, sf::Sprite> mapAtlas;
    TextureManager texmgr;
    sf::RenderWindow window;
  private:
    void loadEntities();
    void loadTextures();

    std::stack<GameState*> states;
};

#endif // GAME_HPP
