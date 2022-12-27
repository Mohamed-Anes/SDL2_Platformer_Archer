#include "GameEntity.hpp"

#include <iostream>

#include "Game.hpp"
#include "window.hpp"


GameEntity::GameEntity() {
    x = 0;
    y = 0;
}

GameEntity::~GameEntity() {
}

int GameEntity::loadSprite(std::string spriteId) {
    Spr = Sprite::sprites.at(spriteId);
    if(Spr == nullptr) {
        std::cout << "Error accessing sprite from map" << std::endl;
        return -1;
    }
    return 0;
}

void GameEntity::draw() {
    SDL_RenderCopy(Window::renderer, Spr->texture, 0, 0);
}



