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

int GameEntity::loadAnimation(std::string animId) {
    animation = Animation::animationsMap.at(animId);
    if(animation == nullptr) {
        std::cout << "Error accessing sprite from map" << std::endl;
        return -1;
    }
    return 0;
}

void GameEntity::draw() {
    // <TEMP>
    SDL_Rect src, dest;
    src.x = animation->x;
    src.y = animation->y;
    src.w = animation->frameWidth;
    src.h = animation->height;
    SDL_RenderCopy(Window::renderer, animation->spriteSheet->texture, &src, &src);
}



