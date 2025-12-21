#pragma once

#ifndef _FleaPool
#define _FleaPool

#include <stack>
#include <SFML/Graphics.hpp>

class Flea;

class FleaPool
{
private:
	std::stack<Flea*> recycledItems;

public:
	FleaPool() = default;
	FleaPool(const FleaPool&) = delete;
	FleaPool& operator=(const FleaPool&) = delete;
	~FleaPool();

	Flea* GetFlea();

	void ReturnFlea(Flea* b);
};

#endif _FleaPool