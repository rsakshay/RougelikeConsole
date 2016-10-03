#pragma once
#include "ComponentList.h"
#include "Player.h"
#include "Enemy.h"

class Engine {
public:
	TCODList<Enemy* > enemies;
	//ComponentList<Actor> actorList;
	//Actor *player;
	Player *player;
	Map *map;

	Engine();
	~Engine();
	void update();
	void render();
};

extern Engine engine;
