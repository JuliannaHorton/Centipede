#pragma once

#ifndef _ScorpionPool
#define _ScorpionPool

#include <stack>
#include <SFML/Graphics.hpp>

class Scorpion;

class ScorpionPool
{
private:
	std::stack<Scorpion*> recycledItems;

public:
	ScorpionPool() = default;
	ScorpionPool(const ScorpionPool&) = delete;
	ScorpionPool& operator=(const ScorpionPool&) = delete;
	~ScorpionPool();

	Scorpion* GetScorpion();

	void ReturnScorpion(Scorpion* b);
};

#endif _ScorpionPool