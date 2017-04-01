#ifndef __MODULEENDSCENE_H__
#define __MODULEENDSCENE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleEndScene : public Module
{
public:
	ModuleEndScene();
	~ModuleEndScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	bool fading = false;
};

#endif // __MODULEENDSCENE_H__

