#include "libtcod.hpp"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"
//#include "ComponentList.h"



Engine::Engine() : fovRadius(4), computeFov(true)
{
	TCODConsole::initRoot(80, 50, "RougelikeConsole", false);
	player = new Player(40, 25, '@', TCODColor::purple);
	//myList.push(*player);
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
		if (map->canWalk(actorPos.first, actorPos.second - 1)) {
			player->moveUP();
			computeFov = true;
			Enemy::update(enemies, player->getPos(), map);
		}
		break;
	case TCODK_DOWN:
		if (map->canWalk(actorPos.first, actorPos.second + 1)) {
			player->moveDOWN();
			computeFov = true;
			Enemy::update(enemies, player->getPos(), map);
		}
		break;
	case TCODK_LEFT:
		if (map->canWalk(actorPos.first - 1, actorPos.second)) {
			player->moveLEFT();
			computeFov = true;
			Enemy::update(enemies, player->getPos(), map);
		}
		break;
	case TCODK_RIGHT:
		if (map->canWalk(actorPos.first + 1, actorPos.second)) {
			player->moveRIGHT();
			computeFov = true;
			Enemy::update(enemies, player->getPos(), map);
		}
		break;
	case TCODK_SPACE:
		for (Enemy **iterator = enemies.begin();
			iterator != enemies.end(); iterator++) {
			int eX = (*iterator)->getPos().first;
			int eY = (*iterator)->getPos().second;
			if (eX <= actorPos.first + 1 && eX >= actorPos.first - 1 && eY <= actorPos.second + 1 && eY >= actorPos.second - 1) {
				(*iterator)->damage(player->playerDamage);
			}
		}
		break;
	default:break;
	}
	if (computeFov) {
		map->computeFov();
		computeFov = false;
	}
}

void Engine::render() {
	TCODConsole::root->clear();
	// draw the map
	map->render();
	if (map->isInFov(player->getPos().first, player->getPos().second)) {
		player->render();
	}
	// draw the enemies
	for (Enemy **iterator = enemies.begin();
		iterator != enemies.end(); iterator++) {
		Enemy* enemy = *iterator;
		//if (map->isInFov(enemy->getPos().first, enemy->getPos().second)) {
			enemy->render();
		//}
	}
	/*for (Actor *iterator = &actorList.begin();
		iterator != &actorList.end(); iterator++) {
		iterator->render();
	}*/
}

