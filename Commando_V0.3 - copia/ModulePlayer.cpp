#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 100;
	position.y = 120;

	// idle animation (just the ship)
	idle.PushBack({1, 49, 13, 23});

	// Move upwards
	up.PushBack({31, 49, 13, 23});
	up.PushBack({1, 49, 13, 23});
	up.PushBack({ 61,49,13,23 });
	up.loop = true;
	up.speed = 0.1f;

	// Move down
	down.PushBack({61, 73, 14, 23});
	down.PushBack({ 1, 73, 14, 23 });
	down.PushBack({ 31, 73, 14, 23 });
	down.loop = true;
	down.speed = 0.1f;

	// Move Right
	right.PushBack({ 1,1,22,22 });
	right.PushBack({31,1,19,22});
	right.PushBack({61,1,25,22});
	right.loop = true;
	right.speed = 0.1f;

	// Move Left
	left.PushBack({1,25,22,22 });
	left.PushBack({31,25,19,22});
	left.PushBack({61,25,25,22});
	left.loop = true;
	left.speed = 0.1f;

	// Move RightUP;
	//rightUP.PushBack({})
	//rightUP.PushBack({})
	//rightUP.PushBack({})
	//rightUP.PushBack({})
	rightUP.loop = true;
	rightUP.speed = 0.1f;

	// Move LeftUP
	//leftUP.PushBack({})
	//leftUP.PushBack({})
	//leftUP.PushBack({})
	//leftUP.PushBack({})
	leftUP.loop = true;
	leftUP.speed = 0.1f;

	// Move RightDOWN
	//rightDOWN.PushBack({})
	//rightDOWN.PushBack({})
	//rightDOWN.PushBack({})
	//rightDOWN.PushBack({})
	rightDOWN.loop = true;
	rightDOWN.speed = 0.1f;

	// Move LeftDOWN
	//leftDOWN.PushBack({})
	//leftDOWN.PushBack({})
	//leftDOWN.PushBack({})
	//leftDOWN.PushBack({})
	leftDOWN.loop = true;
	leftDOWN.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/Superjoe_Sprites_1.png");


	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 2;
	
	//LEFT
	if( App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x > 0) {
			position.x -= speed;
		}
		if (current_animation != &left)
		{
			left.Reset();
			current_animation = &left;
		}
	}
	//RIGHT
	if(App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.x < SCREEN_WIDTH - 20) {
			position.x += speed;
		}
		if (current_animation != &right)
		{
			right.Reset();
			current_animation = &right;
		}
	}
	//DOWN
	if(App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y <SCREEN_HEIGHT-20) {
			position.y += speed;
		}
		if(current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}
	//UP
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > -1864 + SCREEN_HEIGHT) {
			position.y -= speed;
		}
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}
	// TODO 3: Shoot lasers when the player hits SPACE

	//if(App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	//{
	//	App->particles->AddParticle(App->particles->explosion, position.x, position.y + 25);
	//	App->particles->AddParticle(App->particles->explosion, position.x - 25, position.y, 500);
	//	App->particles->AddParticle(App->particles->explosion, position.x, position.y - 25, 1000);
	//	App->particles->AddParticle(App->particles->explosion, position.x + 25, position.y, 1500);
	//}
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
		{  
			App->particles->AddParticle(App->particles->bulletUP, position.x + 11, position.y + 3);
		}
		else if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			App->particles->AddParticle(App->particles->bulletDOWN, position.x +2, position.y + 9);
		}
		else if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		{
			App->particles->AddParticle(App->particles->bulletRIGHT, position.x + 22, position.y + 7);
		}
		else if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			App->particles->AddParticle(App->particles->bulletLEFT, position.x + 2, position.y + 8);
		}
		else {
			App->particles->AddParticle(App->particles->bulletUP, position.x + 11, position.y + 3);
		}
		
	}

	if(App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE
	   && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE
		 && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

	// Draw everything --------------------------------------

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}