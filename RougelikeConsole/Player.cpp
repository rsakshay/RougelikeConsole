#include "Player.h"
#include "Enemy.h"

Player::Player() : Actor()
{
	this->nameID = 'p';
	this->hp = 5;
	this->actorDamage = 1;
}

Player::Player(int x, int y, int ch, const TCODColor & col) : Actor(x, y, ch, col)
{
	this->nameID = 'p';
	this->hp = 5;
	this->actorDamage = 1;
}


Player::~Player()
{
}

void Player::damage(int & x)
{
	this->hp -= x;
}

void Player::damage(Actor & actor)
{
	this->hp -= actor.actorDamage;
}



