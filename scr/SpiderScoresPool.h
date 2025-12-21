#pragma once

#ifndef _SpiderScoresPool
#define _SpiderScoresPool

#include <stack>

class SpiderScores;

class SpiderScoresPool
{
private:
	std::stack<SpiderScores*> recycledItems;

public:
	SpiderScoresPool() = default;
	SpiderScoresPool(const SpiderScoresPool&) = delete;
	SpiderScoresPool& operator=(const SpiderScoresPool&) = delete;
	~SpiderScoresPool();

	SpiderScores* GetScores();

	void ReturnScores(SpiderScores* b);
};

#endif _SpiderScoresPool