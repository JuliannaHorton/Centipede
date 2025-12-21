#pragma once

#ifndef _DeathPool
#define _DeathPool

#include <stack>

class Death;

class DeathPool
{
private:
	std::stack<Death*> recycledItems;

public:
	DeathPool() = default;
	DeathPool(const DeathPool&) = delete;
	DeathPool& operator=(const DeathPool&) = delete;
	~DeathPool();

	Death* GetDeath();

	void ReturnDeath(Death* b);
};

#endif _DeathPool