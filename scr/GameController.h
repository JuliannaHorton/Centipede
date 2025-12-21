#pragma once

#ifndef _GameController
#define _GameController

#include "Game Components/TEAL/CommonElements.h"

class CritterSpawner;
class StrategyInterface;
class WaveManager;

class GameController
{
private:

	static GameController* ptrInstance;	// set up as a singleton

	GameController() = default;
	GameController(const GameController&) = delete;
	GameController& operator=(const GameController&) = delete;
	~GameController() = default;

	static GameController& Instance()					// Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new GameController;
		return *ptrInstance;
	};


	StrategyInterface* pattern;

	void privGameOn();
	void privPlayerDied();
	void privPauseGame();

	void privSetMode(int players);
	int privGetMode();

	void privSwitch();
	void privBottomHit();

	static WaveManager* myWaves;

	enum class GameMode { OnePlayer = 1, TwoPlayer = 2, Attractor = 0 };
	GameMode myMode;

public:

	static void BottomHit() { Instance().privBottomHit(); };
	static void GameOn() { Instance().privGameOn(); };  //This intializes the Game Controller at the beginning of the game

	static void PlayerDied() { Instance().privPlayerDied(); };
	static void PauseGame() { Instance().privPauseGame(); }
	static void SetMode(int Players) { Instance().privSetMode(Players); };

	static int GetMode() { return Instance().privGetMode(); };
	static void Switch() { Instance().privSwitch(); };


	static void Terminate();

};

#endif _GameController
