#include "Game.hpp"

#include <iostream>


Game::Game() {
    state = LOAD;
}

Game::~Game() {
    SDL_Quit();
}

int Game::Init() {
    Uint32 flags = SDL_INIT_VIDEO;
    if (SDL_Init(flags) < 0)
	{
		std::cout << "SDL_Init: Couldn't start SDL\nSDL_Error: " << SDL_GetError << std::endl;
		state = FAIL;
        return -1;
	}
    if(window.Init() == -1){
        state = FAIL;
        return -1;
    }

    state = RUN;
    return 0;
}

int Game::run() {
    while(state != EXIT) {
        switch (state)
        {
        case RUN:
            Game::HandleInput();
            break;

        case PAUSE:
            break;

        case FAIL:
            std::cout << "Exiting with errors" << std::endl;
            state = EXIT;
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
            state = EXIT;
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