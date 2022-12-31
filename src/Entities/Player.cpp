#include "Player.hpp"

#include <iostream>

Player::Player(int x, int y, int width, int height, int nbStates): GameObject(x, y, width, height, nbStates) , vx(0), vy(0) {
    
}

Player::~Player() {
}

void Player::update(float dt) {
    positionAndSize.x += vx * dt;
    positionAndSize.y += vy * dt;
}

