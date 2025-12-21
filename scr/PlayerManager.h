
#ifndef _PlayerManager
#define _PlayerManager

#include <list>
#include "Game Components/TEAL/CommonElements.h"

class MyPlayer;

struct Player
{
	int CurScore; //Saved Score, for 2 player mode
	int Lives;
	int Level;

	std::list<sf::Vector2f> Field;

	//MyPlayer* ThisPlayer;

	Player(int c, int li, int le) : 
		CurScore(c), Lives(li), Level(le) {};
};

class PlayerManager
{
public:
	static void SubLife() { Instance().privSubLife(); };
	static int GetLife() { return Instance().privGetLife(); };

	static void SetScore(int Score) { Instance().privSetScore(Score); };
	static int GetScore() { return Instance().privGetScore(); };
	static void AddScore(int v) { Instance().privAddScore(v); };
	static int GetOneScore() { return Instance().privGetOneScore(); };
	static int GetTwoScore() { return Instance().privGetTwoScore(); };

	static void SaveWave(int wave) { Instance().privSaveWave(wave); };
	static int GetWave() { return Instance().privGetWave(); };


	static void SetPlayer(int which) { Instance().privSetPlayer(which); };
	static int WhatPlayer() { return Instance().privWhatPlayer(); };

	static void AddToField(sf::Vector2f shroom) { Instance().privAddToField(shroom); };
	static std::list<sf::Vector2f> GetMushroom() { return Instance().privGetMushroom(); };
	static void RemoveMushroom(sf::Vector2f shroom) { Instance().privRemoveMushroom(shroom); };
	static void ClearFields() { Instance().privClearFields(); };

	static void Reset() { Instance().privReset(); };
	static void Terminate();


private:
	static PlayerManager* ptrInstance;
	static Player PlayerOne;
	static Player PlayerTwo;
	static Player PlayerAI;

	PlayerManager();
	PlayerManager(const PlayerManager&) = delete;
	PlayerManager& operator=(const PlayerManager&) = delete;
	~PlayerManager() = default;

	static PlayerManager& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new PlayerManager();
		return *ptrInstance;
	};

	void privSubLife();
	int privGetLife();

	void privSetScore(int Score);
	int privGetScore();
	void privAddScore(int v);
	int privGetTwoScore();
	int privGetOneScore();

	void privSaveWave(int wave);
	int privGetWave();

	void privSetPlayer(int which);
	int privWhatPlayer();

	void privReset();

	void privAddToField(sf::Vector2f shroom);
	std::list<sf::Vector2f> privGetMushroom();
	void privRemoveMushroom(sf::Vector2f shroom);
	void privClearFields();

	Player* CurPlayer;
	int Who; //Which player is playing (it felt easier to return it as an int)

};

#endif _PlayerManager