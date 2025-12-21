#pragma once

#include <queue>
#include "Game Components/TEAL/CommonElements.h"

class CmdScore;
class ScoreFactory;

class ScoreManager : public GameObject
{
private:
	// Score values;
	const int FleaDeath = 200;
	const int ScorpionDeath = 1000;
	const int HeadDeath = 100;
	const int SegmentDeath = 10;
	const int MushroomDeath = 1;
	const int MushroomPoisonDeath = 1;

	const int SpiderDeathFar = 300;
	const int SpiderDistFar = 3;

	const int SpiderDeathMedium = 600;
	const int SpiderDistMedium = 4;

	const int SpiderDeathNear = 900;
	const int SpiderDistNear = 5;

	std::queue<CmdScore*> QueueCmds;

	ScoreFactory* myFactory;

public:
	// events

	ScoreManager();
	ScoreManager(const ScoreManager&) = delete;
	ScoreManager& operator=(const ScoreManager&) = delete;
	virtual ~ScoreManager() = default;

	void AddScore(int val);

	enum class ScoreEvents { FleaKilled = 0, ScorpionKilled = 1, MushroomKilled = 2, MushroomPoisonKilled = 3, SpiderKilled = 4, HeadKilled = 5, SegmentKilled = 6 };

	CmdScore* GetScoreCommand(int i);
	//int GetScore(CmdScore* ev);

	void SendScoreCmd(CmdScore* c);
	void ProcessScores();

	virtual void Destroy();

	virtual void Update();

};