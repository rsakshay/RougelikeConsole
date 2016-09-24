#include "libtcod.hpp"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"

Engine engine;

int main() {
	while (!TCODConsole::isWindowClosed()) {
		engine.update();
		engine.render();
		TCODConsole::flush();
	}
	return 0;
}


//int main() {
//	Actor player;
//	TCODConsole::initRoot(80, 50, "libtcod C++ tutorial", false);
//
//	while (!TCODConsole::isWindowClosed()) {
//		TCOD_key_t key;
//		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
//
//		switch (key.vk) {
//
//		case TCODK_UP: 
//			player.moveActorUP();
//			break;
//
//		case TCODK_DOWN: 
//			player.moveActorDOWN();
//			break;
//
//		case TCODK_LEFT: 
//			player.moveActorLEFT();
//			break;
//
//		case TCODK_RIGHT:
//			player.moveActorRIGHT();
//			break;
//
//		default:
//			break;
//		}
//
//		TCODConsole::root->clear();
//		std::pair<int, int> playerPos = player.getActorPos();
//		TCODConsole::root->putChar(playerPos.first, playerPos.second, '@');
//		TCODConsole::flush();
//	}
//	return 0;
//}