#ifndef __GAME_HPP__
#define __GAME_HPP__


#include <SDL2/SDL.h>

#include "window.hpp"


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
    Window window;
    GameState state;
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
};


#endif // __GAME_HPP__