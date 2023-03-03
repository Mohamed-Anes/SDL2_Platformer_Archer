#include "window.hpp"

#include <SDL2/SDL.h>
#include <iostream>

#include "Defs.hpp"


// Static definitions
// The window we'll be rendering to
SDL_Window *Window::window = nullptr;
// The renderer
SDL_Renderer *Window::renderer = nullptr;

Window::Window(): width(WINDOW_WIDTH), height(WINDOW_HEIGHT) {

}

Window::~Window()
{
	std::cout << "--Destroying SDL window and renderer" << std::endl;
	// Destroy window
	if (Window::renderer != NULL) {
		SDL_DestroyRenderer(Window::renderer);
	}
	// Destroy window
	if (Window::window != NULL) {
		SDL_DestroyWindow(Window::window);
	}
}

int Window::Init() {
	// Initializing SDL_Window
	std::cout << "--Initializing SDL_Window" << std::endl;
	Uint32 flags = SDL_WINDOW_SHOWN /* | SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_FULLSCREEN_DESKTOP*/;

	SDL_CreateWindowAndRenderer(width, height, flags, &(Window::window), &(Window::renderer));

	if(Window::window == nullptr || Window::renderer == nullptr){
		std::cout << "SDL_Window and SDL_Renderer could not be created\nSDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	return 0;
}

void Window::SetTitle(const char* title) {
	this->title = title;
	SDL_SetWindowTitle(Window::window, title);
}

void Window::SetFullscreen(bool fullscreen) {
	if (fullscreen) {
		SDL_SetWindowFullscreen(Window::window, SDL_WINDOW_FULLSCREEN);
	} else {
		SDL_SetWindowFullscreen(Window::window, 0);
	}
}

void Window::GetWindowSize(int& width, int& height) const
{
	width = this->width;
	height = this->height;
}

void Window::Update() {
	SDL_RenderPresent(Window::renderer);
	SDL_RenderClear(Window::renderer);
}
