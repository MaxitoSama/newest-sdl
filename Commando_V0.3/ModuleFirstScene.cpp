#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFirstScene.h"
#include "ModuleAudio.h"
#include "ModuleSecondScene.h"


ModuleFirstScene::ModuleFirstScene()
{}

ModuleFirstScene::~ModuleFirstScene()
{}

// Load assets
bool ModuleFirstScene::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/Area1.png");
	music = App->music->Load("rtype/Commando_02_Start_Demo.ogg");
	Mix_PlayMusic(music, -1);

	App->player->Enable();
	
	return true;
}

// UnLoad assets
bool ModuleFirstScene::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleFirstScene::Update()
{
	// Move camera forward -----------------------------

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -1864+SCREEN_HEIGHT, NULL);

	if (App->input->keyboard[SDL_SCANCODE_C] == 1 && fading == false)
	{
		App->fade->FadeToBlack(this, App->scene_map2, 2.0f);
		fading = true;
	}
	
	return UPDATE_CONTINUE;
}