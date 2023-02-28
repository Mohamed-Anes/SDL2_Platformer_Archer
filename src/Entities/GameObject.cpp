#include "GameObject.hpp"

#include <iostream>
#include <SDL2/SDL.h>

#include "Game.hpp"
#include "window.hpp"


GameObject::GameObject(int x, int y, int width, int height, int nbStates):
    positionAndSize{x, y, width, height},
    nbStates(nbStates)
{
    state = IDLE;
    animations.resize(nbStates);
    for(int i = 0; i < nbStates; i++) {
        animations[i].sprite = nullptr;
        animations[i].currentFrame = 0;
        animations[i].elapsed = 0;
    }
    facing = RIGHT;
}

GameObject::GameObject() {
}

GameObject::~GameObject() {
}

int GameObject::loadAnimation(const std::string& animId, ObjectState state) {
    if(state >= nbStates) {
        std::cout << "Error state out of range" << std::endl;
        return -1;
    }
    animations[state].sprite = Sprite::spriteAtlas.at(animId);
    if(animations[state].sprite == nullptr) {
        std::cout << "Error accessing sprite from map" << std::endl;
        return -1;
    }
    return 0;
}

void GameObject::render(int camera_offset) {
    // <TEMP>
    SDL_Rect src = animations[state].sprite->positionAndSize;
    src.w = animations[state].sprite->frameWidth;
    src.x += src.w * animations[state].currentFrame;

    
    dest = {(int)positionAndSize.x - camera_offset, (int)positionAndSize.y, (int)positionAndSize.w, (int)positionAndSize.h};

    SDL_RenderCopyEx(Window::renderer, animations[state].sprite->spriteSheet, &src, &dest, NULL, NULL, facing);
    SDL_SetRenderDrawColor(Window::renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(Window::renderer, &(dest));
}


void GameObject::update(float dt) {
    // transitioning to the next frame
    animations[state].elapsed += (int)(dt*1000);
    if(animations[state].elapsed > animations[state].time_per_frame) {
        animations[state].currentFrame = ++animations[state].currentFrame % animations[state].sprite->frameCount;
        animations[state].elapsed -= animations[state].time_per_frame;
    }
}

// AABB collision detection, for use with player character and eventually NPCs
bool GameObject::isColliding(GameObject *other){
    if(
        this->positionAndSize.x < other->positionAndSize.x + other->positionAndSize.w &&
        this->positionAndSize.x + this->positionAndSize.w > other->positionAndSize.x &&
        this->positionAndSize.y < other->positionAndSize.y + other->positionAndSize.h &&
        this->positionAndSize.y + this->positionAndSize.h > other->positionAndSize.y
    ) {
        return true;
    }
    else {
        return false;
    }
}

