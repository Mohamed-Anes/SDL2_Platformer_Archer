#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include "SpriteSheet.hpp"

#include <map>
#include <string>

// Normal class and wrapper for Sprites map
// Only works with horizontal animations of constant width
class Sprite
{
public:
    static std::map<const std::string, Sprite *> spriteAtlas;
    // TODO: change the x, u, w, h into vectors, change the int into uint
    SDL_Texture *spriteSheet;
    SDL_Rect positionAndSize;
    int frameCount;
    int frameWidth;
    
public:
    Sprite(const std::string& animId, SDL_Texture *spriteSheet, int x, int y, int width, int height, int frameCount);
    ~Sprite();
    static inline int addSpriteToMap(const std::string& animId, Sprite* newSprite);
};






#endif // __SPRITE_HPP__
