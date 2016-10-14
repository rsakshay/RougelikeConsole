#pragma once
#include "Gui.h"
#include "Player.h"
#include "Enemy.h"
#include "MyList.h"
#include "globals.h"

#include <Windows.h>
#include <WinBase.h>

class Engine {
	bool computeFov;
	static bool renderGameOver;

public:
	//TCODList<Enemy* > myList;
	//Gui* hud;
	MyList<Enemy> myList;
	Player *player;
	Map *map;
	Gui* hud;
	int fovRadius;

	Engine();
	~Engine();
	void update();
	void render();
};

extern Engine engine;
