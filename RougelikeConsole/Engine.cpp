#include "libtcod.hpp"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"


Engine::Engine()
{
	TCODConsole::initRoot(80, 50, "libtcod C++ tutorial", false);
	player = new Actor(40, 25, '@', TCODColor::white);
	actors.push(player);
	actors.push(new Actor(60, 13, '@', TCODColor::yellow));
	map = new Map(80, 45);
}


Engine::~Engine()
{
	actors.clearAndDelete();
	delete map;
}

void Engine::update() {
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);

	std::pair<int, int> actorPos = player->getActorPos();

	switch (key.vk) {
	case TCODK_UP:
		if (!map->isWall(actorPos.first, actorPos.second - 1)) {
			player->moveActorUP();
		}
		break;
	case TCODK_DOWN:
		if (!map->isWall(actorPos.first, actorPos.second + 1)) {
			player->moveActorDOWN();
		}
		break;
	case TCODK_LEFT:
		if (!map->isWall(actorPos.first - 1, actorPos.second)) {
			player->moveActorLEFT();
		}
		break;
	case TCODK_RIGHT:
		if (!map->isWall(actorPos.first + 1, actorPos.second)) {
			player->moveActorRIGHT();
		}
		break;
	default:break;
	}
}

void Engine::render() {
	TCODConsole::root->clear();
	// draw the map
	map->render();

	// draw the actors
	for (Actor **iterator = actors.begin();
		iterator != actors.end(); iterator++) {
		(*iterator)->render();
	}
}

