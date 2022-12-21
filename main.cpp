#include <iostream>
#include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>

using namespace std;

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("platformer", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Delay(1000);

    SDL_DestroyWindow(win);
    SDL_Quit();

    cout << "Hello world!" << endl;
    return 0;
}
