#ifndef __APP_H__
#define __APP_H__


class App
{
public:
	// Constructor
	App(int argc, char *args[]);

	// Destructor
	virtual ~App();

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

};




#endif	//__APP_H__