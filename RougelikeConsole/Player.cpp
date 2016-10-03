#include "Player.h"



Player::Player() : Actor()
{
	this->nameID = 'p';
}

Player::Player(int x, int y, int ch, const TCODColor & col) : Actor(x, y, ch, col)
{
	this->nameID = 'p';
}


Player::~Player()
{
}
