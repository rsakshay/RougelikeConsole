#pragma once
#include <utility>
#include "libtcod.hpp"

class Actor
{
protected:
	int abscissa;									// Actor's X position
	int ordinate;									// Actor's Y position
	int asciiCh;									// ASCII character for actor
	TCODColor color;								// Color on tcod console
	char nameID;									// Actor name ID
	int hp;											//Actor's HP

public:
	int actorDamage;							//Actor's damage

	//Constructors
	Actor();
	Actor(int x, int y, int ch, const TCODColor& col);

	//Destructors
	~Actor();

	void moveUP();								// Move actor up
	void moveDOWN();							// Move actor down
	void moveLEFT();							// Move actor left
	void moveRIGHT();							// Move actor right
	std::pair<int, int> getPos() const;			// Return actor postion
	void setActorPos(int x, int y);				// Set Actor position
	int getAsciiCh() const;						// Get Actor ascii value
	TCODColor getColor() const;					// Get Actor color
	void render() const;						// Set Actor display on TCODConsole
	int getHP() const;							// Get Actor HP
	virtual void damage(int& x);				// Function that shows the effect of int& x damage on the player
	virtual void damage(Actor& actor);			// Function that shows the effect of another actor's damage on the player

	//Operator Overloads
	Actor& operator=(const Actor& other);
	friend bool operator==(const Actor& lhs, const Actor& rhs);
};

