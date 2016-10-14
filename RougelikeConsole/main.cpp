#include "libtcod.hpp"
#include "globals.h"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"
#include <fstream>
#include <string>

Engine engine;

int main() {
	while (!TCODConsole::isWindowClosed() && !Globals::gameIsOver) {
		if (Globals::isTitleScreenActive)
		{
			engine.hud->displayTitleScreen();
		}
		else
		{
			engine.update();
			engine.render();
		}
		
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
//			player.moveUP();
//			break;
//
//		case TCODK_DOWN: 
//			player.moveDOWN();
//			break;
//
//		case TCODK_LEFT: 
//			player.moveLEFT();
//			break;
//
//		case TCODK_RIGHT:
//			player.moveRIGHT();
//			break;
//
//		default:
//			break;
//		}
//
//		TCODConsole::root->clear();
//		std::pair<int, int> playerPos = player.getPos();
//		TCODConsole::root->putChar(playerPos.first, playerPos.second, '@');
//		TCODConsole::flush();
//	}
//	return 0;
//}