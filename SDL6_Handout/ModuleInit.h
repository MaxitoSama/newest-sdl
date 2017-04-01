#ifndef __MODULEINIT_H__
#define __MODULEINIT_H__

#include "Module.h"

struct SDL_Texture;

class ModuleInit : public Module
{
public:
	ModuleInit();
	~ModuleInit();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	bool fading = false;
};

#endif // __MODULESCENESPACE_H__