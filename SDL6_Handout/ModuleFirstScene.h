#ifndef __MODULEFIRSTSCENE_H__
#define __MODULEFIRSTSCENE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleFirstScene : public Module
{
public:
	ModuleFirstScene();
	~ModuleFirstScene();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	bool fading = false;
};

#endif // __MODULEFIRSTSCENE_H__