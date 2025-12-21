#pragma once

#include "Game Components/TEAL/CommonElements.h"
#include <queue>
#include "ScoreManager.h"

class CmdScore;
class ScoreManager;

class ScoreAccessor
{
private:
	// Score values;
	static ScoreAccessor* ptrInstance;

	ScoreAccessor() = default;
	ScoreAccessor(const ScoreAccessor&) = delete;
	ScoreAccessor& operator=(const ScoreAccessor&) = delete;
	virtual ~ScoreAccessor() = default;

	static ScoreAccessor& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new ScoreAccessor;
		return *ptrInstance;
	};

	static int PlayerScore;

	static ScoreManager* myManager;

	void privAddScore(int v);

	void privSendScoreCmd(CmdScore* c);

public:
	// events
	enum class myScoreEvents { FleaKilled, ScorpionKilled, MushroomKilled, MushroomPoisonKilled, SpiderKilled, HeadKilled, SegmentKilled };

	static CmdScore* GetScoreCommand(myScoreEvents ev);

	static void SendScoreCmd(CmdScore* c) { Instance().privSendScoreCmd(c); };
	
	static void AddScore(int v) { Instance().privAddScore(v); };

	static void Initialize();

	static void Terminate();
};