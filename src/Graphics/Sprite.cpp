#include "Sprite.hpp"


// Static definitions
std::map<const std::string, Sprite *> Sprite::spriteAtlas;

Sprite::Sprite(const std::string& animId, SDL_Texture *spriteSheet, int x, int y, int width, int height, int frameCount): 
    spriteSheet(spriteSheet),
    positionAndSize{x, y, width, height},
    frameCount(frameCount),
    frameWidth(width / frameCount)
{
    Sprite::addSpriteToMap(animId, this);
}

Sprite::~Sprite() {
}


inline int Sprite::addSpriteToMap(const std::string& animId, Sprite* newSprite) {
    Sprite::spriteAtlas.insert(std::make_pair(animId, newSprite));
}


