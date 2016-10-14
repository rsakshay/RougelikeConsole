#pragma once
#include "Actor.h"
#include "Map.h"
#include "MyList.h"
#include "Gui.h"

class Enemy :
	public Actor
{
public:
	Enemy();
	Enemy(char nameID);
	Enemy(int x, int y, int ch, const TCODColor& col, char nameID);
	bool friend operator==(const Enemy& lhs, const Enemy& rhs);
	Enemy& operator=(const Enemy& other);
	~Enemy();



	void tryMove(const std::pair<int, int>& playerPos, Map* map);
	static void update(MyList<Enemy>& myList, const std::pair<int, int>& playerPos, Map* map);

	friend void Gui::displayEnemyHP(Enemy& enemy);
};

