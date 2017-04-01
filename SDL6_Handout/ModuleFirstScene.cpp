#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleFirstScene.h"
#include "ModuleSecondScene.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleFirstScene::ModuleFirstScene()
{}

ModuleFirstScene::~ModuleFirstScene()
{}

// Load assets
bool ModuleFirstScene::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/Area1.png");

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
	int scroll_speed = 1;

	App->player->position.y += 1;
	App->render->camera.y -= 3;
	

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_C] == 1 && fading == false)
	{
		App->fade->FadeToBlack(this, App->scene_map2, 2.0f);
		fading = true;
	}
	
	return UPDATE_CONTINUE;
}