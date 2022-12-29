#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "GameEntity.hpp"

class Player : public GameEntity
{
public:
    float vx, vy;
public:
    Player(int x, int y, int width, int height);
    ~Player();
    void update(float dt);

};





#endif // __PLAYER_HPP__
