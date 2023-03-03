#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "GameObject.hpp"

class Player : public GameObject
{
public:
    float vx, vy;
public:
    Player(int x, int y, int width, int height, int nbStates);
    ~Player();
    void update(float dt);
    
};





#endif // __PLAYER_HPP__
