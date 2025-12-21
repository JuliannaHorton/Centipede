#include "CritterSpawner.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "CentipedeHeadFactory.h"
#include "FleaFactory.h"
#include "CentipedeSegmentFactory.h"
#include "CentipedeHead.h"
#include "MushroomField.h"
#include "Flea.h"
#include "Scorpion.h"
#include "Spider.h"
#include "WaveManager.h"
#include "GameController.h"


CritterSpawner::CritterSpawner(WaveManager* referenceBack)
{
	Reference = referenceBack;
}


//Scorpion Spawner Methods
void CritterSpawner::Alarm1() //Scorpion
{
	if (ScorHere == false)
	{
		int LR = (rand() % 2); //Random Direction
		ScorHere = true;

		if (LR == 0) myScorpion = ScorpionFactory::CreateScorpion(sf::Vector2f(0, 200), -1, ScorSpeed, this);
		else myScorpion = ScorpionFactory::CreateScorpion(sf::Vector2f(WindowManager::Window().getView().getSize().x, 200), 1, ScorSpeed, this);
	}

	SetAlarm(4, (float)(MinScor + rand() % (MaxScor - MinScor)));
}

void CritterSpawner::SpawnScorpion(int MinTime, int MaxTime, int Speed)
{
	ScorSpeed = Speed;
	MinScor = MinTime;
	MaxScor = MaxTime;

	float time = (float)(MinTime + rand() % (MaxTime - MinTime));
	SetAlarm(1, time);
}

//Spider Spawner Methods
void CritterSpawner::Alarm2() //Spider
{
	if (SpidyHere == false)
	{
		SpidyHere = true;
		int LR = (rand() % 2); //Random Left or Right
		if (LR == 0) mySpider = SpiderFactory::CreateSpider(sf::Vector2f(0, 400), -SpidySpeed, this);
		else mySpider = SpiderFactory::CreateSpider(sf::Vector2f(WindowManager::Window().getView().getSize().x, 400), SpidySpeed, this);
	}

	SetAlarm(2, (float)(MinSpidy + rand() % (MaxSpidy - MinSpidy)));
}

void CritterSpawner::SpawnSpider(int MinTime, int MaxTime, int Speed)
{
	SpidySpeed = Speed;
	MinSpidy = MinTime;
	MaxSpidy = MaxTime;

	SetAlarm(2, (float)(MinTime + rand() % (MaxTime - MinTime)));
}

//Flea Spawner Methods
void CritterSpawner::Alarm3() //Eentually this will communicate with the mushroom field and set its time based on that
{
	if (FleaHere == false && MushroomField::getShroomNumbers() < ShroomNum)
	{
		FleaHere = true;
		float X = (float)(1 + (rand() % 31));
		myFlea = FleaFactory::CreateFlea(sf::Vector2f(X * 16, 0), this);
	}

	SetAlarm(3, (float)(MinFlea + rand() % (MaxFlea - MinFlea)));
}

void CritterSpawner::SpawnFlea(int MinTime, int MaxTime, int threshold) //Time in this case will become the mushroom threshold
{
	ShroomNum = threshold;
	MinFlea = MinTime;
	MaxFlea = MaxTime;

	SetAlarm(3, (float)(MinTime + rand() % (MaxTime - MinTime)));
}

//Centipede Spawner Methods
void CritterSpawner::SpawnCentipede(int length, int Speed)
{
	sf::Vector2f posC = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2, (float)(AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 4, 2).getTextureRect().height));

	Cur = nullptr; //Centipede Segment
	Next = nullptr; //CentipedeSegment
	Front = nullptr; //Centipede Head

	if (length != 1) //If it is length one, only the head will spawn
	{
		for (int x = 1; x != length; x++) //Iterates through the centipede length
		{
			Next = CentipedeSegmentFactory::CreateSeg(posC, Speed, Cur, this); //Receives its the segment behind it (Prev)
			Cur = Next;
		}
	}

	Front = CentipedeHeadFactory::CreateHead(posC, Speed, Cur, this, false); 
	myHeads.push_back(Front);
	HeadNum++;
}

//void CritterSpawner::Alarm4()
//{
//	int LR = (rand() % 2); //Left or Right
//
//	if (LR == 0) myHeads.push_back(CentipedeHeadFactory::CreateHead(sf::Vector2f(WindowManager::Window().getView().getSize().x, 408), headSpeed, nullptr, this, false));
//	else myHeads.push_back(CentipedeHeadFactory::CreateHead(sf::Vector2f(0, 408), headSpeed, nullptr, this, false));
//
//	HeadNum++;
//	headCount--;
//	if (headCount != 0 && minHead != 0)
//	{
//		SetAlarm(4, (float)(minHead + rand() % (maxHead - minHead)));
//	}
//}

//SoloHeads that can go outside of the player area
//void CritterSpawner::SpawnSoloHead(int speed, int count, int minTime, int maxTime)
//{
//	headSpeed = speed;
//	headCount = count;
//	minHead = minTime;
//	maxHead = maxTime;
//
//	//SetAlarm(4, (float)(minHead + rand() % (maxHead - minHead)));
//}

//void CritterSpawner::Alarm0() //hopfully doesn't mess up spider
//{
//	int LR = (rand() % 2); //Left or Right
//
//	if (LR == 0) myHeads.push_back(CentipedeHeadFactory::CreateHead(sf::Vector2f(WindowManager::Window().getView().getSize().x, 408), headSpeed, nullptr, this, true));
//	else myHeads.push_back(CentipedeHeadFactory::CreateHead(sf::Vector2f(0, 408), headSpeed, nullptr, this, true));
//
//	HeadNum++;
//	headInAreaCount--;
//	if (headInAreaCount != 0 && minHead != 0)
//	{
//		SetAlarm(0, (float)(minHead + rand() % (maxHead - minHead)));
//	}
//}

//void CritterSpawner::SpawnSoloHead(int speed, int count, bool Area, int minTime, int maxTime)
//{
//	headSpeed = speed;
//	headInAreaCount = count;
//	minHead = minTime;
//	maxHead = maxTime;
//
//	//SetAlarm(0, (float)(minHead + rand() % (maxHead - minHead)));
//}

//Squashed Methods
void CritterSpawner::ScorpionSquashed()
{
	ScorHere = false;
}

void CritterSpawner::FleaSquashed()
{
	FleaHere = false;
}

void CritterSpawner::SpiderSquashed()
{
	SpidyHere = false;
}

void CritterSpawner::SegmentSquashed(CentipedeHead* NewHead)
{
	myHeads.push_back(NewHead);
	HeadNum++;
}

void CritterSpawner::HeadSquashed(CentipedeHead* OldHead)
{
	myHeads.remove(OldHead);
	HeadNum--;

	if (HeadNum == 0)
	{
		Reference->centipedeDied();
	}
}

//New Wave Methods
void CritterSpawner::NewWave() //Level Reset
{
	//Destroys all active critters
	if (FleaHere == true)
	{
		FleaHere = false;
		myFlea->Squashed();
	}
	if (ScorHere == true)
	{
		ScorHere = false;
		myScorpion->Squashed();
	}
	if (SpidyHere == true)
	{
		SpidyHere = false;
		mySpider->Squashed();
	}

	//Destroys all heads and segments
	for (int x = 0; x < HeadNum; x++)
	{
		myHeads.back()->Squashed();
		myHeads.pop_back();
	}
	HeadNum = 0;

	//Cancel Alarms
	AlarmCancel(1);
	AlarmCancel(2);
	AlarmCancel(3);
	//AlarmCancel(4);
	//AlarmCancel(0);
}

void CritterSpawner::PauseCritters()
{
	for (CentipedeHead* Head : myHeads)
	{
		std::cout << Head << std::endl;
		Head->Pause();
	}

	if (FleaHere == true)
	{
		myFlea->Pause();
	}
	if (ScorHere == true)
	{
		myScorpion->Pause();
	}
	if (SpidyHere == true)
	{
		mySpider->Pause();
	}
}

