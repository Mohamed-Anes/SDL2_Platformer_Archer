#include "Animation.hpp"


// Static definitions
std::map<std::string, Animation *> Animation::animationsMap;

Animation::Animation(std::string animId, Sprite *spriteSheet, int x, int y, int width, int height, int frameCount) {
    this->spriteSheet = spriteSheet;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->frameCount = frameCount;
    this->frameWidth = width/frameCount;
    this->currentFrame = 1;
    Animation::addAnimationToMap(animId, this);
}

Animation::~Animation() {
}


inline int Animation::addAnimationToMap(std::string animId, Animation* newAnimation) {
    Animation::animationsMap.insert(std::pair<std::string, Animation *>(animId, newAnimation));
}


