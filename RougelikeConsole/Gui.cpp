#include "Gui.h"
#include "Enemy.h"
#include "libtcod.hpp"
#include <stdlib.h>
#include "globals.h"


Gui::Gui()
{
	playerHPString = new char[2];
	enemyHPString = new char[2];
	std::ifstream Reader("title.txt");             //Open file
	std::string Art = getFileContents(Reader);       //Get file
	titleText = new char[Art.size() + 1];
	titleText[Art.size()] = 0;
	memcpy(titleText, Art.c_str(), Art.size());
	Reader.close();                           //Close file
}


Gui::~Gui()
{
	delete playerHPString;
	delete enemyHPString;
}

void Gui::update(int playerHP) const
{
	_itoa_s(playerHP, this->playerHPString, 2, 10);
}

void Gui::render()
{
	TCODConsole::root->print(1, 47, "HP: ");
	TCODConsole::root->print(5, 47, this->playerHPString);
}

void Gui::gameOver()
{
	TCODConsole::root->print(30, 47, Globals::gameOverString);
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
	if (key.vk == TCODK_ENTER)
	{
		Globals::gameIsOver = true;
	}
}

void Gui::displayEnemyHP(Enemy& enemy)
{
	TCODConsole::root->print(65, 47, "Enemy HP: ");
	_itoa_s(enemy.hp, this->enemyHPString, 2, 10);
	TCODConsole::root->print(75, 47, this->enemyHPString);
}

void Gui::displayTitleScreen()
{

	TCODConsole::root->print(10, 10, titleText);
	TCOD_key_t key;
	TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key, NULL);
	if (key.vk == TCODK_ENTER)
	{
		Globals::isTitleScreenActive = false;
	}
	else if (key.vk == TCODK_ESCAPE)
	{
		Globals::gameIsOver = true;
	}
}

std::string Gui::getFileContents(std::ifstream& File)
{
	std::string Lines = "";        //All lines

	if (File)                      //Check if everything is good
	{
		while (File.good())
		{
			std::string TempLine;                  //Temp line
			std::getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}

