#ifndef __GAMEENTITY_HPP__
#define __GAMEENTITY_HPP__

#include <string>

#include "Sprite.hpp"

// Top level abstraction of an entity in the game, character or object, or background
class GameEntity
{
private:
    Sprite *Spr;
    int x, y;
public:
    // Constructor
    GameEntity();
    // Destructor
    ~GameEntity();
    // Sprite loader
    int loadSprite(std::string spriteId);
    // Draw function
    void draw();
};





#endif // __GAMEENTITY_HPP__