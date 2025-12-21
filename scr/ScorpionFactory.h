#pragma once

#ifndef _ScorpionFactory
#define _ScorpionFactory

#include "Game Components/TEAL/CommonElements.h"
#include "ScorpionPool.h"
#include "SFML/Graphics.hpp"

class ScorpionPool;
class GameObject;
class Scorpion;
class CritterSpawner;

class ScorpionFactory
{
private:
	static ScorpionFactory* ptrInstance;
	
	ScorpionFactory() = default;												// Private constructor
	ScorpionFactory(const ScorpionFactory&) = delete;				// Prevent copy-construction
	ScorpionFactory& operator=(const ScorpionFactory&) = delete;	// Prevent assignment
	~ScorpionFactory() = default;											// Only this class can delete

	
	static ScorpionFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new ScorpionFactory();
		return *ptrInstance;
	};

	ScorpionPool myScorpionPool;

	Scorpion* privCreateScorpion(sf::Vector2f pos, int LR, int speed, CritterSpawner* referenceback);
	void privRecycleScorpion(GameObject* b);

public:
	static void Initialize();

	static Scorpion* CreateScorpion(sf::Vector2f pos, int LR, int speed, CritterSpawner* referenceback) { return Instance().privCreateScorpion(pos, LR, speed, referenceback); };

	static void RecycleScorpion(GameObject* b) { Instance().privRecycleScorpion(b); };

	static void Terminate();
};

#endif _ScorpionFactory