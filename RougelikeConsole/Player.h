#pragma once
#include "Actor.h"
class Player :
	public Actor
{
public:
	Player();
	Player(int x, int y, int ch, const TCODColor& col);
	~Player();
};

