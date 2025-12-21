#pragma once

#ifndef _BulletFactory
#define _BulletFactory

#include "Game Components/TEAL/CommonElements.h"
#include "SFML/Graphics.hpp"
#include "BulletPool.h"

class GameObject;
class MyPlayer;

class BulletFactory
{
private:
	static BulletFactory* ptrInstance;			// Game set up as a singleton

	BulletFactory() = default;												// Private constructor
	BulletFactory(const BulletFactory&) = delete;				// Prevent copy-construction
	BulletFactory& operator=(const BulletFactory&) = delete;	// Prevent assignment
	~BulletFactory() = default;											// Only this class can delete

	static BulletFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new BulletFactory();
		return *ptrInstance;
	};

	BulletPool myBulletPool;

	void privCreateBullet(sf::Vector2f pos, MyPlayer* blaster);
	void privRecycleBullet(GameObject* b);

public:

	static void CreateBullet(sf::Vector2f pos, MyPlayer* blaster) { Instance().privCreateBullet(pos, blaster); };
	static void RecycleBullet(GameObject* b) { Instance().privRecycleBullet(b); };

	static void Terminate();
};

#endif _BulletFactory