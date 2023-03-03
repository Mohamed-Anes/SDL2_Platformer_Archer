#include "Player.hpp"
#include "Defs.hpp"
#include <iostream>

Player::Player(int x, int y, int width, int height, int nbStates): GameObject(x, y, width, height, nbStates) , vx(0), vy(0) {
    
}

Player::~Player() {
}

void Player::update(float dt) {
    ((GameObject *)this)->update(dt);
    positionAndSize.x += vx * dt;
    positionAndSize.y -= vy * dt;

    vy -= GRAVITY * dt;

    // std::cout << "x: " << positionAndSize.x << " y: " << positionAndSize.y << " vx: " << vx << " vy: " << vy << std::endl;

    // update animation state
    if(vx != 0) {
        state = ACTIVE;
    } else {
        state = IDLE;
    }
    // updating facing direction
    facing = (vx > 0)? RIGHT : facing;
    facing = (vx < 0)? LEFT : facing;
}

