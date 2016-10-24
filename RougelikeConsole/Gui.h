#pragma once
//Reference for FILE I/O : http://www.cplusplus.com/forum/general/58945/#msg318044
#include <fstream>
#include <string>

class Enemy;

//This class handles the GUI of the game and is also responsible for updating and refreshing
class Gui
{
	//variables
	char* playerHPString;			//String for player hp
	char* enemyHPString;			//String for Enemy HP
	char* titleText;				//String for Title Screen
public:

	//Constructors
	Gui();

	//Destructors
	~Gui();

	//Member functions
	void update(int playerHP) const;					//Updates the GUI for each frame
	void render();										//Sets the chars for GUI for each frame

	void gameOver();									//Prints Game over message whe player dies
	void gameWon();										//Prints Game Won string when player wins the game
	void displayEnemyHP(Enemy& enemy);					//Display the enemy HP
	void displayTitleScreen();							//Paints the title screen
	void displayGameOverScreen();						//Paints the Game Over screen
	std::string getFileContents(std::ifstream&);		//Method used to read all file contents into a string
};
