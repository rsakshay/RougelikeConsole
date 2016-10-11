#pragma once
//#include "ComponentList.h"
#include "Player.h"
#include "Enemy.h"
#include "MyList.h"

class Engine {
	bool computeFov;
public:
	//TCODList<Enemy* > myList;
	MyList<Enemy> myList;
	Player *player;
	Map *map;
	int fovRadius;

	Engine();
	~Engine();
	void update();
	void render();
};

extern Engine engine;
