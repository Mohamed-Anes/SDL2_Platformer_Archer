#include <SDL2/SDL.h>

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <SDL2/SDL_log.h>


#include "Game.hpp"


int main(int argc, char *argv[])
{
	std::ofstream out("log.txt");
	std::cout.rdbuf(out.rdbuf());

	
	SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Hello SDL\n");

	std::cout << "Starting the game" << std::endl;
	Game Archer;
	std::cout << "Initiating the game" << std::endl;
	Archer.Init();
	SDL_Log("Hello SDL Game");
	std::cout << "Running the game" << std::endl;
	int result = Archer.run();
	std::cout << "Finished running the game" << std::endl;

	out.close();
	return result;
}
