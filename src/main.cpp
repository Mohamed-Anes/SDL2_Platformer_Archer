#include "app.hpp"
#include <iostream>

enum MainState
{
	CREATE = 1,
	AWAKE,
	START,
	LOOP,
	CLEAN,
	FAIL,
	EXIT
};

int main(int argc, char **args)
{
	App *app = nullptr;
	std::cout << "Engine starting ...\n";
	
	MainState state = CREATE;
	int result = EXIT_FAILURE;

	// game loop
	while (state != EXIT)
	{
		switch (state)
		{
		// Allocate the engine
		case CREATE:
			std::cout << "CREATION PHASE ===============================\n";
			if((app = new App(argc, args)) == nullptr)
				state = FAIL;
			else
				state = AWAKE;
			break;
		
		case AWAKE:
			std::cout << "AWAKENING PHASE ===============================\n";
			if(app->Awake() == true)
			{
				state = START;
			} else {
				std::cout << "ERROR: Awakening failed\n";
				state = FAIL;
			}
			break;

		case START:
			std::cout << "STARTING PHASE ===============================\n";
			if (app->Start() == true) {
				state = LOOP;
			} else {
				state = FAIL;
				std::cout << "ERROR: Starting failed\n";
			}
			break;
		
		case LOOP:
			if (app->Update() == false) {
				state = CLEAN;
			}
			break;
		
		case CLEAN:
			std::cout << "CLEANUP PHASE ===============================\n";
			if (app->CleanUp() == true) {
				if(app) {delete app; app = nullptr;} // to be made into a Macro
				result = EXIT_SUCCESS;
				state = EXIT;
			} else {
				state = FAIL;
			}
			break;
			

		case FAIL:
			std::cout << "Exiting with errors :\n";
			result = EXIT_FAILURE;
			state = EXIT;
			break;
		}
	}
	
	return result;
}
