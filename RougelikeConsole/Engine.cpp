#include "libtcod.hpp"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"
//#include "ComponentList.h"



Engine::Engine()
{
	//actorList = ComponentList<Actor>();
	TCODConsole::initRoot(80, 50, "RougelikeConsole", false);
	player = new Player(40, 25, '@', TCODColor::white);
	//actorList.push(*player);
	map = new Map(80, 45);
}


Engine::~Engine()
{
	delete player;
	enemies.clearAndDelete();
	//actorList.deleteList();
	delete map;
}

void Engine::update() {
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);

	std::pair<int, int> actorPos = player->getPos();

	switch (key.vk) {
	case TCODK_UP:
		if (!map->isWall(actorPos.first, actorPos.second - 1)) {
			player->moveUP();
			Enemy::update(enemies, player->getPos(), map);
		}
		break;
	case TCODK_DOWN:
		if (!map->isWall(actorPos.first, actorPos.second + 1)) {
			player->moveDOWN();
			Enemy::update(enemies, player->getPos(), map);
		}
		break;
	case TCODK_LEFT:
		if (!map->isWall(actorPos.first - 1, actorPos.second)) {
			player->moveLEFT();
			Enemy::update(enemies, player->getPos(), map);
		}
		break;
	case TCODK_RIGHT:
		if (!map->isWall(actorPos.first + 1, actorPos.second)) {
			player->moveRIGHT();
			Enemy::update(enemies, player->getPos(), map);
		}
		break;
	default:break;
	}
	
}

void Engine::render() {
	TCODConsole::root->clear();
	// draw the map
	map->render();
	player->render();
	// draw the enemies
	for (Enemy **iterator = enemies.begin();
		iterator != enemies.end(); iterator++) {
		(*iterator)->render();
	}
	/*for (Actor *iterator = &actorList.begin();
		iterator != &actorList.end(); iterator++) {
		iterator->render();
	}*/
}

