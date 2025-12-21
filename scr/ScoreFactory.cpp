
#include "ScoreFactory.h"
#include "ScorePool.h"
#include "CmdScore.h"

ScoreFactory::ScoreFactory()
{
	myScorePool = new ScorePool();
}

ScoreFactory::~ScoreFactory()
{
	delete myScorePool;
}

CmdScore* ScoreFactory::CreateScore(const int score)
{
	return myScorePool->GetScore(score);
}

CmdScore* ScoreFactory::CreateScore(const int score1, const int score2, const int score3, const int score4, const int score5, const int score6)
{
	return myScorePool->GetScore(score1, score2, score3, score4, score5, score6);
}