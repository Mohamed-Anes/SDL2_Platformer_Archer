#include "Game.hpp"

#include <iostream>
#include <string>

#include "Sprite.hpp"
#include "GameEntity.hpp"
#include "Defs.hpp"
#include "Player.hpp"

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
    GameEntity *temp;
    // background
    temp = new GameEntity(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    temp->loadAnimation(std::string("BGL1A"));
    entities.push_back(temp);
    // player
    player = new Player(100, 272, 56, 56);
    player->loadAnimation(std::string("PLAYER_ATTACK"));
    player->vx = 1;
    // shop
    temp = new GameEntity(200, 200, 118, 128);
    temp->loadAnimation(std::string("SHOPA"));
    entities.push_back(temp);
    // <ENDTEMP>

    Game::state = RUN;
    return 0;
}

int Game::run() {
    uint64_t current_time = SDL_GetTicks64(), past_time, elapsed_time = 0;
    uint64_t delay;
    while(Game::state != EXIT) {
        switch (Game::state)
        {
        case RUN:
            past_time = current_time;
            Game::HandleInput();
            Game::UpdateEntities(((float)elapsed_time) / 1000.0);
            Game::window.Update();
	        std::cout << ".";
            current_time = SDL_GetTicks64();
            elapsed_time = current_time - past_time;
            delay = (elapsed_time < MS_PER_UPDATE)? MS_PER_UPDATE - elapsed_time : 0;
            SDL_Delay(delay);
            std::cout << "elapsed time: " << elapsed_time << std::endl;
            std::cout << "delaying by: " << delay << std::endl;
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

void Game::UpdateEntities(float dt) {
    	std::list<GameEntity *>::iterator it;
        
        for (it = entities.begin(); it != entities.end(); it++)
        {
            (*it)->update(dt);
            (*it)->draw();
        }
        player->update(dt);
        player->draw();
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