#pragma once
#include "Actor.h"
class Enemy;

//This class is a child of Actor, for player
class Player :
	public Actor
{
public:
	//Constructors
	Player();
	Player(int x, int y, int ch, const TCODColor& col);

	//Destructors
	~Player();

	//Member Functions
	void damage(int& x) override;					//Override Actor::damage(int& x)
	void damage(Actor& actor) override;				//Override Actor::damage(Actor& actor) which is also an overload to previous method
	
};

