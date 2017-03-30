#pragma once
#ifndef _ModuleAudio_H_
#define _ModuleAudio_H_

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

#define MAX_TRACKS 50

class ModuleAudio : public Module
{
public:
	ModuleAudio();
	virtual~ModuleAudio();

	bool Start();
	bool CleanUp();
	Mix_Music* const Load(const char* path);


public:
	Mix_Music* musica[MAX_TRACKS];
	int last_track = 0;
};
#endif

