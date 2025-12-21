#include "HighScoreManager.h"
#include "GameController.h"
#include "InitialsInput.h"

HighScoreManager* HighScoreManager::ptrInstance = nullptr;
HighScores HighScoreManager::myScores = HighScores();

void HighScoreManager::privCheckScores(int score1, int score2)
{
	if (score2 != 0) //if it isn't 0, then player 2 is active
	{
		//Player1
		if (score1 > myScores.TopScore)
		{
			myScores.TopScore = score1;
			Score = WhichScore::TopScore;
			new InitialsInput(this);
		}
		else if (score1 > myScores.SecondScore)
		{
			myScores.SecondScore = score1;
			Score = WhichScore::SecondScore;
			new InitialsInput(this);
		}
		else if (score1 > myScores.ThirdScore)
		{
			myScores.ThirdScore = score1;
			Score = WhichScore::ThirdScore;
			new InitialsInput(this);
		}
		else if (score1 > myScores.FourthScore)
		{
			myScores.FourthScore = score1;
			Score = WhichScore::FourthScore;
			new InitialsInput(this);
		}
		else if (score1 > myScores.FifthScore)
		{
			myScores.FifthScore = score1;
			Score = WhichScore::FifthScore;
			new InitialsInput(this);
		}
		else if (score1 > myScores.SixthScore)
		{
			myScores.SixthScore = score1;
			Score = WhichScore::SixthScore;
			new InitialsInput(this);
		}
		else if (score1 > myScores.SeventhScore)
		{
			myScores.SeventhScore = score1;
			Score = WhichScore::SeventhScore;
			new InitialsInput(this);
		}
		else if (score1 > myScores.EighthScore)
		{
			myScores.EighthScore = score1;
			Score = WhichScore::EighthScore;
			new InitialsInput(this);
		}


		//Player 2
		if (score2 > myScores.TopScore)
		{
			myScores.TopScore = score2;
			Score = WhichScore::TopScore;
			new InitialsInput(this);
		}
		else if (score2 > myScores.SecondScore)
		{
			myScores.SecondScore = score2;
			Score = WhichScore::SecondScore;
			new InitialsInput(this);
		}
		else if (score2 > myScores.ThirdScore)
		{
			myScores.ThirdScore = score2;
			Score = WhichScore::ThirdScore;
			new InitialsInput(this);
		}
		else if (score2 > myScores.FourthScore)
		{
			myScores.FourthScore = score2;
			Score = WhichScore::FourthScore;
			new InitialsInput(this);
		}
		else if (score2 > myScores.FifthScore)
		{
			myScores.FifthScore = score2;
			Score = WhichScore::FifthScore;
			new InitialsInput(this);
		}
		else if (score2 > myScores.SixthScore)
		{
			myScores.SixthScore = score2;
			Score = WhichScore::SixthScore;
			new InitialsInput(this);
		}
		else if (score2 > myScores.SeventhScore)
		{
			myScores.SeventhScore = score2;
			Score = WhichScore::SeventhScore;
			new InitialsInput(this);
		}
		else if (score2 > myScores.EighthScore)
		{
			myScores.EighthScore = score2;
			Score = WhichScore::EighthScore;
			new InitialsInput(this);
		}
	}
	
	else if (score1 > myScores.TopScore) //Since Score2 wasn't 0, it will go straight into checking player 1's highscore
	{
		myScores.TopScore = score1;
		Score = WhichScore::TopScore;
		new InitialsInput(this);
	}
	else if (score1 > myScores.SecondScore)
	{
		myScores.SecondScore = score1;
		Score = WhichScore::SecondScore;
		new InitialsInput(this);
	}
	else if (score1 > myScores.ThirdScore)
	{
		myScores.ThirdScore = score1;
		Score = WhichScore::ThirdScore;
		new InitialsInput(this);
	}
	else if (score1 > myScores.FourthScore)
	{
		myScores.FourthScore = score1;
		Score = WhichScore::FourthScore;
		new InitialsInput(this);
	}
	else if (score1 > myScores.FifthScore)
	{
		myScores.FifthScore = score1;
		Score = WhichScore::FifthScore;
		new InitialsInput(this);
	}
	else if (score1 > myScores.SixthScore)
	{
		myScores.SixthScore = score1;
		Score = WhichScore::SixthScore;
		new InitialsInput(this);
	}
	else if (score1 > myScores.SeventhScore)
	{
		myScores.SeventhScore = score1;
		Score = WhichScore::SeventhScore;
		new InitialsInput(this);
	}
	else if (score1 > myScores.EighthScore)
	{
		myScores.EighthScore = score1;
		Score = WhichScore::EighthScore;
		new InitialsInput(this);
	}
	else
	{
		GameController::Switch(); //If no initials need to be added, it returns back to attractor mode
	}
}

//Receives an input from the InitialsInput class, before it destroys itself
void HighScoreManager::ReceiveInput(std::string in)
{
	//Checks what Score the initials belong to
	switch (Score)
	{
	case WhichScore::TopScore:
		myScores.TopIn = in;
		break;
	case WhichScore::SecondScore:
		myScores.SecondIn = in;
		break;
	case WhichScore::ThirdScore:
		myScores.ThirdIn = in;
		break;
	case WhichScore::FourthScore:
		myScores.FourthIn = in;
		break;
	case WhichScore::FifthScore:
		myScores.FifthIn = in;
		break;
	case WhichScore::SixthScore:
		myScores.SixthIn = in;
		break;
	case WhichScore::SeventhScore:
		myScores.SeventhIn = in;
		break;
	case WhichScore::EighthScore:
		myScores.EighthIn = in;
		break;
	}

	GameController::Switch(); //Tells the Game Controller that Intitials have been entered and can return to Attractor mode
}

int HighScoreManager::privGetTopScore()
{
	return myScores.TopScore;
}

int HighScoreManager::privGetSecondScore()
{
	return myScores.SecondScore;
}

int HighScoreManager::privGetThirdScore()
{
	return myScores.ThirdScore;
}

int HighScoreManager::privGetFourthScore()
{
	return myScores.FourthScore;
}

int HighScoreManager::privGetFifthScore()
{
	return myScores.FifthScore;
}

int HighScoreManager::privGetSixthScore()
{
	return myScores.SixthScore;
}

int HighScoreManager::privGetSeventhScore()
{
	return myScores.SeventhScore;
}

int HighScoreManager::privGetEighthScore()
{
	return myScores.EighthScore;
}

std::string HighScoreManager::privGetTopInitials()
{
	return myScores.TopIn;
}

std::string HighScoreManager::privGetSecondInitials()
{
	return myScores.SecondIn;
}

std::string HighScoreManager::privGetThirdInitials()
{
	return myScores.ThirdIn;
}

std::string HighScoreManager::privGetFourthInitials()
{
	return myScores.FourthIn;
}

std::string HighScoreManager::privGetFifthInitials()
{
	return myScores.FifthIn;
}

std::string HighScoreManager::privGetSixthInitials()
{
	return myScores.SixthIn;
}

std::string HighScoreManager::privGetSeventhInitials()
{
	return myScores.SeventhIn;
}

std::string HighScoreManager::privGetEighthInitials()
{
	return myScores.EighthIn;
}

void HighScoreManager::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}