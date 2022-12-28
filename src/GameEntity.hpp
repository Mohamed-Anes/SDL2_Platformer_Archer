#ifndef __GAMEENTITY_HPP__
#define __GAMEENTITY_HPP__

#include <string>

#include "Animation.hpp"

// Top level abstraction of an entity in the game, character or object, or background
class GameEntity
{
private:
    Animation *animation;
    int x, y;
public:
    // Constructor
    GameEntity();
    // Destructor
    ~GameEntity();
    // Sprite loader
    int loadAnimation(std::string animId);
    // Draw function
    void draw();
};





#endif // __GAMEENTITY_HPP__