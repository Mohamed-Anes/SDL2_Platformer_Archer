#include "window.hpp"

#include <SDL2/SDL.h>
#include <iostream>

Window::Window() : Module()
{
	window = nullptr;
	screenSurface = nullptr;
	name.assign("window");
}

bool Window::Awake() {
	// Initializing SDL_Window and SDL_Surface
	std::cout << "Initializing SDL_Window and SDL_Surface";
	bool ret = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL_VIDEO could not be initialized\nSDL_Error: " << SDL_GetError() << std::endl;
		ret = false;
	} else {
		// Create a window
		// can load configs from a file
		Uint32 flags = SDL_WINDOW_SHOWN| SDL_WINDOW_RESIZABLE /* | SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_FULLSCREEN_DESKTOP*/;

		width = 640;
		height = 480;
		scale = 1;

		window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
		if(window == nullptr) {
			std::cout << "Window could not be created\nSDL_Error: " << SDL_GetError() << std::endl;
			ret = false;
		} else {
			// get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	return ret;
}

void Window::ChangeFullscreen(bool fullscreen) {
	if (fullscreen) {
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	} else {
		SDL_SetWindowFullscreen(window, 0);
	}
}

// Called before quitting
bool Window::CleanUp()
{
	std::cout << "Destroying SDL window and quitting all SDL systems" << std::endl;
	// Destroy window
	if (window != NULL) {
		SDL_DestroyWindow(window);
	}
	// Quit SDL subsystems
	SDL_Quit();
	return true;
}

void Window::GetWindowSize(uint& width, uint& height) const
{
	width = this->width;
	height = this->height;
}

uint Window::GetScale() const
{
	return scale;
}

