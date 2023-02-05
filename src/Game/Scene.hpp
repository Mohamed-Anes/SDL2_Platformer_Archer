#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <list>

#include "GameObject.hpp"
#include "Player.hpp"

// TODO: make a constructor that would take a list of all initial objects
// TODO: make update and render methods only execute on elements within Camera
class Scene
{
private:
    std::list<GameObject *> objects;
    SDL_Rect Camera;
public:
    Player *player;
public:
    // Constructor
    Scene();
    // Destructor
    ~Scene();
    // update all objects
    void update(float dt);
    // render all objects
    void render();
    // add object
    void addObject(GameObject *object);
    // remove object
    void removeObject(GameObject *object);
    //
    void resolveCollisions();
};


#endif // __SCENE_HPP__