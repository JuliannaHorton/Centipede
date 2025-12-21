#pragma once

#ifndef _CentipedeSegmentFactory
#define _CentipedeSegmentFactory

#include "Game Components/TEAL/CommonElements.h"
#include "CentipedeSegmentPool.h"
#include "SFML/Graphics.hpp"

class CentipedeSegmentPool;
class CentipedeSegment;
class CentipedeHead;
class GameObject;
class CritterSpawner;

class CentipedeSegmentFactory
{
private:
	static CentipedeSegmentFactory* ptrInstance;

	CentipedeSegmentFactory() = default;											// Private constructor
	CentipedeSegmentFactory(const CentipedeSegmentFactory&) = delete;				// Prevent copy-construction
	CentipedeSegmentFactory& operator=(const CentipedeSegmentFactory&) = delete;	// Prevent assignment
	~CentipedeSegmentFactory() = default;											// Only this class can delete

	static CentipedeSegmentFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new CentipedeSegmentFactory();
		return *ptrInstance;
	};

	CentipedeSegmentPool mySegPool;

	CentipedeSegment* privCreateSeg(sf::Vector2f pos, int Speed, CentipedeSegment* prev, CritterSpawner* referenceBack);
	void privRecycleSeg(GameObject* b);

public:
	static void Initialize();

	static CentipedeSegment* CreateSeg(sf::Vector2f pos, int Speed, CentipedeSegment* prev, CritterSpawner* referenceBack) { return Instance().privCreateSeg(pos, Speed, prev, referenceBack); };

	static void RecycleSeg(GameObject* b) { Instance().privRecycleSeg(b); }; 

	static void Terminate();
};

#endif _CentipedeSegmentFactory

