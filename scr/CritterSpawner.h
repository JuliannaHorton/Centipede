#pragma once

#ifndef _CritterSpawner
#define _CritterSpawner


#include "Game Components/TEAL/CommonElements.h"

class Spider;
class Scorpion;
class Flea;
class CentipedeHead;
class CentipedeSegment;
class WaveManager;

class CritterSpawner : public GameObject
{
public:
	CritterSpawner() = default;
	CritterSpawner(const CritterSpawner&) = delete;
	CritterSpawner& operator=(const CritterSpawner&) = delete;
	~CritterSpawner() = default;

	CritterSpawner(WaveManager* referenceBack);

	virtual void Alarm1(); //Scorpion Spawner
	virtual void Alarm2(); //Spider Spawner
	virtual void Alarm3(); //Flea Spawner

	//Critter Spawners
	void SpawnScorpion(int MinTime, int MaxTime, int speed); //time == frequency
	void SpawnSpider(int MinTime, int MaxTime, int speed);
	void SpawnFlea(int MinTime, int MaxTime, int threshold);

	//Centipede Spawners
	void SpawnCentipede(int length, int Speed);
	//void SpawnSoloHead(int Speed, int count, int MinTime, int MaxTime);
	//void SpawnSoloHead(int Speed, int count, bool Area, int MinTime, int MaxTime);

	//Squashed methods are for the Critter calling back to tell the Spawner that its been destroyed
	void FleaSquashed();
	void ScorpionSquashed();
	void SpiderSquashed();
	void SegmentSquashed(CentipedeHead* NewHead);
	void HeadSquashed(CentipedeHead* OldHead);

	//New wave methods
	void NewWave();
	void PauseCritters();

private:

	//Centipede
	WaveManager* Reference;
	CentipedeSegment* Next = nullptr;
	CentipedeSegment* Cur = nullptr;
	CentipedeHead* Front = nullptr;
	std::list<CentipedeHead*> myHeads; //For keeping track of what heads are active, so they can be destroyed when the game ends or a new wave starts


	int CentiLength = 0;
	int HeadNum = 0;
	int Speed = 0;

	//Solo Head
	int headSpeed = 0;
	int headCount = 0;
	int headInAreaCount = 0;
	int minHead = 0;
	int maxHead = 0;
	bool inPlayerArea = 0;

	//Scorpion
	bool ScorHere = false;
	Scorpion* myScorpion = nullptr;
	int ScorSpeed = 0;
	int MinScor = 0;
	int MaxScor = 0;

	//Spider
	Spider* mySpider = nullptr;
	int SpidySpeed = 0;
	int MinSpidy = 0;
	int MaxSpidy = 0;
	bool SpidyHere = 0;

	//Flea
	bool FleaHere = false;
	Flea* myFlea = nullptr;
	int FleaSpeed = 0;
	int ShroomNum = 0;
	int MinFlea = 0;
	int MaxFlea = 0;
};

#endif _CritterSpawner
