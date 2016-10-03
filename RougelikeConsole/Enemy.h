#pragma once
#include "Actor.h"
#include "Map.h"

class Enemy :
	public Actor
{
public:
	Enemy();
	Enemy(char nameID);
	Enemy(int x, int y, int ch, const TCODColor& col, char nameID);
	~Enemy();

	void tryMove(const std::pair<int, int>& playerPos, Map* map);
	static void update(const TCODList<Enemy* >& enemies, const std::pair<int, int>& playerPos, Map* map);
};

