#include <SDL2/SDL.h>
#include "Game.hpp"


int main(int argc, char *argv[])
{
	Game Archer = Game();

	int result = Archer.run();
	
	return result;
}
