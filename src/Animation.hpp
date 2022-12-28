#ifndef __ANIMATION_HPP__
#define __ANIMATION_HPP__

#include "Sprite.hpp"

#include <map>
#include <string>

// Normal class and wrapper for Animations map
// Only works with horizontal animations of constant width
class Animation
{
public:
    static std::map<std::string, Animation *> animationsMap;
    // TODO: change the x, u, w, h into vectors, change the int into uint
    Sprite *spriteSheet;
    int x, y, width, height;
    int frameCount;
    int frameWidth;
public:
    Animation(std::string animId, Sprite *spriteSheet, int x, int y, int width, int height, int frameCount);
    ~Animation();
    static inline int addAnimationToMap(std::string animId, Animation* newAnimation);
};






#endif // __ANIMATION_HPP__
