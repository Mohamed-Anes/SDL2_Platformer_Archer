
#include "SpriteSheet.hpp"

#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>

#include "window.hpp"
#include "Sprite.hpp"

// Static definitions
std::map<const std::string, SDL_Texture *> SpriteSheet::spriteSheetAtlas;

SpriteSheet::SpriteSheet(const std::string& spriteId, const std::string& filename) {
    SDL_Surface *tempSurf;
    if(!(tempSurf = IMG_Load(filename.c_str()))) {
        std::cout << "Error loading the file:" << filename << "\nSDL Error: " << SDL_GetError() << std::endl;
    }
    SDL_Texture *tempText;
    if(!(tempText = SDL_CreateTextureFromSurface(Window::renderer, tempSurf))) {
        std::cout << "Error creating the texture for the file:" << filename << "\nSDL Error: " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(tempSurf);
    SpriteSheet::addSpriteSheetToMap(spriteId, tempText);
}

SpriteSheet::~SpriteSheet() {
}


int SpriteSheet::loadSpriteSheets(const std::string& configfname) {
    std::ifstream config(configfname.c_str());

    if(!config.is_open()) {
        std::cout << "Error opening the file: " << configfname << std::endl;
        return -1;
    }
    // loading individual sprite sheets
    std::string spriteId, tempfilename;
    int numOfSprites;
    SpriteSheet *tempSpriteSheet = nullptr;
    while(config.good()) {
        config >> spriteId >> tempfilename >> numOfSprites;
        std::cout << "--loading sprite sheet: " << spriteId << " " << tempfilename << " " << numOfSprites << std::endl;
        tempSpriteSheet = new SpriteSheet(spriteId, tempfilename); // creating + adding to map
        // Error check
        if(tempSpriteSheet == nullptr) {
            std::cout << "Error loading sprite sheet" << std::endl;
            continue;
        }
        
        // loading individual sprites
        std::string animId;
        int x, y, width, height, frameCount;
        Sprite *tempSprite = nullptr;
        for(int i = 0; i < numOfSprites; ++i) {
            config >> animId >> x >> y >> width >> height >> frameCount;
            std::cout << "----loading sprite: " << animId << " " << x << " " << y << " " << width << " " << height << " " << frameCount << std::endl;
            tempSprite = new Sprite(animId, SpriteSheet::spriteSheetAtlas.at(spriteId), x, y, width, height, frameCount);
            // Error check
            if(tempSprite == nullptr) {
                std::cout << "Error loading sprite" << std::endl;
                continue;
            }
            // clearing previous values
            animId.clear();
            tempSprite = nullptr;
        }

        // clear previous values
        spriteId.clear();
        tempfilename.clear();
        tempSprite = nullptr;
    }
    return 0;

}


inline int SpriteSheet::addSpriteSheetToMap(const std::string& spriteId, SDL_Texture* newSpriteSheet) {
    SpriteSheet::spriteSheetAtlas.insert(std::make_pair(spriteId, newSpriteSheet));
}

void SpriteSheet::destroyAllSpriteSheets() {
    for(auto it = SpriteSheet::spriteSheetAtlas.begin(); it != SpriteSheet::spriteSheetAtlas.end(); it++) {
        SDL_DestroyTexture(it->second);
    }
}