#include <SFML/Graphics.hpp>

#include "level.hpp"
#include <iostream>

void Level::setPlayerClass(std::string className)
{
  this->injureSoundBuffer.loadFromFile("assets/sound/injure.wav");

  if (className == "dragon")
    this->attackSoundBuffer.loadFromFile("assets/sound/dragon_attack.wav");
  else if (className == "knight")
    this->attackSoundBuffer.loadFromFile("assets/sound/knight_attack.wav");
  else if (className == "mage")
    this->attackSoundBuffer.loadFromFile("assets/sound/mage_attack.wav");
}

void Level::setWallRects(std::vector<sf::FloatRect> wallRects)
{
 this->wallRects = wallRects;
}

void Level::attack(Character player) 
{
  for (auto& enemy: this->enemies) {
    if (player.collides(enemy)) {
      this->sound.setBuffer(this->attackSoundBuffer);
      player.attack(enemy, this->sound);
    }
  }

  for (auto& boss: this->bosses) {
    if (player.collides(boss)) {
      this->sound.setBuffer(this->attackSoundBuffer);
      player.attack(boss, this->sound);
    }
  }
}

bool Level::collides(Character player, movement_type movementType)
{
  for (auto wall : this->wallRects) 
    if (player.collides(wall, movementType))
      return true;

  return false;
}


void Level::draw(sf::RenderWindow& window)
{
  window.draw(this->mapSprite);

  for (auto& enemy : this->enemies)
    enemy.draw(window);

  for (auto& boss : this->bosses)
    boss.draw(window);

  for (auto& potion : this->potions)
    potion.draw(window);
}

void Level::drop(sf::Vector2f position) {
  int drops = rand() % 10;
  if (drops > 3)
    return;

  srand(time(NULL));
  int type = rand() % 3;
  int offset = 10;
  int value;


  switch (type) {
  case 0:
    value = rand() % 2 + 3;
    this->potionAtlas["regen"].setEffectValue(value);
    this->potionAtlas["regen"].setPosition(position.x + offset, position.y);
    // this->potionAtlas["regen"].initAnimation();
    this->potions.push_back(this->potionAtlas["regen"]);
    break;
  case 1:
    value = rand() % 3 + 2;
    this->potionAtlas["speed"].setEffectValue(value);
    this->potionAtlas["speed"].setPosition(position.x + offset, position.y);
    // this->potionAtlas["speed"].initAnimation();
    this->potions.push_back(this->potionAtlas["speed"]);
    break;
  case 2:
    value = rand() % 2 + 3;
    // value /= 2;
    this->potionAtlas["strength"].setEffectValue(value);
    this->potionAtlas["strength"].setPosition(position.x + offset, position.y);
    // this->potionAtlas["strength"].initAnimation();
    this->potions.push_back(this->potionAtlas["strength"]);
    break;
  default:
    break;
  }
}

void Level::idle()
{
  for (auto& enemy : this->enemies)
    enemy.idle();

  for (auto& boss : this->bosses)
    boss.idle();

  // for (auto& potion : this->potions)
  //   potion.idle();
}

void Level::initAnimation()
{
  for (auto& enemy : this->enemies)
    enemy.initAnimation();

  for (auto& boss : this->bosses)
    boss.initAnimation();

  // for (auto& potion : this->potions)
  //   potion.initAnimation();
}

void Level::injure(Character& player)
{
  for (auto& enemy: this->enemies) {
    if (player.collides(enemy)) {
      this->sound.setBuffer(this->injureSoundBuffer);
      enemy.injure(player, this->sound);
    }
  }

  for (auto& boss: this->bosses) {
    if (player.collides(boss)) {
      this->sound.setBuffer(this->injureSoundBuffer);
      boss.injure(player, this->sound);
    }
  }
}

bool Level::triggersFinish(Character player)
{
  return player.collides(this->triggerFinish);
}

bool Level::triggersNext(Character player)
{
  return player.collides(this->triggerNextLevel);
}

void Level::pickPotion(Character& player) {
  for (auto& potion: this->potions) {
    if (player.collides(potion)) {
      potion.pick();
      potion.effect(player);
    }
  }
}

void Level::update(const sf::Time dt)
{
  for (auto& enemy : this->enemies) {
    if (enemy.dead() && !enemy.getDropped()) {
      enemy.setDropped();
      this->drop(enemy.getPosition());
    }
    enemy.update(dt);
  }

  for (auto& boss : this->bosses)
    boss.update(dt);

  // for (auto& potion : this->potions)
  //   potion.update(dt);
}
