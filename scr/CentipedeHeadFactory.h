#pragma once

#ifndef _CentipedeHeadFactory
#define _CentipedeHeadFactory

#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeHeadPool.h"
#include "SFML/Graphics.hpp"

class CentipedeHeadPool;
class CentipedeHead;
class CentipedeSegment;
class GameObject;
class MoveState;
class CritterSpawner;

class CentipedeHeadFactory
{
private:
	static CentipedeHeadFactory* ptrInstance;

	CentipedeHeadFactory() = default;										// Private constructor
	CentipedeHeadFactory(const CentipedeHeadFactory&) = delete;				// Prevent copy-construction
	CentipedeHeadFactory& operator=(const CentipedeHeadFactory&) = delete;	// Prevent assignment
	~CentipedeHeadFactory() = default;										// Only this class can delete

	static CentipedeHeadFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new CentipedeHeadFactory();
		return *ptrInstance;
	};

	CentipedeHeadPool myHeadPool;

	CentipedeHead* privCreateHead(sf::Vector2f pos, int Speed, CentipedeSegment* prev, CritterSpawner* referenceback, bool zone);
	CentipedeHead* privCreateHead(sf::Vector2f pos, int Speed, const MoveState* State, int CurInd, CentipedeSegment* prev, CritterSpawner* referenceback);
	void privRecycleHead(GameObject* b);

public:
	static void Initialize();

	static CentipedeHead* CreateHead(sf::Vector2f pos, int Speed, const MoveState* State, int CurInd, CentipedeSegment* prev, CritterSpawner* referenceback)
		{ return Instance().privCreateHead(pos, Speed, State, CurInd, prev, referenceback); };

	static CentipedeHead* CreateHead(sf::Vector2f pos, int Speed, CentipedeSegment* prev, CritterSpawner* referenceback, bool zone)
		{ return Instance().privCreateHead(pos, Speed, prev, referenceback, zone); };

	static void RecycleHead(GameObject* b) { Instance().privRecycleHead(b); };  // Arguments must be GameObject since it will be called by the base class

	static void Terminate();
};

#endif _CentipedeHeadFactory


