#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <SDL2/SDL_log.h>


#include "Game.hpp"


int main(int argc, char *argv[])
{

	std::cout << "Starting the game" << std::endl;
	Game Archer;
	std::cout << "Initializing the game" << std::endl;
	Archer.Init();
	std::cout << "Running the game" << std::endl;
	int result = Archer.run();
	std::cout << "Finished running the game" << std::endl;

	return result;
}
