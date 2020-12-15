#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"
#include "texture_manager.hpp"

Game::Game()
{
  this->loadTextures();
  this->loadEntities();

  this->window.create(sf::VideoMode(800, 600), "Tales Of Gikruth", sf::Style::Titlebar | sf::Style::Close);
  this->window.setFramerateLimit(60);
}

Game::~Game()
{
  while(!this->states.empty())
    popState();
}

void Game::changeState(GameState* state)
{
  if (!this->states.empty())
    popState();

  pushState(state);

  return;
}

void Game::gameLoop()
{
  sf::Clock clock;

  while(this->window.isOpen()) {
    sf::Time elapsed = clock.restart();

    if (peekState() == nullptr)
      continue;

    peekState()->handleInput();
    peekState()->update(elapsed);
    this->window.clear(sf::Color::Black);
    peekState()->draw(elapsed);
    this->window.display();
  }
}

GameState* Game::peekState()
{
  if (this->states.empty())
    return nullptr;

  return this->states.top();
}

void Game::popState()
{
  delete this->states.top();
  this->states.pop();

  return;
}

void Game::pushState(GameState* state)
{
  this->states.push(state);

  return;
}

void Game::loadEntities()
{
  // characters
  this->characterAtlas["dragon"] = Character(this->texmgr.getRef("dragon"));
  this->characterAtlas["knight"] = Character(this->texmgr.getRef("knight"));
  this->characterAtlas["mage"] = Character(this->texmgr.getRef("mage"));

  // level 1 enemies
  this->enemyAtlas["orc"] = Enemy(this->texmgr.getRef("orc"));
  this->enemyAtlas["skelly"] = Enemy(this->texmgr.getRef("skelly"));

  // level 2 enemies
  this->enemyAtlas["demon"] = Enemy(this->texmgr.getRef("demon"));
  this->enemyAtlas["tinyorc"] = Enemy(this->texmgr.getRef("tinyorc"));
  this->enemyAtlas["tinydemon"] = Enemy(this->texmgr.getRef("tinydemon"));
  this->bossAtlas["bossdemon"] = Boss(this->texmgr.getRef("bossdemon"));
  this->bossAtlas["bossorc"] = Boss(this->texmgr.getRef("bossorc"));

  for (auto& x : bossAtlas)
    x.second.setOrigin(12, 22);

  for (auto& x : characterAtlas)
    x.second.setOrigin(12, 22);

  for (auto& x : enemyAtlas)
    x.second.setOrigin(12, 22);

  // maps
  this->mapAtlas["1"] = sf::Sprite(this->texmgr.getRef("map_1"));
  this->mapAtlas["2"] = sf::Sprite(this->texmgr.getRef("map_2"));

  // potions
  this->potionAtlas["regen"] = Potion(this->texmgr.getRef("regen"), potionType::regen);
  this->potionAtlas["speed"] = Potion(this->texmgr.getRef("speed"), potionType::speed);
  this->potionAtlas["strength"] = Potion(this->texmgr.getRef("strength"), potionType::strength);
}

void Game::loadTextures()
{
  // main menu
  texmgr.loadTexture("start",           "assets/menu/start.png");
  texmgr.loadTexture("start_highlight", "assets/menu/start_highlight.png");
  texmgr.loadTexture("start_press",     "assets/menu/start_press.png");

  texmgr.loadTexture("hiscores",           "assets/menu/hiscores.png");
  texmgr.loadTexture("hiscores_highlight", "assets/menu/hiscores_highlight.png");
  texmgr.loadTexture("hiscores_press",     "assets/menu/hiscores_press.png");

  texmgr.loadTexture("quit",           "assets/menu/quit.png");
  texmgr.loadTexture("quit_highlight", "assets/menu/quit_highlight.png");
  texmgr.loadTexture("quit_press",     "assets/menu/quit_press.png");

  texmgr.loadTexture("menu_background", "assets/menu/background.png");
  texmgr.loadTexture("game_background", "assets/game/background.png");

  // class menu
  texmgr.loadTexture("choose_class",     "assets/menu/choose_class.png");

  texmgr.loadTexture("dragon_menu",      "assets/menu/dragon.png");
  texmgr.loadTexture("dragon_highlight", "assets/menu/dragon_highlight.png");
  texmgr.loadTexture("dragon_press",     "assets/menu/dragon_press.png");

  texmgr.loadTexture("knight_menu",      "assets/menu/knight.png");
  texmgr.loadTexture("knight_highlight", "assets/menu/knight_highlight.png");
  texmgr.loadTexture("knight_press",     "assets/menu/knight_press.png");

  texmgr.loadTexture("mage_menu",        "assets/menu/mage.png");
  texmgr.loadTexture("mage_highlight",   "assets/menu/mage_highlight.png");
  texmgr.loadTexture("mage_press",       "assets/menu/mage_press.png");

  // maps
  texmgr.loadTexture("map_1", "assets/game/maps/map_1.png");
  texmgr.loadTexture("map_2", "assets/game/maps/map_2.png");

  texmgr.loadTexture("dragon", "assets/game/characters/dragon.png");
  texmgr.loadTexture("knight", "assets/game/characters/knight.png");
  texmgr.loadTexture("mage",   "assets/game/characters/mage.png");

  // tiny and normal enemies: 24x24
  texmgr.loadTexture("tinydemon",  "assets/game/characters/tinydemon.png");
  texmgr.loadTexture("tinyorc",    "assets/game/characters/tinyorc.png");
  texmgr.loadTexture("tinyzombie", "assets/game/characters/tinyzombie.png");
  texmgr.loadTexture("demon",      "assets/game/characters/demon.png");
  texmgr.loadTexture("orc",        "assets/game/characters/orc.png");
  texmgr.loadTexture("skelly",     "assets/game/characters/skelly.png");

  // bosses: 34x34
  texmgr.loadTexture("bossdemon", "assets/game/characters/bossdemon.png");
  texmgr.loadTexture("bossorc",   "assets/game/characters/bossorc.png");

  // potions
  texmgr.loadTexture("regen",   "assets/game/items/health_potion.png");
  texmgr.loadTexture("speed",    "assets/game/items/speed_potion.png");
  texmgr.loadTexture("strength", "assets/game/items/strength_potion.png");
}

