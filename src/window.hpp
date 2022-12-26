#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <string>

#include "Defs.hpp"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

class Window
{
public:
	// Construstor
	Window();

	//Destructor
	~Window();

	// Initializer
	int Init();

	// Change title
	void SetTitle(const char *title);

	// Retrive window size
	void GetWindowSize(uint &width, uint &height) const;

	// Set or unset full screen
	void SetFullscreen(bool fullscreen);

	// Update
	void Update();

public:
	// The window we'll be rendering to
	SDL_Window *window;
	// The renderer
	SDL_Renderer *renderer;

private:
	std::string title;
	uint width;
	uint height;
};

#endif //__WINDOW_HPP__