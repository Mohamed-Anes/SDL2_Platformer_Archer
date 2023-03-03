#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <SDL2/SDL.h>
#include <string>




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
	void GetWindowSize(int &width, int &height) const;

	// Set or unset full screen
	void SetFullscreen(bool fullscreen);

	// Update
	void Update();

public:
	// The window we'll be rendering to
	static SDL_Window *window;
	// The renderer
	static SDL_Renderer *renderer;

public:
	std::string title;
	int width;
	int height;
};

#endif //__WINDOW_HPP__