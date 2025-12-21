#pragma once

#ifndef _ExplodeFactory
#define _ExplodeFactory

#include "Game Components/TEAL/CommonElements.h"
#include "ExplodePool.h"
#include "SFML/Graphics.hpp"

class GameObject;
class ExplodePool;
class Explode;

class ExplodeFactory
{
private:
	static ExplodeFactory* ptrInstance;			// Game set up as a singleton

	ExplodeFactory() = default;												// Private constructor
	ExplodeFactory(const ExplodeFactory&) = delete;				// Prevent copy-construction
	ExplodeFactory& operator=(const ExplodeFactory&) = delete;	// Prevent assignment
	~ExplodeFactory() = default;											// Only this class can delete

	static ExplodeFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new ExplodeFactory();
		return *ptrInstance;
	};

	ExplodePool myExplodePool;

	void privCreateExplode(sf::Vector2f pos);
	void privRecycleExplode(GameObject* b);

public:

	static void CreateExplode(sf::Vector2f pos) { Instance().privCreateExplode(pos); };
	static void RecycleExplode(GameObject* b) { Instance().privRecycleExplode(b); };

	static void Terminate();
};

#endif _ExplodeFactory