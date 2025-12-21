#pragma once

#ifndef _MushroomPool
#define _MushroomPool

#include <stack>
#include <SFML/Graphics.hpp>

class Mushroom;

class MushroomPool
{
private:
	std::stack<Mushroom*> recycledItems;

public:
	MushroomPool() = default;
	MushroomPool(const MushroomPool&) = delete;
	MushroomPool& operator=(const MushroomPool&) = delete;
	~MushroomPool();

	Mushroom* GetMushroom();

	void ReturnMushroom(Mushroom* b);
};

#endif _MushroomPool