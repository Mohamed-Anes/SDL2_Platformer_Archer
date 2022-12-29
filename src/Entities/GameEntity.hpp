#ifndef __GAMEENTITY_HPP__
#define __GAMEENTITY_HPP__

#include <string>

#include "Animation.hpp"

// replaced by an enum of player state and a vector of possible animations accessed by the enum
// typedef std::pair<std::string, Animation *> namedAnimation;

// Top level abstraction of an entity in the game, character or object, or background
class GameEntity
{
protected:
    
    Animation *animation;
    float x, y;
    int width, height;
public:
    // Constructor
    // TODO: Transfer these arguments somewhere else
    GameEntity(int x, int y, int width, int height);
    // Default Constructor
    GameEntity();
    // Destructor
    ~GameEntity();
    // Sprite loader
    int loadAnimation(std::string animId);
    // Draw function
    void draw();
    // Update <TEMP>
    void update(float dt);
};





#endif // __GAMEENTITY_HPP__