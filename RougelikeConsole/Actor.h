#pragma once
#include <utility>
#include "libtcod.hpp"

class Actor
{
	int actorX;									// Actor's X position
	int actorY;									// Actor's Y position
	int asciiCh;									// ASCII character for player
	TCODColor color;								// Color on tcod console

public:
	Actor();
	Actor(int x, int y, int ch, const TCODColor& col);
	~Actor();

	void moveActorUP();							// Move player up
	void moveActorDOWN();							// Move player down
	void moveActorLEFT();							// Move player left
	void moveActorRIGHT();							// Move player right
	std::pair<int, int> getActorPos() const;		// Return player postion
	void setActorPos(int x, int y);

	void render() const;

};

