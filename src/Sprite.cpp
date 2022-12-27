#include "Sprite.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>

#include "window.hpp"

// Static definitions
std::map<std::string, Sprite *> Sprite::sprites;

Sprite::Sprite(std::string filename, int x, int y, int width, int height) {
    SDL_Surface *tempSurf;
    if(!(tempSurf = IMG_Load(filename.c_str()))) {
        std::cout << "Error loading the file:" << filename << "\nSDL Error: " << SDL_GetError() << std::endl;
    }
    ;
    if(!(texture = SDL_CreateTextureFromSurface(Window::renderer, tempSurf))) {
        std::cout << "Error creating the texture for the file:" << filename << "\nSDL Error: " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(tempSurf);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}


int Sprite::loadSprites(std::string configfname) {
    std::ifstream config(configfname.c_str());

    if(!config.is_open()) {
        std::cout << "Error opening the file: " << configfname << std::endl;
        return -1;
    }
    std::string spriteId;
    std::string tempfilename;
    int x, y, width, height;
    // Sprite *tempSprite;
    while(config.good()) {
        // read values from the file
        config >> spriteId;
        config >> tempfilename;
        config >> x >> y >> width >> height;
        // tempSprite = new Sprite(tempfilename, x, y, width, height);
        // add sprite to the map
        Sprite::sprites.insert(std::pair<std::string, Sprite *>(spriteId, new Sprite(tempfilename, x, y, width, height)));
        // clear strings
        spriteId.clear();
        tempfilename.clear();
    }
    return 0;

}



