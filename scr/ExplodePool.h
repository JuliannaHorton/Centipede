#pragma once

#ifndef _ExplodePool
#define _ExplodePool

#include <stack>

class Explode;

class ExplodePool
{
private:
	std::stack<Explode*> recycledItems;

public:
	ExplodePool() = default;
	ExplodePool(const ExplodePool&) = delete;
	ExplodePool& operator=(const ExplodePool&) = delete;
	~ExplodePool();

	Explode* GetExplode();

	void ReturnExplode(Explode* b);
};

#endif _ExplodePool