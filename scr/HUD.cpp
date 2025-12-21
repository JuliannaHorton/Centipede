
#include "HUD.h"
#include "GameController.h"
#include "PlayerManager.h"
#include "MushroomField.h"
#include "HighScoreManager.h"
#include "Letter.h"

#include "SpriteString.h"

HUD::HUD()
{
	std::string Score;

	Score = addZeros(PlayerManager::GetScore());

	PlayerOneScore = new SpriteString(Score, sf::Vector2f(30, 0));

	std::string Life = "";

	for (int x = 1; x < PlayerManager::GetLife(); x++) //Counts how many lives there are
	{
		Life += "{";
	}

	PlayerOneLife = new SpriteString(Life, sf::Vector2f(95, 0));

	Score = addZeros(HighScoreManager::GetTopScore());

	HighScoreString = new SpriteString(Score, sf::Vector2f(WindowManager::Window().getView().getSize().x / 2 - 32, 0));

	if (PlayerManager::WhatPlayer() == 0)
	{
		AttractorScreen();
	}
	else if (GameController::GetMode() == 2)
	{
		Score = addZeros(PlayerManager::GetTwoScore());

		PlayerTwoScore = new SpriteString(Score, sf::Vector2f(WindowManager::Window().getView().getSize().x - 96, 0));

		std::string Life = "";

		for (int x = 1; x <= PlayerManager::GetLife(); x++) //Counts how many lives there are
		{
			Life += "{";
		}

		PlayerTwoLife = new SpriteString(Life, sf::Vector2f(WindowManager::Window().getView().getSize().x - 144, 0));
	}
}

void HUD::AttractorScreen()
{
	std::string Score;
	High = new SpriteString("High Score", sf::Vector2f(HalfWindow - HighScoreCenter, Size * 2));

	Score = addZeros(HighScoreManager::GetTopScore());

	Top = new SpriteString(Score + " " + HighScoreManager::GetTopInitials(), sf::Vector2f(HalfWindow - HighScoreCenter, Size * 3));

	Score = addZeros(HighScoreManager::GetSecondScore());

	Second = new SpriteString(Score + " " + HighScoreManager::GetSecondInitials(), sf::Vector2f(HalfWindow - HighScoreCenter, Size * 4));

	Score = addZeros(HighScoreManager::GetThirdScore());

	Third = new SpriteString(Score + " " + HighScoreManager::GetThirdInitials(), sf::Vector2f(HalfWindow - HighScoreCenter, Size * 5));

	Score = addZeros(HighScoreManager::GetFourthScore());

	Fourth = new SpriteString(Score + " " + HighScoreManager::GetFourthInitials(), sf::Vector2f(HalfWindow - HighScoreCenter, Size * 6));

	Score = addZeros(HighScoreManager::GetFifthScore());

	Fifth = new SpriteString(Score + " " + HighScoreManager::GetFifthInitials(), sf::Vector2f(HalfWindow - HighScoreCenter, Size * 7));

	Score = addZeros(HighScoreManager::GetSixthScore());

	Sixth = new SpriteString(Score + " " + HighScoreManager::GetSixthInitials(), sf::Vector2f(HalfWindow - HighScoreCenter, Size * 8));

	Score = addZeros(HighScoreManager::GetSeventhScore());

	Seventh = new SpriteString(Score + " " + HighScoreManager::GetSeventhInitials(), sf::Vector2f(HalfWindow - HighScoreCenter, Size * 9));

	Score = addZeros(HighScoreManager::GetEighthScore());

	Eighth = new SpriteString(Score + " " + HighScoreManager::GetEighthInitials(), sf::Vector2f(HalfWindow - HighScoreCenter, Size * 10));
}

void HUD::ScoreUpdate(int v)
{
	std::string Score;

	Score = addZeros(PlayerManager::GetScore());


	if (PlayerManager::WhatPlayer() < 2)
	{
		if ((int)Score.length() > PlayerOneScore->getStringLength()) //Checks if its longer than 4 charqacters and pushes back its position
		{
			PlayerOneScore->pushBackPos();
		}
		PlayerOneScore->SetText(Score);
	}
	else
	{
		if ((int)Score.length() > PlayerTwoScore->getStringLength())
		{
			PlayerOneScore->pushBackPos();
		}
		PlayerTwoScore->SetText(Score);
	}
}

void HUD::UpdateLife()
{
	if (PlayerManager::WhatPlayer() < 2)
	{
		PlayerOneLife->Backspace();
	}
	else
	{
		PlayerTwoLife->Backspace();
	}
}

void HUD::PlayerSwitch()
{
	std::string PlayerS;
	if (PlayerManager::WhatPlayer() == 1)
	{
		PlayerS = "Player 1";
	}
	else
	{
		PlayerS = "Player 2";
	}

	PlayerSwitchS = new SpriteString(PlayerS, sf::Vector2f((WindowManager::Window().getView().getSize().x / 2) - HighScoreCenter, WindowManager::Window().getView().getSize().y / 2));
	SetAlarm(0, 1);
}

void HUD::Alarm0()
{
	PlayerSwitchS->Delete();
}

std::string HUD::addZeros(int originalScore)
{
	std::string oldScoreString = Tools::ToString(originalScore);
	std::string scoreString;

	for (int x = 4 - oldScoreString.length(); x > 0; x--)
	{
		scoreString += "0";
	}
	scoreString += oldScoreString;

	return scoreString;
}