#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "module.hpp"

struct SDL_Window;
struct SDL_Surface;

class Window : public Module
{
public:
	Window();

	// Called before render is available
	bool Awake(/*pugi::xml_node&*/);

	// Called before quitting
	bool CleanUp();

	// Changae title
	void SetTitle(const char *title);

	// Retrive window size
	void GetWindowSize(uint &width, uint &height) const;

	void ChangeFullscreen(bool fullscreen);

	// Retrieve window scale
	unsigned int GetScale() const;

public:
	// The window we'll be renderinng to
	SDL_Window *window;
	// The surface contained by the window
	SDL_Surface *screenSurface;

private:
	std::string title;
	uint width;
	uint height;
	uint scale;
};

#endif //__WINDOW_HPP__