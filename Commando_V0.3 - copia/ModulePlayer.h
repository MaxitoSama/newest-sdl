#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation up;
	Animation down;
	Animation left;
	Animation right;
	Animation rightUP;
	Animation leftUP;
	Animation rightDOWN;
	Animation leftDOWN;
	enum Direction{ UP, DOWN, LEFT, RIGHT };
	Direction playerDirection;
	iPoint position;
};

#endif