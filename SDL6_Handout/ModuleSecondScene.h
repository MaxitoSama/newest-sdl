#ifndef __MODULESECONDSCENE_H__
#define __MODULESECONDSCENE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSecondScene : public Module
{
public:
	ModuleSecondScene();
	~ModuleSecondScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	bool fading = false;
};

#endif // __MODULESECONDSCENE_H__