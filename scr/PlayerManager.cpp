#include "PlayerManager.h"
#include "HUDAccess.h"


PlayerManager* PlayerManager::ptrInstance = nullptr;

PlayerManager::PlayerManager()
{
	CurPlayer = &PlayerAI; //Should CurPlayer be a pointer?
	Who = 0;
}

Player PlayerManager::PlayerOne = Player(0, 3, 0); //Default values
Player PlayerManager::PlayerTwo = Player(0, 3, 0); //Default values
Player PlayerManager::PlayerAI = Player(0, 3, 0); //Default values

void PlayerManager::privSubLife()
{
	CurPlayer->Lives--;
}

int PlayerManager::privGetLife()
{
	return CurPlayer->Lives;
}

void PlayerManager::privSetScore(int s)
{
	CurPlayer->CurScore = s;
	HUDAccess::UpdateScore(s);
}

void PlayerManager::privAddScore(int v)
{
	CurPlayer->CurScore += v;
	HUDAccess::UpdateScore(v);
}

int PlayerManager::privGetScore()
{
	return CurPlayer->CurScore;
}

int PlayerManager::privGetOneScore()
{
	return PlayerOne.CurScore;
}

int PlayerManager::privGetTwoScore()
{
	return PlayerTwo.CurScore;
}

void PlayerManager::privSaveWave(int wave)
{
	CurPlayer->Level = wave;
}

int PlayerManager::privGetWave()
{
	return CurPlayer->Level;
}

void PlayerManager::privSetPlayer(int which) //Enum?
{
	if (which == 0)
	{
		CurPlayer = &PlayerAI;
		Who = 0;
	}
	else if (which == 1)
	{
		CurPlayer = &PlayerOne;
		Who = 1;
	}
	else
	{
		CurPlayer = &PlayerTwo;
		Who = 2;
	}
}

int PlayerManager::privWhatPlayer() //0 AI, 1 PlayerOne, 2 PlayerTwo
{
	return Who;
}

void PlayerManager::privAddToField(sf::Vector2f pos)
{
	CurPlayer->Field.push_back(pos);
}

std::list<sf::Vector2f> PlayerManager::privGetMushroom()
{
	return CurPlayer->Field;
}

void PlayerManager::privRemoveMushroom(sf::Vector2f pos)
{
	CurPlayer->Field.remove(pos);
}

void PlayerManager::privClearFields()
{
	while (!PlayerAI.Field.empty())
	{
		PlayerAI.Field.pop_back();
	}

	while (!PlayerOne.Field.empty())
	{
		PlayerOne.Field.pop_back();
	}

	while (!PlayerTwo.Field.empty())
	{
		PlayerTwo.Field.pop_back();
	}
}

void PlayerManager::privReset()
{
	PlayerOne = Player(0, 3, 0); //Default values
	PlayerTwo = Player(0, 3, 0); //Default values
	PlayerAI = Player(0, 3, 0); //Default values

	privClearFields();
}

void PlayerManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	
}