#ifndef __MODULE_HPP__
#define __MODULE_HPP__

#include <string>
#include "Defs.hpp"

class Module
{
public:
    Module() : active(false) {};
    void Init() {
        active = true;
    }
	// Called before render is available
    // sending config file to all modules, have to add it as argument
    virtual bool Awake() {
        return true;
    }

    // Called before the first frame
	virtual bool Start()
	{
		return true;
	}

	// Called each loop iteration
	virtual bool PreUpdate()
	{
		return true;
	}

	// Called each loop iteration
	virtual bool Update(float dt)
	{
		return true;
	}

	// Called each loop iteration
	virtual bool PostUpdate()
	{
		return true;
	}

	// Called before quitting
	virtual bool CleanUp()
	{
		return true;
	}

    virtual void OnCollision(/*Collider* c1, Collider* c2*/)
	{

	}

    // missing virtual methods to Load / Save state

public:
    std::string name;
    bool active;
};





#endif //__MODULE_HPP__