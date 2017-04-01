#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSecondScene.h"
#include "ModuleEndScene.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSecondScene::ModuleSecondScene()
{}

ModuleSecondScene::~ModuleSecondScene()
{}

// Load assets
bool ModuleSecondScene::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("rtype/Area2.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleSecondScene::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleSecondScene::Update()
{
	// Move camera forward -----------------------------


	// Draw everything --------------------------------------
	App->render->Blit(background, 0, -1854+SCREEN_HEIGHT, NULL);

	if (App->input->keyboard[SDL_SCANCODE_C] == 1 && fading == false)
	{
		App->fade->FadeToBlack(this, App->end_scene, 2.0f);
		fading = true;
	}

	return UPDATE_CONTINUE;
}