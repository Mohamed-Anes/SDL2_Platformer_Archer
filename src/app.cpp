#include "app.hpp"

#include <iostream>
#include <sstream>

#include "window.hpp"

App::App(int argc, char **args) : argc(argc), args(args)
{
	// initialize and add modules
	win = new Window();

	// add modules to list
	modules.push_back(win);
}

App::~App()
{
	// release modules
}

void App::AddModule(Module* module)
{
	module->Init();
	modules.push_back(module);
}

bool App::Awake() {
	// load configuration files, get app title, organisation, framerate cap
	// if config file loaded loop modules and apply Awake() method
	std::list<Module *>::iterator it;
	for (it = modules.begin(); it != modules.end(); it++)
	{
		(*it)->Awake();
	}
	return true;
}

bool App::Start() {
	// load save file
	// loop modules and apply Start() method
	std::list<Module *>::iterator it;
	for (it = modules.begin(); it != modules.end(); it++)
	{
		(*it)->Start();
	}
	return true;
}

// called each loop iteration
bool App::Update() {
	// apply update methods, and check for QUIT window event
	return true;
}

bool App::CleanUp() {
	// loop modules and apply CleanUp() method
	std::list<Module *>::iterator it;
	for (it = modules.end(); it != modules.begin(); it--)
	{
		(*it)->CleanUp();
	}
	return true;
}


