//Basic Rougelike Coding Reference: http://www.roguebasin.com/index.php?title=Complete_roguelike_tutorial_using_C%2B%2B_and_libtcod_-_part_1:_setting_up
//NOTE: Please follow this link to setup the environment for Visual Studio: http://daraprogramming.blogspot.com/2014/08/setting-up-libtcod-151-with-visual.html
#include "libtcod.hpp"
#include "globals.h"
#include "Actor.h"
#include "Map.h"
#include "Engine.h"
#include <fstream>
#include <string>
#define _GAMEOVER
//Declare Engine variable
Engine engine;

int main() {
	//Check for TCODConsole Window to be opn and a global value gameover to not be set
	while (!TCODConsole::isWindowClosed() && !Globals::gameIsOver) {
		//Display title screen
		if (Globals::isTitleScreenActive)
		{
			engine.hud->displayTitleScreen();
		}
		else
		//Run engine
		{
			//call Engine update
			engine.update();
			//call Engine render
			engine.render();
		}
		// Calling flush updates the TCODConsole screen
		TCODConsole::flush();
	}

//Using defines of Existense for GameOver
#ifdef _GAMEOVER
	while (true)
	{
		TCODConsole::root->clear();
		engine.hud->displayGameOverScreen();
		TCODConsole::flush();
		TCOD_key_t key;
		TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
		if (key.vk == TCODK_ENTER)
		{
			break;
		}
	}
#endif // _GAMEOVER

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