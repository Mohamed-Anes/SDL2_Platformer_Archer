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
    }
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

void GameObject::render() {
    // <TEMP>
    SDL_Rect src = animations[state].sprite->positionAndSize;
    src.w = animations[state].sprite->frameWidth;
    src.x += src.w * animations[state].currentFrame;

    // animations[state].currentFrame += 1;
    animations[state].currentFrame = ++animations[state].currentFrame % animations[state].sprite->frameCount;

    dest = {(int)positionAndSize.x, (int)positionAndSize.y, (int)positionAndSize.w, (int)positionAndSize.h};

    SDL_RenderCopy(Window::renderer, animations[state].sprite->spriteSheet, &src, &dest);
}


void GameObject::update(float dt) {
}

