#include "ScoreAccessor.h"
#include "CmdScore.h"

ScoreAccessor* ScoreAccessor::ptrInstance = nullptr;
ScoreManager* ScoreAccessor::myManager;

void ScoreAccessor::Initialize()
{
	Instance().myManager = new ScoreManager();
}

CmdScore* ScoreAccessor::GetScoreCommand(myScoreEvents ev)
{
	switch (ev)
	{
	case myScoreEvents::FleaKilled:
		return myManager->GetScoreCommand(0);
		break;
	case myScoreEvents::ScorpionKilled:
		return myManager->GetScoreCommand(1);
		break;
	case myScoreEvents::MushroomKilled:
		return myManager->GetScoreCommand(2);
		break;
	case myScoreEvents::MushroomPoisonKilled:
		return myManager->GetScoreCommand(3);
		break;
	case myScoreEvents::SpiderKilled:
		return myManager->GetScoreCommand(4);
		break;
	case myScoreEvents::HeadKilled:
		return myManager->GetScoreCommand(5);
		break;
	case myScoreEvents::SegmentKilled:
		return myManager->GetScoreCommand(6);
		break;
	}

	return nullptr;
}

void ScoreAccessor::privSendScoreCmd(CmdScore* c)
{
	myManager->SendScoreCmd(c);
}

void ScoreAccessor::privAddScore(int v)
{
	myManager->AddScore(v);
}

void ScoreAccessor::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}