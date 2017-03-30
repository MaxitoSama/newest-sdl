#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleNew.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleNew::ModuleNew()
{}

ModuleNew::~ModuleNew()
{}

// Load assets
bool ModuleNew::Start()
{
	LOG("Loading space scene");
	background = App->textures->Load("rtype/intro.png");

	return true;
}

// UnLoad assets
bool ModuleNew::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleNew::Update()
{
	// Move camera forward -----------------------------


	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 && fading==false)
	{
		App->fade->FadeToBlack(this, App->scene_space, 2.0f);
		fading = true;
	}

	return UPDATE_CONTINUE;
}