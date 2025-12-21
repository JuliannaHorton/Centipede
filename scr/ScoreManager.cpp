#include "ScoreManager.h"

#include <iostream>
#include "CmdScoreValue.h"
#include "CmdScoreByDistance.h"

#include "Game Components/TEAL/CommonElements.h"

#include "HUDAccess.h"
#include "PlayerManager.h"
#include "ScoreFactory.h"

ScoreManager::ScoreManager()
{
	myFactory = new ScoreFactory();
}

CmdScore* ScoreManager::GetScoreCommand(int i)
{
	CmdScore* pCmd = nullptr;

	ScoreEvents ev = (ScoreEvents)i;

	switch (ev)
	{
	case ScoreEvents::FleaKilled:
		pCmd = myFactory->CreateScore(FleaDeath);
		break;
	case ScoreEvents::ScorpionKilled:
		pCmd = myFactory->CreateScore(ScorpionDeath);
		break;
	case ScoreEvents::MushroomKilled:
		pCmd = myFactory->CreateScore(MushroomDeath);
		break;
	case ScoreEvents::SpiderKilled:
		pCmd = myFactory->CreateScore(SpiderDistNear, SpiderDistMedium, SpiderDistFar,
			SpiderDeathNear, SpiderDeathMedium, SpiderDeathFar);
		break;
	case ScoreEvents::MushroomPoisonKilled:
		pCmd = myFactory->CreateScore(MushroomPoisonDeath);
		break;
	case ScoreEvents::HeadKilled:
		pCmd = myFactory->CreateScore(HeadDeath);
		break;
	case ScoreEvents::SegmentKilled:
		pCmd = myFactory->CreateScore(SegmentDeath);
		break;
	}

	return pCmd;
}

void ScoreManager::AddScore(int val)
{
	PlayerManager::AddScore(val); //Score Gets added to the Player's score
}

void ScoreManager::SendScoreCmd(CmdScore* c)
{
	QueueCmds.push(c);
}

void ScoreManager::ProcessScores()
{
	CmdScore* c;

	while (!QueueCmds.empty())
	{
		c = QueueCmds.front();
		c->Execute();

		QueueCmds.pop();
	}

}

void ScoreManager::Destroy()
{
	delete myFactory;
}

void ScoreManager::Update()
{
	ProcessScores();
}