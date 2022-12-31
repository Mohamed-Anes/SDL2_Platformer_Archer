#ifndef __SPRITESHEET_HPP__
#define __SPRITESHEET_HPP__

#include <SDL2/SDL.h>
#include <string>
#include <map>


// Wrapper class for the Textures map
class SpriteSheet {
public:
    static std::map<const std::string, SDL_Texture *> spriteSheetAtlas;
public:
    // Constructor, takes a png filename and a sprite ID, loads the texture and adds it to the map
    SpriteSheet(const std::string& spriteId, const std::string& filename);
    // Destructor
    ~SpriteSheet();

    // Add a sprite to the map
    static inline int addSpriteSheetToMap(const std::string& spriteId, SDL_Texture* newSpriteSheet);
    // Load all sprites specified in the configuration file
    static int loadSpriteSheets(const std::string& configfname);
    // Destroy all textures
    static void destroyAllSpriteSheets();
};





#endif // __SPRITESHEET_HPP__