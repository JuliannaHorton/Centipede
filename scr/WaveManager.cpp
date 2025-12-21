#include "WaveManager.h"
#include "CritterSpawner.h"
#include "GameController.h"
#include "MushroomField.h"
#include "PlayerManager.h"
#include "HUDAccess.h"
#include "StrategyInterface.h"
#include "PlayerFactory.h"
#include "HighScoreManager.h"

#include <iostream>
#include <fstream>

WaveManager::WaveManager(GameController* myController, StrategyInterface* _pattern)
{
	mySpawner = new CritterSpawner(this);
	referenceBack = myController;
	pattern = _pattern;
	waveAmount = 0;
	headsActive = false;
	headsActiveInArea = false;

	std::string myText;
	std::string line;
	std::ifstream inputFile("../WaveControl.txt");

	std::list<std::string> WaveData;

	assert(inputFile.is_open() && "File cannot be opened");

	int Crittercount = 0;
	int Datacount = 0;



	while (std::getline(inputFile, myText)) { // Read line by line
		std::istringstream read(myText);

		read >> line;

		if (myText == "") continue;

		if (line == "Wave")
		{
			Crittercount = 0;
			waveAmount++;
			read >> line;
			assert(line == std::to_string(waveAmount) && "Your waves must be numbered correctly");
		}
		else if (line == "Active:")
		{
			read >> line;
			assert(line == "Active" || line == "NotActive" && "Active or Not Active parameter, must be Active or NotActive, fallowed by a comma");

			Datacount++;
			WaveData.push_back(line);
		}
		else if (line == "Scorpion:")
		{
			assert(Crittercount == 0 && "Please keep the critters in order: Scorpion, Flea, Spider, Solo Head, and Centipede");
			Crittercount++;

			assert(Datacount == 0 || Datacount == 2 && "Make sure all the needed values are inside each of the Centipede waves");
			Datacount = 0;
		}
		else if (line == "Flea:")
		{
			assert(Crittercount == 1 && "Please keep the critters in order: Scorpion, Flea, Spider, Solo Head, and Centipede");
			Crittercount++;

			assert(Datacount == 4 && "Make sure all the needed values are inside each of the Scorpion waves");
			Datacount = 0;
		}
		else if (line == "Spider:")
		{
			assert(Crittercount == 2 && "Please keep the critters in order: Scorpion, Flea, Spider, Solo Head, and Centipede");
			Crittercount++;

			assert(Datacount == 5 && "Make sure all the needed values are inside each of the Flea waves");
			Datacount = 0;
		}
		else if (line == "Solo")
		{
			assert(Crittercount == 3 && "Please keep the critters in order: Scorpion, Flea, Spider, Solo Head, and Centipede");
			Crittercount++;

			assert(Datacount == 4 && "Make sure all the needed values are inside each of the Spider waves");
			Datacount = 0;
		}
		else if (line == "Centipede:")
		{
			assert(Crittercount == 4 && "Please keep the critters in order: Scorpion, Flea, Spider, Solo Head, and Centipede");
			Crittercount++;

			assert(Datacount == 8 && "Make sure all the needed values are inside each of the Solo Head waves");
			Datacount = 0;
		}
		else
		{
			if (Crittercount == 1)
			{
				if (Datacount == 1)  assert(line == "Speed:" && "Make sure the Scorpion data is in order and correct. The Scorpion should have Active, Speed, Minimum Frequency, and Maximum Frequency");
				else if (Datacount == 2)  assert(line == "Minimum" && "Make sure the Scorpion data is in order and correct. The Scorpion should have Active, Speed, Minimum Frequency, and Maximum Frequency");
				else assert(line == "Maximum" && "Make sure the Scorpion data is in order and correct. The Scorpion should have Active, Speed, Minimum Frequency, and Maximum Frequency");

				Datacount++;
			}
			else if (Crittercount == 2)
			{
				if (Datacount == 1)  assert(line == "Speed:" && "Make sure the Flea data is in order and correct. The Flea should have Active, Speed, Mushroom Threshold, Minimum Frequency, and Maximum Frequency");
				else if (Datacount == 2)  assert(line == "Mushroom" && "Make sure the Flea data is in order and correct. The Flea should have Active, Speed, Mushroom Threshold, Minimum Frequency, and Maximum Frequency");
				else if (Datacount == 3)  assert(line == "Minimum" && "Make sure the Flea data is in order and correct. The Flea should have Active, Speed, Mushroom Threshold, Minimum Frequency, and Maximum Frequency");
				else assert(line == "Maximum" && "Make sure the Flea data is in order and correct. The Flea should have Active, Speed, Mushroom Threshold, Minimum Frequency, and Maximum Frequency");

				Datacount++;
			}
			else if (Crittercount == 3)
			{
				if (Datacount == 1)  assert(line == "Speed:" && "Make sure the Spider data is in order and correct. The Spider should have Active, Speed, Minimum Frequency, and Maximum Frequency");
				else if (Datacount == 2)  assert(line == "Minimum" && "Make sure the Spider data is in order and correct. The Spider should have Active, Speed, Minimum Frequency, and Maximum Frequency");
				else assert(line == "Maximum" && "Make sure the Spider data is in order and correct. The Spider should have Active, Speed, Minimum Frequency, and Maximum Frequency");

				Datacount++;
			}
			else if (Crittercount == 4)
			{
				if (Datacount == 1)  assert(line == "Speed:" && "Make sure the Solo Head data is in order and correct. The Centipede should have Active, Count, Player Area, Player Area Speed, Minimum Frequency, and Maximum Frequency");
				else if (Datacount == 2)  assert(line == "Count:" && "Make sure the Solo Head data is in order and correct. The Centipede should have Active, Count, Player Area, Player Area Speed, Minimum Frequency, and Maximum Frequency");
				else if (Datacount == 3)
				{
					assert(line == "Player" && "Make sure the Solo Head data is in order and correct. The Centipede should have Active, Count, Player Area, Player Area Speed, Minimum Frequency, and Maximum Frequency");
					read >> line;
					read >> line;
					assert(line == "On" || line == "Off" && "The Solo Head's Player Area must be 'On' or 'Off'");
					WaveData.push_back(line);
					Datacount++;
					continue;
				}
				else if (Datacount == 4)
				{
					read >> line;
					assert(line == "Area" && "Make sure the Solo Head data is in order and correct. The Solo Head should have Active, Count, Player Area, Player Area Speed, Minimum Frequency, and Maximum Frequency");
					read >> line;
				}
				else if (Datacount == 5)
				{
					read >> line;
					read >> line;
					assert(line == "Count:" && "Make sure the Solo Head data is in order and correct. The Solo Head should have Active, Count, Player Area, Player Area Speed, Minimum Frequency, and Maximum Frequency");
				}
				else if (Datacount == 6)  assert(line == "Minimum" && "Make sure the Solo Head data is in order and correct. The Solo Head should have Active, Count, Player Area, Player Area Speed, Minimum Frequency, and Maximum Frequency");
				else assert(line == "Maximum" && "Make sure the Solo Head data is in order and correct. The Solo Head should haveActive, Count, Player Area, Player Area Speed, Minimum Frequency, and Maximum Frequency");

				Datacount++;
			}
			else if (Crittercount == 5)
			{
				if (Datacount == 0)  assert(line == "Speed:" && "Make sure the Centipede data is in order and correct. The Centipede should have Active, Speed, Minimum Frequency, and Maximum Frequency");
				else assert(line == "Length:" && "Make sure the Centipede data is in order and correct. The Centipede should have Active, Speed, Minimum Frequency, and Maximum Frequency");

				Datacount++;
			}


			read >> line;
			if (line == "Frequency:" || line == "Threshold:")
			{
				read >> line;
			}
			assert(line[0] >= '0' && line[0] <= '9' && "All parameters fallowing Active or NotActive must be a number (with the exception of Player Area in Solo Head)");

			WaveData.push_back(line);
		}
	}

	// Close the file
	inputFile.close();
	
	ScorData.resize(waveAmount);
	FleaData.resize(waveAmount);
	SpidyData.resize(waveAmount);
	HeadData.resize(waveAmount);
	CentiData.resize(waveAmount);

	for (int x = 0; x < waveAmount; x++)
	{
		if (WaveData.front() == "Active") ScorData[x].Active = true;
		else ScorData[x].Active = false;
		WaveData.pop_front();

		ScorData[x].Speed = std::stoi(WaveData.front());
		WaveData.pop_front();
		ScorData[x].Fmin = std::stoi(WaveData.front());
		WaveData.pop_front();
		ScorData[x].Fmax = std::stoi(WaveData.front());
		WaveData.pop_front();

		if (WaveData.front() == "Active") FleaData[x].Active = true;
		else FleaData[x].Active = false;
		WaveData.pop_front();

		FleaData[x].Speed = std::stoi(WaveData.front());
		WaveData.pop_front();
		FleaData[x].Threshold = std::stoi(WaveData.front());
		WaveData.pop_front();
		FleaData[x].Pmin = std::stoi(WaveData.front());
		WaveData.pop_front();
		FleaData[x].Pmax = std::stoi(WaveData.front());
		WaveData.pop_front();

		if (WaveData.front() == "Active") SpidyData[x].Active = true;
		else SpidyData[x].Active = false;
		WaveData.pop_front();

		SpidyData[x].Speed = std::stoi(WaveData.front());
		WaveData.pop_front();
		SpidyData[x].Fmin = std::stoi(WaveData.front());
		WaveData.pop_front();
		SpidyData[x].Fmax = std::stoi(WaveData.front());
		WaveData.pop_front();

		if (WaveData.front() == "Active") HeadData[x].Active = true;
		else HeadData[x].Active = false;
		WaveData.pop_front();

		HeadData[x].Speed = std::stoi(WaveData.front());
		WaveData.pop_front();
		HeadData[x].Count = std::stoi(WaveData.front());
		WaveData.pop_front();
		if (WaveData.front() == "On") HeadData[x].playerArea = true;
		else HeadData[x].playerArea = false;
		WaveData.pop_front();
		HeadData[x].playerCount = std::stoi(WaveData.front());
		WaveData.pop_front();
		HeadData[x].playerSpeed = std::stoi(WaveData.front());
		WaveData.pop_front();
		HeadData[x].Fmin = std::stoi(WaveData.front());
		WaveData.pop_front();
		HeadData[x].Fmax = std::stoi(WaveData.front());
		WaveData.pop_front();

		CentiData[x].Speed = std::stoi(WaveData.front());
		WaveData.pop_front();
		CentiData[x].Length = std::stoi(WaveData.front());
		WaveData.pop_front();

	}
	waveNum = 0;

	runWave(waveNum);
}

void WaveManager::runWave(int wave)
{
	if (ScorData[wave].Active == true)
	{
		mySpawner->SpawnScorpion(ScorData[wave].Fmin, ScorData[wave].Fmax, ScorData[wave].Speed);
	}

	if (FleaData[wave].Active == true)
	{
		mySpawner->SpawnFlea(FleaData[wave].Pmin, FleaData[wave].Pmax, 30);
	}

	if (SpidyData[wave].Active == true)
	{
		mySpawner->SpawnSpider(SpidyData[wave].Fmin, SpidyData[wave].Fmax, SpidyData[wave].Speed);
	}

	mySpawner->SpawnCentipede(CentiData[wave].Length, CentiData[wave].Speed);
}

void WaveManager::playerDied()
{
	mySpawner->NewWave(); //Cancels alarms and destroys all active critters
	headsActive = false;
	headsActiveInArea = false;

	MushroomField::HealAll(); //Heals all the mushrooms


	if (referenceBack->GetMode() == 2)
	{
		PlayerManager::SaveWave(waveNum);
		MushroomField::SaveField();

		if (PlayerManager::WhatPlayer() == 1)
		{
			PlayerManager::SetPlayer(2);
		}
		else PlayerManager::SetPlayer(1);

		int livesLeft = PlayerManager::GetLife();
		if (livesLeft > 0)
		{
			HUDAccess::UpdateLife(); //Removes a life icon
			PlayerFactory::CreatePlayer(pattern); //Respawns the player
			MushroomField::GenerateField();
			HUDAccess::PlayerSwitch(); //Displays which player is playing next
			waveNum = PlayerManager::GetWave();
			runWave(waveNum);
		}
		else
		{
			HighScoreManager::CheckScores(PlayerManager::GetOneScore(), PlayerManager::GetTwoScore()); //If were in One Player Mode, 2's scores will autimatically be 0

			PlayerManager::Reset();
		}
	}
	else //Player One or Attractor mode
	{
		int livesLeft = PlayerManager::GetLife();
		if (livesLeft > 0)
		{
			HUDAccess::UpdateLife(); //Removes a life icon
			PlayerFactory::CreatePlayer(pattern); //Respawns the player
			runWave(waveNum);
		}
		else
		{
			HighScoreManager::CheckScores(PlayerManager::GetOneScore(), PlayerManager::GetTwoScore()); //If were in One Player Mode, 2's scores will autimatically be 0

			PlayerManager::Reset();
		}
	}

}

void WaveManager::centipedeDied()
{
	MushroomField::HealAll();
	headsActive = false;
	headsActiveInArea = false;
	mySpawner->NewWave();

	if (waveNum < waveAmount)
	{
		waveNum++;
	}

	runWave(waveNum);
}

void WaveManager::centipedeHitBottom()
{
	/*if (HeadData[waveNum].Active == true && headsActive == false)
	{
		mySpawner->SpawnSoloHead(HeadData[waveNum].Speed, HeadData[waveNum].Count, HeadData[waveNum].Fmin, HeadData[waveNum].Fmax);
		headsActive = true;
	}
	if (HeadData[waveNum].playerArea == true && headsActiveInArea == false)
	{
		mySpawner->SpawnSoloHead(HeadData[waveNum].playerSpeed, HeadData[waveNum].playerCount, true, HeadData[waveNum].Fmin, HeadData[waveNum].Fmax);
		headsActiveInArea = true;
	}*/
}

void WaveManager::pauseCritters()
{
	mySpawner->PauseCritters();
}

