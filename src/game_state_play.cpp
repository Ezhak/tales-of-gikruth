#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "game_state_play.hpp"
#include "game_state_start.hpp"
#include "level.hpp"

GameStatePlay::GameStatePlay(Game* game, std::string className)
{
  this->className = className;
  this->game = game;
  this->position = sf::Vector2f(this->game->window.getSize());
  this->guiView.setSize(this->position);
  this->gameView.setSize(this->position);
  this->position *= 0.5f;
  this->guiView.setCenter(this->position);
  this->gameView.setCenter(this->position);

  this->background.setTexture(this->game->texmgr.getRef("game_background"));

  this->attackSoundBuffer.loadFromFile("assets/sound/swing.wav");

  this->playTheme.openFromFile("assets/music/play.wav");
  this->playTheme.setLoop(true);
  this->playTheme.play();

  this->initLevel(this->position, this->className);

  this->gameView.zoom(0.666f);

  // Create gui elements
}

void GameStatePlay::draw(const sf::Time dt)
{
  this->game->window.clear(sf::Color::Black);

  this->game->window.setView(this->guiView);
  this->game->window.draw(this->background);
  
  this->game->window.setView(this->gameView);

  this->level.draw(this->game->window);
  this->player.draw(this->game->window);

  this->game->window.setView(this->guiView);
  for (auto gui : this->guiSystem)
    this->game->window.draw(gui.second);

  return;
}

void GameStatePlay::handleInput()
{
  this->level.idle();

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
      !this->level.collides(this->player, movement_type::UP))
    this->player.move(movement_type::UP);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
           !this->level.collides(this->player, movement_type::DOWN))
    this->player.move(movement_type::DOWN);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
           !this->level.collides(this->player, movement_type::LEFT))
    this->player.move(movement_type::LEFT);

  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
           !this->level.collides(this->player, movement_type::RIGHT))
    this->player.move(movement_type::RIGHT);

  else this->player.idle();

  sf::Event event;

  // sf::Vector2f guiPos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->guiView);
  // sf::Vector2f gamePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->gameView);
  
  while(this->game->window.pollEvent(event)) {
    switch(event.type) {
    case sf::Event::KeyPressed:
      if (event.key.code == sf::Keyboard::Space) {
        this->sound.setBuffer(this->attackSoundBuffer);
        this->sound.setVolume(50.f);
        this->sound.play();
        this->level.attack(this->player);
      }
      break;
    // close the window
    case sf::Event::Closed:
      this->game->window.close();
      break;
    default: break;
    }
  }

  return;
}

void GameStatePlay::initLevel(sf::Vector2f position, std::string className)
{
  this->game->characterAtlas[className].setPosition(300, 275);

  this->player = this->game->characterAtlas[className];
  this->player.initAnimation();

  std::vector<Enemy> enemies;

  this->game->enemyAtlas["orc"].setPosition(500, 275);
  this->game->enemyAtlas["orc"].flip();
  enemies.push_back(this->game->enemyAtlas["orc"]);

  this->game->enemyAtlas["skelly"].setPosition(350, 430);
  enemies.push_back(this->game->enemyAtlas["skelly"]);

  this->game->enemyAtlas["skelly"].setPosition(350, 460);
  enemies.push_back(this->game->enemyAtlas["skelly"]);

  sf::Vector2i mapOrigin(160, 130);
  this->game->mapAtlas["1"].setPosition(position);
  this->game->mapAtlas["1"].setOrigin(mapOrigin.x, mapOrigin.y);

  sf::FloatRect trigger(275, 428, 10, 3);

  this->level = Level();
  this->level.setEnemies(enemies);
  this->level.setMap(this->game->mapAtlas["1"]);
  this->level.setPotionAtlas(this->game->potionAtlas);
  this->level.setTriggerNextLevel(trigger);
  this->level.setPlayerClass(className);

  std::vector<sf::FloatRect> wallRects;
  std::ifstream file("assets/map_1.txt");
  std::vector<int> tileIDVector;
  int tileID;

  while(file >> tileID)
    tileIDVector.push_back(tileID);

  for (long unsigned int i = 0; i < tileIDVector.size(); i++) {
    if (!tileIDVector.at(i))
      continue;

    // required for identifying tiles
    // tileIDArray.at(i) -= 1;

    sf::FloatRect collidableRect((i % this->mapTiles * this->tileSize) + position.x - mapOrigin.x,
                               (i / this->mapTiles * this->tileSize) + position.y - mapOrigin.y,
                               this->tileSize, this->tileSize);

    wallRects.push_back(collidableRect);
  }
  
  this->level.setWallRects(wallRects);
  this->level.initAnimation();
}

void GameStatePlay::nextLevel()
{
  std::vector<Enemy> enemies;

  this->game->enemyAtlas["demon"].setPosition(380, 250);
  this->game->enemyAtlas["demon"].flip();
  enemies.push_back(this->game->enemyAtlas["demon"]);

  this->game->enemyAtlas["demon"].setOrigin(340, 250);
  this->game->enemyAtlas["demon"].flip();
  enemies.push_back(this->game->enemyAtlas["demon"]);

  this->game->enemyAtlas["skelly"].setPosition(300, 250);
  enemies.push_back(this->game->enemyAtlas["skelly"]);

  this->game->enemyAtlas["skelly"].setPosition(300, 280);
  this->game->enemyAtlas["skelly"].flip();
  enemies.push_back(this->game->enemyAtlas["skelly"]);

  this->game->enemyAtlas["tinyorc"].setPosition(340, 320);
  this->game->enemyAtlas["tinyorc"].flip();
  enemies.push_back(this->game->enemyAtlas["tinyorc"]);

  this->game->enemyAtlas["tinydemon"].setPosition(380, 280);
  this->game->enemyAtlas["tinydemon"].flip();
  enemies.push_back(this->game->enemyAtlas["tinydemon"]);

  std::vector<Boss> bosses;

  this->game->bossAtlas["bossdemon"].setPosition(340, 280);
  this->game->bossAtlas["bossdemon"].flip();
  bosses.push_back(this->game->bossAtlas["bossdemon"]);

  this->game->bossAtlas["bossorc"].setPosition(480, 250);
  bosses.push_back(this->game->bossAtlas["bossorc"]);

  sf::Vector2i mapOrigin(160, 130);
  this->game->mapAtlas["2"].setPosition(this->position);
  this->game->mapAtlas["2"].setOrigin(mapOrigin.x, mapOrigin.y);

  sf::FloatRect trigger(515, 248, 10, 3);

  this->level.setBosses(bosses);
  this->level.setEnemies(enemies);
  this->level.setMap(this->game->mapAtlas["2"]);
  this->level.setTriggerFinish(trigger);

  std::vector<sf::FloatRect> wallRects;
  std::ifstream file("assets/map_2.txt");
  std::vector<int> tileIDVector;
  int tileID;

  while(file >> tileID)
    tileIDVector.push_back(tileID);

  for (long unsigned int i = 0; i < tileIDVector.size(); i++) {
    if (!tileIDVector.at(i))
      continue;

    // required for identifying tiles
    // tileIDArray.at(i) -= 1;

    sf::FloatRect collidableRect((i % this->mapTiles * this->tileSize) + position.x - mapOrigin.x,
                               (i / this->mapTiles * this->tileSize) + position.y - mapOrigin.y,
                               this->tileSize, this->tileSize);

    wallRects.push_back(collidableRect);
  }
  
  this->level.setWallRects(wallRects);
  this->level.initAnimation();
}

void GameStatePlay::update(const sf::Time dt)
{
  this->level.update(dt);
  this->player.update(dt);

  if (this->player.dead()) {
    this->playTheme.stop();
    this->game->pushState(new GameStateStart(this->game));
  }

  this->level.pickPotion(this->player);

  if (this->level.triggersNext(this->player))
    this->nextLevel();

  if (this->level.triggersFinish(this->player)) {
    this->playTheme.stop();
    this->game->pushState(new GameStateStart(this->game));
  }

  timeElapsed += (float)dt.asSeconds();
  if (timeElapsed > 1.f) {
    this->level.injure(this->player);
    this->timeElapsed = 0.f;
  }

  return;
}
