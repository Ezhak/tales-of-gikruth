#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "boss.hpp"
#include "potion.hpp"

class Level {
  public:
    Level() {}

    void setBosses(std::vector<Boss> bosses) { this->bosses = bosses; }
    void setEnemies(std::vector<Enemy> enemies) { this->enemies = enemies; }
    void setMap(sf::Sprite& mapSprite) { this->mapSprite = mapSprite; }
    void setPlayerClass(std::string className);
    void setPotionAtlas(std::map<std::string, Potion> potionAtlas) { this->potionAtlas = potionAtlas; }
    void setTriggerFinish(sf::FloatRect triggerFinish) { this->triggerFinish = triggerFinish; }
    void setTriggerNextLevel(sf::FloatRect triggerNextLevel) { this->triggerNextLevel = triggerNextLevel; }
    void setWallRects(std::vector<sf::FloatRect> wallRects);

    void attack(Character player);
    bool collides(Character player, movement_type movementType);
    void draw(sf::RenderWindow& window);
    void drop(sf::Vector2f position);
    void idle();
    void initAnimation();
    void injure(Character& player);
    void pickPotion(Character& player);
    bool triggersFinish(Character player);
    bool triggersNext(Character player);
    void update(const sf::Time dt);
  private:
    sf::SoundBuffer attackSoundBuffer;
    std::vector<Boss> bosses;
    std::vector<Enemy> enemies;
    std::map<std::string, Potion> potionAtlas;
    std::vector<Potion> potions;
    sf::SoundBuffer injureSoundBuffer;
    sf::Sprite mapSprite;
    sf::Sound sound;
    sf::FloatRect triggerNextLevel;
    sf::FloatRect triggerFinish;
    std::vector<sf::FloatRect> wallRects;
};

#endif // LEVEL_HPP
