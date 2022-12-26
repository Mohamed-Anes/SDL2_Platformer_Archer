#include "window.hpp"

#include <SDL2/SDL.h>
#include <iostream>

Window::Window(){
	width = 640;
	height = 480;
	window = nullptr;
	renderer = nullptr;
}

Window::~Window()
{
	std::cout << "--Destroying SDL window and renderer" << std::endl;
	// Destroy window
	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);
	}
	// Destroy window
	if (window != NULL) {
		SDL_DestroyWindow(window);
	}
}

int Window::Init() {
	// Initializing SDL_Window
	std::cout << "--Initializing SDL_Window" << std::endl;
	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE /* | SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_FULLSCREEN_DESKTOP*/;

	SDL_CreateWindowAndRenderer(width, height, flags, &window, &renderer);

	if(window == nullptr || renderer == nullptr){
		std::cout << "SDL_Window and SDL_Renderer could not be created\nSDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}
	return 0;
}

void Window::SetTitle(const char* title) {
	this->title = title;
	SDL_SetWindowTitle(window, title);
}

void Window::SetFullscreen(bool fullscreen) {
	if (fullscreen) {
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	} else {
		SDL_SetWindowFullscreen(window, 0);
	}
}

void Window::GetWindowSize(uint& width, uint& height) const
{
	width = this->width;
	height = this->height;
}

void Window::Update() {
	SDL_RenderPresent(renderer);
}
