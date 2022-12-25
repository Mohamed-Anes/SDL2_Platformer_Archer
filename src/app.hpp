#ifndef __APP_HPP__
#define __APP_HPP__

#include <list>

#include "module.hpp"

class Window;

class App
{
public:
	// Constructor
	App(int argc, char *args[]);

	// Destructor
	virtual ~App();

	void AddModule(Module* module);

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update();

	// Called before quitting
	bool CleanUp();

private:
	int argc;
	char **args;
	// list of modules
	std::list<Module *> modules;

public:
	// modules
	Window *win;


};




#endif	//__APP_HPP__