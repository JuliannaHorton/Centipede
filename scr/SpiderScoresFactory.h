#pragma once

#ifndef _SpiderScoresFactory
#define _SpiderScoresFactory

#include "Game Components/TEAL/CommonElements.h"
#include "SpiderScoresPool.h"
#include "SFML/Graphics.hpp"

class GameObject;
class SpiderScoresPool;
class SpiderScores;

class SpiderScoresFactory
{
private:
	static SpiderScoresFactory* ptrInstance;			// Game set up as a singleton

	SpiderScoresFactory() = default;												// Private constructor
	SpiderScoresFactory(const SpiderScoresFactory&) = delete;				// Prevent copy-construction
	SpiderScoresFactory& operator=(const SpiderScoresFactory&) = delete;	// Prevent assignment
	~SpiderScoresFactory() = default;											// Only this class can delete

	static SpiderScoresFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new SpiderScoresFactory();
		return *ptrInstance;
	};

	SpiderScoresPool myScoresPool;

	void privCreateScores(sf::Vector2f pos, int Score);
	void privRecycleScores(GameObject* b);

public:

	static void CreateScores(sf::Vector2f pos, int Score) { Instance().privCreateScores(pos, Score); };
	static void RecycleScores(GameObject* b) { Instance().privRecycleScores(b); };

	static void Terminate();
};

#endif _SpiderScoresFactory