#pragma once


#ifndef _ScorePool
#define _ScorePool

#include <stack>
class CmdScore;

class ScorePool
{
private:
	std::stack<CmdScore*> Scores;

public:
	ScorePool();
	ScorePool(const ScorePool&) = delete;
	ScorePool& operator=(const ScorePool&) = delete;
	~ScorePool();

	CmdScore* GetScore(const int value);

	CmdScore* GetScore(const int value1, const int value2, const int value3, const int value4, const int value5, const int value6);
};


#endif _ScorePool
