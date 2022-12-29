#ifndef __GAMEOBJECT_HPP__
#define __GAMEOBJECT_HPP__

#include "GameEntity.hpp"

class GameObject : GameEntity
{
private:
    
public:
    GameObject(int x, int y, int width, int height);
    ~GameObject();

};






#endif // __GAMEOBJECT_HPP__