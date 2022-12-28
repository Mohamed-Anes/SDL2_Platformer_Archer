#include "Sprite.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>

#include "window.hpp"
#include "Animation.hpp"

// Static definitions
std::map<std::string, Sprite *> Sprite::spritesMap;

Sprite::Sprite(std::string spriteId, std::string filename) {
    SDL_Surface *tempSurf;
    if(!(tempSurf = IMG_Load(filename.c_str()))) {
        std::cout << "Error loading the file:" << filename << "\nSDL Error: " << SDL_GetError() << std::endl;
    }
    ;
    if(!(texture = SDL_CreateTextureFromSurface(Window::renderer, tempSurf))) {
        std::cout << "Error creating the texture for the file:" << filename << "\nSDL Error: " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(tempSurf);
    Sprite::addSpriteToMap(spriteId, this);
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
    // loading individual sprite sheets
    std::string spriteId, tempfilename;
    int numOfAnimations;
    Sprite *tempSprite = nullptr;
    while(config.good()) {
        config >> spriteId >> tempfilename >> numOfAnimations;
        std::cout << "--loading sprite: " << spriteId << " " << tempfilename << " " << numOfAnimations << std::endl;
        tempSprite = new Sprite(spriteId, tempfilename); // creating + adding to map
        // Error check
        if(tempSprite == nullptr) {
            std::cout << "Error loading sprite" << std::endl;
            continue;
        }
        
        // loading individual animations
        std::string animId;
        int x, y, width, height, frameCount;
        Animation *tempAnimation = nullptr;
        for(int i = 0; i < numOfAnimations; ++i) {
            config >> animId >> x >> y >> width >> height >> frameCount;
            std::cout << "----loading animation: " << animId << " " << x << " " << y << " " << width << " " << height << " " << frameCount << std::endl;
            tempAnimation = new Animation(animId, tempSprite, x, y, width, height, frameCount);
            // Error check
            if(tempAnimation== nullptr) {
                std::cout << "Error loading animation" << std::endl;
                continue;
            }
            // clearing previous values
            animId.clear();
            tempAnimation = nullptr;
        }

        // clear previous values
        spriteId.clear();
        tempfilename.clear();
        tempSprite = nullptr;

        // // read values from the file
        // config >> spriteId;
        // config >> tempfilename;
        // config >> x >> y >> width >> height;
        // // tempSprite = new Sprite(tempfilename, x, y, width, height);
        // // add sprite to the map
        // Sprite::spritesMap.insert(std::pair<std::string, Sprite *>(spriteId, new Sprite(tempfilename)));
        // // clear strings
        // spriteId.clear();
        // tempfilename.clear();
    }
    return 0;

}


inline int Sprite::addSpriteToMap(std::string spriteId, Sprite* newSprite) {
    Sprite::spritesMap.insert(std::pair<std::string, Sprite *>(spriteId, newSprite));
}

