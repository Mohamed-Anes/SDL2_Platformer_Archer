#include "Game.hpp"

#include <iostream>
#include <string>

#include "Sprite.hpp"
#include "GameEntity.hpp"


// Static definitions
Window Game::window;
GameState Game::state;

Game::Game() {
    Game::state = LOAD;
}

Game::~Game() {
    SDL_Quit();
}

int Game::Init() {
    Uint32 flags = SDL_INIT_VIDEO;
    if (SDL_Init(flags) < 0)
	{
		std::cout << "SDL_Init: Couldn't start SDL\nSDL_Error: " << SDL_GetError() << std::endl;
		Game::state = FAIL;
        return -1;
	}

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "IMG_Init: Couldn't start PNG support\nSDL_Error: " << IMG_GetError() << std::endl;
		Game::state = FAIL;
        return -1;
	}
    if(Game::window.Init() == -1){
        Game::state = FAIL;
        return -1;
    }

    Sprite::loadSprites(std::string("src/assets/assets-config.txt"));

    // --Temporary part for testing-- <TEMP>
    GameEntity testEntity;
    testEntity.loadSprite(std::string("BGL1"));
    testEntity.draw();
    SDL_Rect rectangle;
    rectangle.h = 50;
    rectangle.w = 50;
    rectangle.x = 50;
    rectangle.y = 50;
    SDL_RenderDrawRect(Window::renderer, &rectangle);
    // <ENDTEMP>

    Game::state = RUN;
    return 0;
}

int Game::run() {
    while(Game::state != EXIT) {
        switch (Game::state)
        {
        case RUN:
            Game::HandleInput();
            Game::window.Update();
            break;

        case PAUSE:
            break;

        case FAIL:
            std::cout << "Exiting with errors" << std::endl;
            Game::state = EXIT;
            break;
        case EXIT:
            break;
        case LOAD:
            break;
        default:
            break;
        }
    }
    return 0;
}

void Game::HandleInput() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            Game::state = EXIT;
            break;
        
        default:
            break;
        }
    }
}


// for looping in functions

// void App::AddModule(Module* module)
// {
// 	module->Init();
// 	modules.push_back(module);
// }

// bool App::Awake() {
// 	// load configuration files, get app title, organisation, framerate cap
// 	// if config file loaded loop modules and apply Awake() method
// 	std::list<Module *>::iterator it;
// 	for (it = modules.begin(); it != modules.end(); it++)
// 	{
// 		(*it)->Awake();
// 	}
// 	return true;
// }