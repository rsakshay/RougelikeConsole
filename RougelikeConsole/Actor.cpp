#include "Actor.h"

Actor::Actor() : Actor::Actor(40, 25, '@', TCODColor::white)
{
}

Actor::Actor(int x, int y, int ch, const TCODColor& col) :
	actorX(x), actorY(y), asciiCh(ch), color(col)
{
	/*actorX = x;
	actorY = y;
	asciiCh = ch;
	color = col;*/
}


Actor::~Actor()
{
}

void Actor::moveActorUP()
{
	actorY--;
}

void Actor::moveActorDOWN()
{
	actorY++;
}

void Actor::moveActorLEFT()
{
	actorX--;
}

void Actor::moveActorRIGHT()
{
	actorX++;
}

std::pair<int, int> Actor::getActorPos() const
{
	return std::pair<int, int>(actorX, actorY);
}

void Actor::setActorPos(std::pair<int, int>& actorPos)
{
	actorX = actorPos.first;
	actorY = actorPos.second;
}

void Actor::render() const
{
	TCODConsole::root->setChar(actorX, actorY, asciiCh);
	TCODConsole::root->setCharForeground(actorX, actorY, color);
}
