#ifndef __MODULENEW_H__
#define __MODULENEW_H__

#include "Module.h"

struct SDL_Texture;

class ModuleNew : public Module
{
public:
	ModuleNew();
	~ModuleNew();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	bool fading = false;
};

#endif // __MODULESCENESPACE_H__