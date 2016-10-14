#pragma once
#include <fstream>
#include <string>

class Enemy;

class Gui
{
	char* playerHPString;
	char* enemyHPString;
	char* titleText;
public:
	Gui();
	~Gui();

	void update(int playerHP) const;
	void render();

	void gameOver();
	void displayEnemyHP(Enemy& enemy);
	void displayTitleScreen();
	std::string getFileContents(std::ifstream&);
};
