#ifndef __GAME_HPP__
#define __GAME_HPP__


#include <SDL2/SDL.h>


enum GameState{
    RUN,
    PAUSE,
    EXIT
};

class Game
{
private:
    SDL_Window *window;
    GameState state;
public:
    // Constructor
    Game();
    // Destructor
    ~Game();

    // game loop
    int run();
};


#endif // __GAME_HPP__