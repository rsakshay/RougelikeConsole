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
	int hp;

public:
	int actorDamage;

	Actor();
	Actor(int x, int y, int ch, const TCODColor& col);
	~Actor();

	void moveUP();							// Move actor up
	void moveDOWN();							// Move actor down
	void moveLEFT();							// Move actor left
	void moveRIGHT();							// Move actor right
	std::pair<int, int> getPos() const;		// Return actor postion
	void setActorPos(int x, int y);
	int getAsciiCh() const;
	TCODColor getColor() const;
	void render() const;
	int getHP() const;
	void damage(int& x);
	void damage(Actor& actor);
};

