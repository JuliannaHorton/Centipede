#pragma once

#ifndef _MushroomField
#define _MushroomField

#include "Game Components/TEAL/CommonElements.h"
#include "MushroomPool.h"

class Mushroom;
class GameObject;
class Cell;

class  MushroomField
{
public:
	//Used to create and remove mushrooms
	static void CreateMushroom(sf::Vector2f pos) { Instance().privCreateShroom(pos); };
	static void RecycleMushroom(GameObject* b) { Instance().privRecycleShroom(b); }; // Arguments must be GameObject since it will be called by the base class
	static void Terminate();

	//For Field Info and Access
	static void GenerateField() { Instance().privGenerateField(); };
	static void AddtoGrid(Cell* cell) { Instance().privAddtoGrid(cell); };
	static void SaveField() { Instance().privSaveField(); };
	static void HealAll() { Instance().privHealAll(); };
	static int getShroomNumbers() { return Instance().privGetShroomNumbers(); };

	//For Grid Info and Access
	enum class Obstacle { Clear = 0, Blocked = 1, Poisoned = 2 };
	static Obstacle Inspect(int row, int col) { return Instance().privInspect(row, col); };
	static void removeShroomPos(sf::Vector2f pos) { Instance().privRemoveShroomPos(pos); };
	static sf::Vector2f getGridPos(sf::Vector2f pos) { return Instance().privGetGridPos(pos); };
	static const int TOP_PLAYER_ROW = 20;
	static const int BOTTOM_ROW = 30;

private:
	static MushroomField* ptrInstance;

	MushroomField() = default;
	MushroomField(const MushroomField&) = delete;
	MushroomField& operator=(const MushroomField&) = delete;
	~MushroomField() = default;

	static MushroomField& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new MushroomField();
		return *ptrInstance;
	};

	void privCreateShroom(sf::Vector2f pos);
	void privRecycleShroom(GameObject* b);
	void privGenerateField();
	void privSaveField();
	void privHealAll();
	sf::Vector2f privGetGridPos(sf::Vector2f pos);
	int privGetShroomNumbers();
	void privRemoveShroomPos(sf::Vector2f pos);

	void privAddtoGrid(Cell* cell);
	Obstacle privInspect(int row, int col);

	int X = 0;
	int Y = 0;
	int Counter = 0;
	static Cell* MushroomPosition[30][30]; //30 by 30 grid

	MushroomPool myMushroomPool;
	const int shroomAmountMax = 20;
	const int shroomAmountMin = 10;
	const int ShroomSize = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2).getTextureRect().width;
	const int QuarterShroom = ShroomSize / 3;

};

#endif _MushroomField