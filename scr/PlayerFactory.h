#pragma once

#ifndef _PlayerFactory
#define _PlayerFactory

#include "Game Components/TEAL/CommonElements.h"
#include "SFML/Graphics.hpp"
#include "PlayerPool.h"
#include "StrategyInterface.h"

class GameObject;

class PlayerFactory
{
private:
	static PlayerFactory* ptrInstance;			// Game set up as a singleton

	PlayerFactory() = default;												// Private constructor
	PlayerFactory(const PlayerFactory&) = delete;				// Prevent copy-construction
	PlayerFactory& operator=(const PlayerFactory&) = delete;	// Prevent assignment
	~PlayerFactory() = default;											// Only this class can delete

	static PlayerFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new PlayerFactory();
		return *ptrInstance;
	};

	PlayerPool myPlayerPool;

	void privCreatePlayer(StrategyInterface* Pattern);
	void privRecyclePlayer(GameObject* b);
	sf::Vector2f privGetPos();


public:

	static void CreatePlayer(StrategyInterface* Pattern) { Instance().privCreatePlayer(Pattern); };
	static void RecyclePlayer(GameObject* b) { Instance().privRecyclePlayer(b); };
	static sf::Vector2f GetPos() { return Instance().privGetPos(); };

	static void Terminate();
};

#endif _PlayerFactory