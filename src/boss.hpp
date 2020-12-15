#include "enemy.hpp"
#ifndef BOSS_HPP
#define BOSS_HPP

class Boss : public Enemy {
  public:
    Boss() { };
    Boss(sf::Texture& texture);
    void addFrames(thor::FrameAnimation& animation, int x, int yFirst, int yLast, float duration = 1.f);
    void initAnimation();
};

#endif // BOSS_HPP