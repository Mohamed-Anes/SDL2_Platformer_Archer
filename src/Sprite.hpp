#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__

#include <SDL2/SDL.h>
#include <string>
#include <map>

class Sprite {
public:
    SDL_Texture *texture;
public:
    static std::map<std::string, Sprite *> sprites;
public:
    // Constructor, takes a png filename as an argument, 
    // x and y coordinates of the sprite in the sprite sheet, 
    // width and height of the sprite
    // TODO: add number of frames and their width and height for animation
    // TODO2: x, y, w, h, nbFrames will be transfered to the class Animation
    Sprite(std::string filename, int x, int y, int width, int height);
    // Destructor
    ~Sprite();

    static int loadSprites(std::string configfname);

};





#endif // __SPRITE_HPP__