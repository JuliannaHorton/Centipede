#pragma once
#ifndef _Cell
#define _Cell

class MyPlayer;


#include "Game Components/TEAL/CommonElements.h"

class Cell : public GameObject
{
public:
	Cell() = default;
	Cell(const Cell&) = delete;
	Cell& operator=(const Cell&) = delete;
	~Cell() = default;

	virtual sf::Vector2f GetPos() = 0;
	virtual bool amIShroom() = 0;
};

#endif _Cell