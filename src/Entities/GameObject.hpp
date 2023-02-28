#ifndef __GAMEOBJECT_HPP__
#define __GAMEOBJECT_HPP__

#include <string>
#include <vector>

#include "Sprite.hpp"


struct Animation {
    Sprite *sprite;
    int currentFrame;
    const int time_per_frame = 120;
    int elapsed;
};

enum ObjectState {
    IDLE = 0, ACTIVE, PAUSED
};

// objects face to the right by default
#define RIGHT SDL_FLIP_NONE
#define LEFT SDL_FLIP_HORIZONTAL


// replaced by an enum of player state and a vector of possible animations accessed by the enum
// typedef std::pair<std::string, Animation *> namedAnimation;

// Top level abstraction of an entity in the game, character or object, or background
class GameObject
{
public:
    ObjectState state;
    int nbStates;
    std::vector<Animation> animations;
    SDL_FRect positionAndSize; // add SDL_Rect if needed to send position
    SDL_Rect dest; // for rendering
    SDL_RendererFlip facing;
public:
    // Constructor
    // TODO: Transfer these arguments somewhere else
    GameObject(int x, int y, int width, int height, int nbStates);
    // Default Constructor
    GameObject();
    // Destructor
    ~GameObject();
    // Sprite loader
    int loadAnimation(const std::string& animId, ObjectState state);
    // Draw function
    void render();
    // Update <TEMP>
    void update(float dt);

    bool isColliding(GameObject *other);
};





#endif // __GAMEOBJECT_HPP__