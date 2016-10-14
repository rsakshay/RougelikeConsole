#include "Enemy.h"
#include "Engine.h"
#include "Gui.h"
#include <cmath>

extern TCODList<Enemy* > myList;
Enemy::Enemy()
{
	this->nameID = '@';
	this->hp = 1;
	this->actorDamage = 1;
}

Enemy::Enemy(char nameID) : Actor()
{
	this->nameID = nameID;
	this->hp = 1;
	this->actorDamage = 1;
}

Enemy::Enemy(int x, int y, int ch, const TCODColor & col, char nameID) : Actor(x, y, ch, col)
{
	this->nameID = nameID;
	this->hp = 1;
	this->actorDamage = 1;
}



Enemy & Enemy::operator=(const Enemy & other)
{
	if (this != &other)
	{
		this->nameID = other.nameID;
		this->hp = other.hp;
		this->actorDamage = other.actorDamage;
		this->abscissa = other.abscissa;
		this->ordinate = other.ordinate;
		this->asciiCh = other.asciiCh;
		this->color = other.color;
	}
	// TODO: insert return statement here
	return *this;
}

Enemy::~Enemy()
{
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

void Enemy::update(MyList<Enemy>& myList, const std::pair<int, int>& playerPos, Map* map)
{
	//for (Enemy *iterator = &(myList.begin());
	//	iterator != &(myList.end()); iterator++) {
	//	/*if ((*iterator)->hp <= 0)
	//		myList.remove(iterator);*/
	//	iterator->tryMove(playerPos, map);
	//}
	for (int i = 0; i <= myList.top; i++)
	{
		if (myList.objects[i].hp <= 0)
		{
			myList.remove(myList.objects[i--]);
		}
		myList.objects[i].tryMove(playerPos, map);
		int eX = myList.objects[i].getPos().first;
		int eY = myList.objects[i].getPos().second;
		if (eX <= playerPos.first + 1 && eX >= playerPos.first - 1 && eY <= playerPos.second + 1 && eY >= playerPos.second - 1) {
			engine.player->damage(myList.objects[i].actorDamage);
			engine.hud->displayEnemyHP(myList.objects[i]);
		}
	}
}

bool operator==(const Enemy & lhs, const Enemy & rhs)
{
	if (&lhs == &rhs)
		return true;
	return false;
}
