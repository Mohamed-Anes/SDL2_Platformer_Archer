#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <SDL2/SDL.h>
#include <string>
#include <map>


// Wrapper class for the Textures map
class Sprite {
public:
    SDL_Texture *texture;
public:
    static std::map<std::string, Sprite *> spritesMap;
public:
    // Constructor, takes a png filename as an argument, 
    // x and y coordinates of the sprite in the sprite sheet, 
    // width and height of the sprite
    // TODO: add number of frames and their width and height for animation --done in Animation--
    // TODO2: x, y, w, h, nbFrames will be transfered to the class Animation --done--
    Sprite(std::string spriteId, std::string filename);
    // Destructor
    ~Sprite();

    // Add a sprite to the map
    static inline int addSpriteToMap(std::string spriteId, Sprite* newSprite);

    static int loadSprites(std::string configfname);

};





#endif // __SPRITE_HPP__