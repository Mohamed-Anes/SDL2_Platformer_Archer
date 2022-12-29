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
    // Constructor, takes a png filename and a sprite ID, loads the texture and adds it to the map
    Sprite(std::string spriteId, std::string filename);
    // Destructor
    ~Sprite();

    // Add a sprite to the map
    static inline int addSpriteToMap(std::string spriteId, Sprite* newSprite);
    // Load all sprites specified in the configuration file
    static int loadSprites(std::string configfname);

};





#endif // __SPRITE_HPP__