#include "Letter.h"

Letter::Letter(sf::Vector2f p)
{
	Pos = p;
}

sf::Vector2f Letter::GetPos()
{
	return Pos;
}

bool Letter::amIShroom()
{
	return false;
}