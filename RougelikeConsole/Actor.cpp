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

int Actor::getHP() const
{
	return hp;
}

void Actor::damage(int & x)
{
	//this->hp -= x;
}

void Actor::damage(Actor & actor)
{
	//this->hp -= actor.actorDamage;
}

Actor & Actor::operator=(const Actor & other)
{
	if (this != &other)
	{
		this->nameID = other.nameID;
		this->hp = other.hp;
		this->actorDamage = other.actorDamage;
		this->abscissa = other.abscissa;
		this->ordinate = other.ordinate;
		this->asciiCh = other.asciiCh;
		this->color = other.color;
	}
	// TODO: insert return statement here
	return *this;
}

bool operator==(const Actor & lhs, const Actor & rhs)
{
	if (&lhs == &rhs)
		return true;
	return false;
}
