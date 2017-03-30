#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "SDL/include/SDL.h"


#include "SDL_mixer\include\SDL_mixer.h"

#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )


ModuleAudio::ModuleAudio() :Module()
{
	for (int i = 0; i <= MAX_TRACKS; i++)
		musica[i] = nullptr;
}


ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Start()
{
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Load("rtype/intro.ogg");
	Mix_PlayMusic(musica[0], -1);

	return true;
}
bool ModuleAudio::CleanUp()
{
	//Mix_FreeMusic(musica[0]);
	Mix_CloseAudio();
	Mix_Quit();
	return true;
}

Mix_Music* const ModuleAudio::Load(const char* path)
{
	Mix_Music* music = Mix_LoadMUS(path);
	if (music == nullptr)
	{
		LOG("Error with the music %s", path);
	}
	else {
		musica[0] = music;
	}
	return music;
}
