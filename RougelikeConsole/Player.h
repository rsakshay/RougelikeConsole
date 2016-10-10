#pragma once
#include "Actor.h"
class Player :
	public Actor
{
	int hp;
	
public:
	int playerDamage;

	Player();
	Player(int x, int y, int ch, const TCODColor& col);
	~Player();

	void damage(int& x);
	int getHP() const;
};

