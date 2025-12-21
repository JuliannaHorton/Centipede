#pragma once

#include "Game Components/TEAL/CommonElements.h"
#include <queue>
#include "SoundManager.h"
#include "LoopedPlay.h"

class SoundPlay;
class LoopedPlay;
class SoundManager;
class SoundInterface;

class SoundAccessor
{
private:
	// Score values;
	static SoundAccessor* ptrInstance;

	SoundAccessor() = default;
	SoundAccessor(const SoundAccessor&) = delete;
	SoundAccessor& operator=(const SoundAccessor&) = delete;
	virtual ~SoundAccessor() = default;

	static SoundAccessor& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new SoundAccessor;
		return *ptrInstance;
	};

	static int PlayerScore;

	static SoundManager* myManager;

	void privSendSound(SoundPlay* c);
	void privMute();
	void privStopLoop(LoopedPlay* c);

	bool mute = true;

	static SoundInterface* myMode;

public:
	// events
	enum class mySoundEvents { PlayerDied, FleaSpawn, ScorpionSpawn, SpiderSpawn, FireBullet, CritterDied };

	static SoundPlay* AddSound(mySoundEvents ev);

	static void StartSound(SoundPlay* c) { Instance().privSendSound(c); };

	static void Mute() { Instance().privMute(); };

	static void StopLoop(LoopedPlay* c) { Instance().privStopLoop(c); };

	static void Initialize();

	static void Terminate();
};