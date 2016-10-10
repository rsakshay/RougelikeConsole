#include "Enemy.h"
#include <cmath>

extern TCODList<Enemy* > enemies;
Enemy::Enemy()
{
	this->hp = 1;
}

Enemy::Enemy(char nameID) : Actor()
{
	this->nameID = nameID;
	this->hp = 1;
}

Enemy::Enemy(int x, int y, int ch, const TCODColor & col, char nameID) : Actor(x, y, ch, col)
{
	this->nameID = nameID;
	this->hp = 1;
}


Enemy::~Enemy()
{
}

void Enemy::damage(int & x)
{
	this->hp -= x;
}

void Enemy::tryMove(const std::pair<int, int>& playerPos, Map* map)
{
	int xDist = playerPos.first - this->abscissa;
	int yDist = playerPos.second - this->ordinate;
	float distance = ceil(sqrt(pow(abs(xDist), 2) + pow(abs(yDist), 2)));
	if (distance < 5 && distance > 1)
	{
		if (abs(xDist) > abs(yDist))
		{
			if (xDist > 0) {
				if (map->canWalk(abscissa + 1, ordinate))
				{
					this->moveRIGHT();
				}
			}
			else if (xDist < 0) {
				if (map->canWalk(abscissa - 1, ordinate))
				{
					this->moveLEFT();
				}
			}
		}
		else if (abs(xDist) < abs(yDist))
		{
			if (yDist < 0) {
				if (map->canWalk(abscissa, ordinate - 1))
				{
					this->moveUP();
				}
			}
			else if (yDist > 0) {
				if (map->canWalk(abscissa, ordinate + 1))
				{
					this->moveDOWN();
				}
			}
		}
	}
}

void Enemy::update(const TCODList<Enemy*>& enemies, const std::pair<int, int>& playerPos, Map* map)
{
	for (Enemy **iterator = enemies.begin();
		iterator != enemies.end(); iterator++) {
		/*if ((*iterator)->hp <= 0)
			enemies.remove(iterator);*/
		(*iterator)->tryMove(playerPos, map);
	}
}

