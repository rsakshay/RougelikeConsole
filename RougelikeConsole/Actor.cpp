#include "Actor.h"

Actor::Actor() : Actor::Actor(40, 25, '@', TCODColor::white)
{
}

Actor::Actor(int x, int y, int ch, const TCODColor& col) :
	abscissa(x), ordinate(y), asciiCh(ch), color(col)
{
	/*abscissa = x;
	ordinate = y;
	asciiCh = ch;
	color = col;*/
}


Actor::~Actor()
{
}

void Actor::moveUP()
{
	ordinate--;
}

void Actor::moveDOWN()
{
	ordinate++;
}

void Actor::moveLEFT()
{
	abscissa--;
}

void Actor::moveRIGHT()
{
	abscissa++;
}

std::pair<int, int> Actor::getPos() const
{
	return std::pair<int, int>(abscissa, ordinate);
}

void Actor::setActorPos(int x, int y)
{
	abscissa = x;
	ordinate = y;
}

int Actor::getAsciiCh() const
{
	return asciiCh;
}

TCODColor Actor::getColor() const
{
	return color;
}


void Actor::render() const
{
	TCODConsole::root->setChar(abscissa, ordinate, asciiCh);
	TCODConsole::root->setCharForeground(abscissa, ordinate, color);
}
