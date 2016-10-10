#include "Player.h"



Player::Player() : Actor()
{
	this->nameID = 'p';
	this->hp = 5;
	this->playerDamage = 1;
}

Player::Player(int x, int y, int ch, const TCODColor & col) : Actor(x, y, ch, col)
{
	this->nameID = 'p';
	this->hp = 5;
	this->playerDamage = 1;
}


Player::~Player()
{
}

void Player::damage(int & x)
{
	hp -= x;
}

int Player::getHP() const
{
	return hp;
}
