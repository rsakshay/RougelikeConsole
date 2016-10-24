#pragma once
#include "Actor.h"
#include "Map.h"
#include "MyList.h"
#include "Gui.h"

//This is a child class of Actor, for enemies
class Enemy :
	public Actor
{
public:
	//Constructors
	Enemy();
	Enemy(char nameID);
	Enemy(int x, int y, int ch, const TCODColor& col, char nameID);

	//Operator overloads
	bool friend operator==(const Enemy& lhs, const Enemy& rhs);
	Enemy& operator=(const Enemy& other);

	//Destructors
	~Enemy();

	//Member Functions
	void damage(int& x) override;																//Override Actor::damage(int& x)
	void damage(Actor& actor) override;															//Override Actor::damage(Actor& actor) which is also an overload to previous method

	void tryMove(const std::pair<int, int>& playerPos, Map* map);								//Try Moving enemy object in the direction of player if there are no obstacles
	static void update(MyList<Enemy>& myList, const std::pair<int, int>& playerPos, Map* map);	//A static function that updates all the Enemy objects

	friend void Gui::displayEnemyHP(Enemy& enemy);												//A friend function from Gui class that displays the enemy HP on screen
};

