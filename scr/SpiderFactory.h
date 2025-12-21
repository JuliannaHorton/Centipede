#pragma once

#ifndef _SpiderFactory
#define _SpiderFactory

#include "Game Components/TEAL/CommonElements.h"
#include "SFML/Graphics.hpp"
#include "SpiderPool.h"

class GameObject;
class Spider;
class CritterSpawner;

class SpiderFactory
{
private:
	static SpiderFactory* ptrInstance;			// Game set up as a singleton
	
	SpiderFactory() = default;												// Private constructor
	SpiderFactory(const SpiderFactory&) = delete;				// Prevent copy-construction
	SpiderFactory& operator=(const SpiderFactory&) = delete;	// Prevent assignment
	~SpiderFactory() = default;	 // Only this class can delete

	static SpiderFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new SpiderFactory();
		return *ptrInstance;
	};

	SpiderPool mySpiderPool;

	Spider* PrivCreateSpider(sf::Vector2f pos, int LR, CritterSpawner* referenceback);
	void PrivRecycleSpider(GameObject* b);
	sf::Vector2f privGetPos();

public:

	static Spider* CreateSpider(sf::Vector2f pos, int LR, CritterSpawner* referenceback) { return Instance().PrivCreateSpider(pos, LR, referenceback); };
	static void RecycleSpider(GameObject* b) { Instance().PrivRecycleSpider(b); };
	static sf::Vector2f GetPos() { return Instance().privGetPos(); };
	static void Terminate();
};

#endif _SpiderFactory
