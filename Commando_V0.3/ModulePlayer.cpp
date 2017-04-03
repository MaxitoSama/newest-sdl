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

	position.x = 150;
	position.y = 120;

	// idle animation (just the ship)
	idle.PushBack({3, 32, 13, 23});

	// Move upwards
	up.PushBack({30, 32, 13, 23});
	up.PushBack({3, 32, 13, 23});
	up.PushBack({ 56,2,13,23 });
	up.loop = true;
	up.speed = 0.1f;

	// Move down
	down.PushBack({3, 64, 13, 23});
	down.PushBack({ 105, 35, 14, 23 });
	down.PushBack({ 27, 64, 13, 23 });
	down.PushBack({ 105, 35, 14, 23 });
	down.loop = true;
	down.speed = 0.1f;

	// Move Right
	//right.PushBack({})
	//right.PushBack({})
	//right.PushBack({})
	//right.PushBack({})
	right.loop = true;
	right.speed = 0.1f;

	// Move Left
	//left.PushBack({})
	//left.PushBack({})
	//left.PushBack({})
	//left.PushBack({})
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
		if (position.x < SCREEN_WIDTH - 13) {
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
		if (position.y <SCREEN_HEIGHT-14) {
			position.y += speed;
		}
		if(current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}
	//UP
	if(App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > -1864+SCREEN_HEIGHT) {
			position.y -= speed;
		}
		if(current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}
	/*//RIGHT UP
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > -1864 + SCREEN_HEIGHT) {
			position.y -= speed;
		}
		if (current_animation != &rightUP)
		{
			rightUP.Reset();
			current_animation = &rightUP;
		}
	}
	//LEFT UP
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > -1864 + SCREEN_HEIGHT) {
			position.y -= speed;
		}
		if (current_animation != &leftUP)
		{
			leftUP.Reset();
			current_animation = &leftUP;
		}
	}
	//RIGHT DOWN
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > -1864 + SCREEN_HEIGHT) {
			position.y -= speed;
		}
		if (current_animation != &rightDOWN)
		{
			rightDOWN.Reset();
			current_animation = &rightDOWN;
		}
	}
	//LEFT DOWN
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (position.y > -1864 + SCREEN_HEIGHT) {
			position.y -= speed;
		}
		if (current_animation != &leftDOWN)
		{
			leftDOWN.Reset();
			current_animation = &leftDOWN;
		}
	}*/

	// TODO 3: Shoot lasers when the player hits SPACE

	if(App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->explosion, position.x, position.y + 25);
		App->particles->AddParticle(App->particles->explosion, position.x - 25, position.y, 500);
		App->particles->AddParticle(App->particles->explosion, position.x, position.y - 25, 1000);
		App->particles->AddParticle(App->particles->explosion, position.x + 25, position.y, 1500);
	}
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x+32, position.y);
	}

	if(App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_IDLE
	   && App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

	// Draw everything --------------------------------------

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}