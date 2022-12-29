#include "GameEntity.hpp"

#include <iostream>
#include <SDL2/SDL.h>

#include "Game.hpp"
#include "window.hpp"


GameEntity::GameEntity(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

GameEntity::GameEntity() {
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
    SDL_Rect src {
        (animation->x) + (animation->frameWidth * ((animation->currentFrame - 1)%animation->frameCount)),
        animation->y,
        animation->frameWidth,
        animation->height
    };
    animation->currentFrame += 1;
    SDL_Rect dest {x, y, width, height};

    SDL_RenderCopy(Window::renderer, animation->spriteSheet->texture, &src, &dest);
}


void GameEntity::update(float dt) {
}

