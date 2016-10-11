#pragma once
#include "Actor.h"
#include "Map.h"
#include "MyList.h"

class Enemy :
	public Actor
{
	int hp;
public:
	Enemy();
	Enemy(char nameID);
	Enemy(int x, int y, int ch, const TCODColor& col, char nameID);
	~Enemy();

	void damage(int& x);
	void tryMove(const std::pair<int, int>& playerPos, Map* map);
	static void update(MyList<Enemy>& myList, const std::pair<int, int>& playerPos, Map* map);
};

