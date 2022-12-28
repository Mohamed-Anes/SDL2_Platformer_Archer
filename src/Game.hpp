#ifndef __GAME_HPP__
#define __GAME_HPP__


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>

#include "window.hpp"
#include "Sprite.hpp"
#include "GameEntity.hpp"


enum GameState{
    LOAD,
    RUN,
    PAUSE,
    EXIT,
    FAIL
};

class Game
{
public:
    static Window window;
    static GameState state;

    // <TEMP>
    std::list<GameEntity *> entities;
    // <ENDTEMP>
public:
    // Constructor
    Game();
    // Destructor
    ~Game();
    // Initializer
    int Init();
    // Game loop
    int run();
    // Input handler
    void HandleInput();
    // Update entities
    void UpdateEntities();
};


#endif // __GAME_HPP__