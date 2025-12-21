#include "GameController.h"
#include "WaveManager.h"
#include "Game Components/FirstScene.h"
#include "ScoreManager.h"
#include "KeyboardControl.h"
#include "AIControl.h"
#include "PlayerFactory.h"
#include "PlayerManager.h"


#include <iostream>
#include <fstream>


GameController* GameController::ptrInstance = nullptr;
WaveManager* GameController::myWaves;

void GameController::privGameOn()
{
	if (myMode == GameMode::Attractor)
	{
		pattern = new AIControl();
		PlayerFactory::CreatePlayer(pattern);
	}
	else
	{
		pattern = new KeyboardControl();
		PlayerFactory::CreatePlayer(pattern);
	}

	myWaves = new WaveManager(this, pattern);
}

void GameController::privPlayerDied()
{
	myWaves->playerDied();
}

void GameController::privSwitch() //Once the scores have been checked and initials entered this gets called
{
	SceneManager::ChangeScene(new FirstScene);
}

void GameController::privPauseGame()
{
	myWaves->pauseCritters();
}

void GameController::privSetMode(int players)
{
	GameMode mode = (GameMode)players;

	switch (mode)
	{
	case GameMode::OnePlayer:
		myMode = GameMode::OnePlayer;
		break;
	case GameMode::TwoPlayer:
		myMode = GameMode::TwoPlayer;
		break;
	case GameMode::Attractor:
		myMode = GameMode::Attractor;
		break;
	}
}

int GameController::privGetMode()
{
	switch (myMode)
	{
	case GameMode::OnePlayer:
		return 1;
	case GameMode::TwoPlayer:
		return 2;
	case GameMode::Attractor:
		return 0;
	}

	return 0;
}

void GameController::privBottomHit()
{
	myWaves->centipedeHitBottom();
}

void GameController::Terminate()
{
	delete myWaves;

	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}
