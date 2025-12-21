#pragma once
#pragma once

#ifndef _WaveManager
#define _WaveManager

#include <vector>

struct ScorpionData
{
	bool Active;
	int Speed;

	//I still want the Scorpion to spawn within a random amount of time
	//so I'm giving the frequency a min and max
	int Fmin;
	int Fmax;

	ScorpionData(bool a, int s, int min, int max)
		: Active(a), Speed(s), Fmin(min), Fmax(max) {
	};

	ScorpionData()
		: Active(false), Speed(5), Fmin(5), Fmax(60) {
	};
};

struct FleaData
{
	bool Active;
	int Speed;
	int Threshold; //Minimum amount of Mushrooms to be on Screen
	int Pmin;  //Minimum probability of Spawning a Mushroom
	int Pmax;  //Maximum probability of Spawning a Mushroom

	FleaData(bool a, int s, int t, int min, int max)
		: Active(a), Speed(s), Threshold(t), Pmin(min), Pmax(max) {
	};

	FleaData()
		: Active(false), Speed(5), Threshold(30), Pmin(5), Pmax(60) {
	};  //1/5 probability
};

struct SpiderData
{
	bool Active;
	int Speed;
	int Fmin;
	int Fmax;

	SpiderData(bool a, int s, int t, int min, int max)
		: Active(a), Speed(s), Fmin(min), Fmax(max) {
	};

	SpiderData()
		: Active(false), Speed(2), Fmin(1), Fmax(10) {
	};  //1/5 probability
};

struct SoloHeadData
{
	bool Active;
	int Speed;
	int Count;
	bool playerArea;
	int playerCount;
	int playerSpeed;
	int Fmin;
	int Fmax;

	SoloHeadData(bool a, int s, int c, bool pA, int pC, int pS, int min, int max)
		: Active(a), Speed(s), Count(c), playerArea(pA), playerCount(pC), playerSpeed(pS), Fmin(min), Fmax(max) {
	};

	SoloHeadData()
		: Active(false), Speed(4), Count(3), playerArea(false), playerCount(3), playerSpeed(4), Fmin(1), Fmax(30) {
	};
};

struct CentipedeData
{
	int Speed;
	int Length; //time in seconds

	CentipedeData(int s, int l)
		: Speed(s), Length(l) {
	};

	CentipedeData()
		: Speed(4), Length(5) {
	};  //1/5 probability
};


class CritterSpawner;
class GameController;
class StrategyInterface;


class WaveManager
{

public:
	WaveManager() = default;
	WaveManager(const WaveManager&) = delete;
	WaveManager& operator=(const WaveManager&) = delete;
	~WaveManager() = default;

	WaveManager(GameController* reference, StrategyInterface* );

	void runWave(int wave);
	void playerDied();
	void centipedeDied();
	void centipedeHitBottom();
	void pauseCritters();

private:
	std::vector<ScorpionData> ScorData;
	std::vector<FleaData> FleaData;
	std::vector<SpiderData> SpidyData;
	std::vector<SoloHeadData> HeadData;
	std::vector<CentipedeData> CentiData;
	
	CritterSpawner* mySpawner;
	GameController* referenceBack;
	StrategyInterface* pattern;
	int waveAmount;
	int waveNum;

	bool headsActive;
	bool headsActiveInArea;
};

#endif _WaveManager
