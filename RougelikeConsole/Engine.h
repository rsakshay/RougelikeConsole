#pragma once
#include "Gui.h"
#include "Player.h"
#include "Enemy.h"
#include "MyList.h"
#include "globals.h"

//Includes for Beep function
#include <Windows.h>
#include <WinBase.h>

//This class handles all the game object interaction
class Engine {
	bool computeFov;
	static bool renderGameOver;

public:
	//TCODList<Enemy* > myList;
	//Gui* hud;
	MyList<Enemy> myList;			//List of enemies
	Player *player;					//Player object pointer
	Map *map;						//Map object pointer
	Gui* hud;						//Gui object pointer
	int fovRadius;					//Field of View Radius

	//Constructors
	Engine();

	//Destructors
	~Engine();

	//Member Functions
	void update();					//Updates game object variables and is called for each frame
	void render();					//Sets all the game object display variables on TCODConsole
};

//Forward declare an engine variable for all classes that use Engine.h
extern Engine engine;
