#pragma once

#ifndef _FleaFactory
#define _FleaFactory

#include "Game Components/TEAL/CommonElements.h"
#include "FleaPool.h"
#include "SFML/Graphics.hpp"

class FleaPool;
class GameObject;
class Flea;
class CritterSpawner;

class FleaFactory
{
private:
	static FleaFactory* ptrInstance;

	FleaFactory() = default;												// Private constructor
	FleaFactory(const FleaFactory&) = delete;				// Prevent copy-construction
	FleaFactory& operator=(const FleaFactory&) = delete;	// Prevent assignment
	~FleaFactory() = default;											// Only this class can delete

	static FleaFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new FleaFactory();
		return *ptrInstance;
	};

	FleaPool myFleaPool;

	Flea* privCreateFlea(sf::Vector2f pos, CritterSpawner* reference);
	void privRecycleFlea(GameObject* b);

public:
	static void Initialize();

	static Flea* CreateFlea(sf::Vector2f pos, CritterSpawner* reference) { return Instance().privCreateFlea(pos, reference); };

	static void RecycleFlea(GameObject* b) { Instance().privRecycleFlea(b); };

	static void Terminate();
};

#endif _FleaFactory
