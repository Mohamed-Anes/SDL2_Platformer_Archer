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
    std::cout << "Initialized SDL" << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		std::cout << "IMG_Init: Couldn't start PNG support\nSDL_Error: " << IMG_GetError() << std::endl;
		Game::state = FAIL;
        return -1;
	}
    std::cout << "Initialized SDL Image" << std::endl;

    if(Game::window.Init() == -1){
        Game::state = FAIL;
        return -1;
    }
    std::cout << "Initialized Window" << std::endl;


    Sprite::loadSprites(std::string("src\\assets\\assets_config.txt"));
        // Sprite::loadSprites(std::string("assets-config.txt"));


    // --Temporary part for testing-- <TEMP>
    GameEntity *temp = new GameEntity();
    temp->loadAnimation(std::string("BGL1A"));
    entities.push_back(temp);
    temp = new GameEntity();
    temp->loadAnimation(std::string("PLAYER_IDLE"));
    entities.push_back(temp);
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
            Game::UpdateEntities();
            Game::window.Update();
            SDL_Delay(200);
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
        
        case SDL_WINDOWEVENT:
            if(event.window.event == SDL_WINDOWEVENT_RESIZED) {
                SDL_DestroyRenderer(window.renderer);
                Window::renderer = SDL_CreateRenderer(Window::window, -1, SDL_RENDERER_ACCELERATED);
                if(Window::renderer == nullptr){
		            std::cout << "SDL_Renderer could not be recreated\nSDL_Error: " << SDL_GetError() << std::endl;
	            }
                std::cout << "\nwindow resized\n";
                window.width = event.window.data1;
                window.height = event.window.data2;
            }
        default:
            break;
        }
    }

}

void Game::UpdateEntities() {
    	std::list<GameEntity *>::iterator it;
        
        for (it = entities.begin(); it != entities.end(); it++)
        {
            (*it)->draw();
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