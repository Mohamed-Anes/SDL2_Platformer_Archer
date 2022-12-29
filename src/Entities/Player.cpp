#include "Player.hpp"

#include <iostream>

Player::Player(int x, int y, int width, int height): vx(0), vy(0) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Player::~Player() {
}

void Player::update(float dt) {
    x += vx * dt;
    y += vy * dt;
    std::cout << "x: " << x << " y: " << y << std::endl;
}

