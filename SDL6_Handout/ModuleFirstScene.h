#ifndef __MODULEFIRSTSCENE_H__
#define __MODULEFIRSTSCENE_H__

#include "Module.h"
#include "SDL_mixer\include\SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

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
	Mix_Music* music = NULL;
	bool fading = false;
};

#endif // __MODULEFIRSTSCENE_H__