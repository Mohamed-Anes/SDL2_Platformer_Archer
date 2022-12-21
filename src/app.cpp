#include "app.hpp"

#include <iostream>
#include <sstream>


App::App(int argc, char **args) : argc(argc), args(args)
{
	// initialize and add modules
}

App::~App()
{
	// release modules
}

bool App::Awake() {
	// load configuration files, get app title, organisation, framerate cap
	// if config file loaded loop modules and apply Awake() method
	return true;
}

bool App::Start() {
	// load save file
	// loop modules and apply Start() method
	return true;
}

// called each loop iteration
bool App::Update() {
	// apply update methods, and check for QUIT window event
	return true;
}

bool App::CleanUp() {
	// loop modules and apply CleanUp() method
	return true;
}


