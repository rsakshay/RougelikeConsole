#include "libtcod.hpp"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"
//#include "ComponentList.h"

bool Engine::renderGameOver;

Engine::Engine() : fovRadius(4), computeFov(true)
{
	hud = new Gui();
	Engine::renderGameOver = false;
	TCODConsole::initRoot(80, 50, "RougelLove Console", true);
	player = new Player(40, 25, 234, TCODColor::purple);
	//myList.push(*player);
	//actorList.push(*player);
	map = new Map(80, 45);
	myList.push(*(new Enemy(60, 20, 140,
		TCODColor::yellow, 'o')));
}


Engine::~Engine()
{
	delete player;
	delete map;
	delete hud;
}

void Engine::update() {
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);

	std::pair<int, int> actorPos = player->getPos();
	if (actorPos == std::pair<int, int>(7, 36) || player->getHP() <= 0)
	{
		Engine::renderGameOver = true;
		return;
	}

	switch (key.vk) {
	case TCODK_UP:
		if (map->canWalk(actorPos.first, actorPos.second - 1)) {
			player->moveUP();
			computeFov = true;
			Enemy::update(myList, player->getPos(), map);
		}
		break;
	case TCODK_DOWN:
		if (map->canWalk(actorPos.first, actorPos.second + 1)) {
			player->moveDOWN();
			computeFov = true;
			Enemy::update(myList, player->getPos(), map);
		}
		break;
	case TCODK_LEFT:
		if (map->canWalk(actorPos.first - 1, actorPos.second)) {
			player->moveLEFT();
			computeFov = true;
			Enemy::update(myList, player->getPos(), map);
		}
		break;
	case TCODK_RIGHT:
		if (map->canWalk(actorPos.first + 1, actorPos.second)) {
			player->moveRIGHT();
			computeFov = true;
			Enemy::update(myList, player->getPos(), map);
		}
		break;
	case TCODK_SPACE:
		//for (Enemy *iterator = &(myList.begin());
		//	iterator != &(myList.end()); iterator++) {
		//	int eX = iterator->getPos().first;
		//	int eY = iterator->getPos().second;
		//	if (eX <= actorPos.first + 1 && eX >= actorPos.first - 1 && eY <= actorPos.second + 1 && eY >= actorPos.second - 1) {
		//		iterator->damage(player->actorDamage);
		//	}
		//}
		Beep(750, 300);
		for (int i = 0; i <= myList.top; i++)
		{
			int eX = myList.objects[i].getPos().first;
			int eY = myList.objects[i].getPos().second;
			if (eX <= actorPos.first + 1 && eX >= actorPos.first - 1 && eY <= actorPos.second + 1 && eY >= actorPos.second - 1) {
				myList.objects[i].damage(*player);
				Beep(900, 500);
				break;
			}
		}
		Enemy::update(myList, player->getPos(), map);
		break;
	case TCODK_ESCAPE:
		Globals::gameIsOver = true;
		break;
	default:break;
	}
	if (computeFov) {
		map->computeFov();
		computeFov = false;
	}
	hud->update(player->getHP());
}

void Engine::render() {
	TCODConsole::root->clear();
	// draw the map
	map->render();
	if (map->isInFov(player->getPos().first, player->getPos().second)) {
		player->render();
	}
	// draw the myList
	//int x = int(&(myList.begin()));
	//int y = int(&(myList.end()));
	//for (Enemy *iterator = &(myList.begin());
	//	iterator != &(myList.end()); iterator++) {
	//	if (map->isInFov(iterator->getPos().first, iterator->getPos().second)) {
	//		iterator->render();
	//	}
	//}
	for (int i = 0; i <= myList.top; i++)
	{
		if (map->isInFov(myList.objects[i].getPos().first, myList.objects[i].getPos().second)) {
			myList.objects[i].render();
			hud->displayEnemyHP(myList.objects[i]);
		}
	}
	/*for (Actor *iterator = &actorList.begin();
		iterator != &actorList.end(); iterator++) {
		iterator->render();
	}*/
	hud->render();
	if (Engine::renderGameOver)
	{
		hud->gameOver();
	}
}

