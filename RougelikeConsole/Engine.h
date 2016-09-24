#pragma once
class Engine {

	TCODList<Actor* > actors;
	Actor *player;
	Map *map;

public:
	Engine();
	~Engine();
	void update();
	void render();
};

extern Engine engine;
