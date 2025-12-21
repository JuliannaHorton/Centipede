#pragma once

#ifndef _DeathFactory
#define _DeathFactory

#include "Game Components/TEAL/CommonElements.h"
#include "DeathPool.h"
#include "SFML/Graphics.hpp"

class GameObject;
class DeathPool;
class Death;

class DeathFactory
{
private:
	static DeathFactory* ptrInstance;			// Game set up as a singleton

	DeathFactory() = default;												// Private constructor
	DeathFactory(const DeathFactory&) = delete;				// Prevent copy-construction
	DeathFactory& operator=(const DeathFactory&) = delete;	// Prevent assignment
	~DeathFactory() = default;											// Only this class can delete

	static DeathFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new DeathFactory();
		return *ptrInstance;
	};

	DeathPool myDeathPool;

	void privCreateDeath(sf::Vector2f pos);
	void privRecycleDeath(GameObject* b);

public:

	static void CreateDeath(sf::Vector2f pos) { Instance().privCreateDeath(pos); };
	static void RecycleDeath(GameObject* b) { Instance().privRecycleDeath(b); };

	static void Terminate();
};

#endif _DeathFactory