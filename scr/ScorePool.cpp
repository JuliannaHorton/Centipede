#include "ScorePool.h"
#include "CmdScoreValue.h"
#include "CmdScoreByDistance.h"

ScorePool::ScorePool()
{
	// Alterninatively: pre-load the recycledItems queue is a few bullets already
}

ScorePool::~ScorePool()
{
	// forcefully delele all recycled gameobjects

	while (!Scores.empty())
	{
		delete Scores.top();
		Scores.pop();
	}
}

CmdScore* ScorePool::GetScore(const int value)
{
	CmdScoreValue* b;

	b = new CmdScoreValue(value);

	Scores.push(b);

	return b;
}

CmdScore* ScorePool::GetScore(const int value1, const int value2, const int value3, const int value4, const int value5, const int value6)
{
	CmdScoreByDistance* b;

	b = new CmdScoreByDistance(value1, value2, value3, value4, value5, value6);

	Scores.push(b);

	return b;
}