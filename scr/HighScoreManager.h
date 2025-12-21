#pragma once

#ifndef _HighScoreManager
#define _HighScoreManager

struct HighScores
{
	int TopScore;
	std::string TopIn;
	int SecondScore; 
	std::string SecondIn;
	int ThirdScore;
	std::string ThirdIn;
	int FourthScore;
	std::string FourthIn;
	int FifthScore;
	std::string FifthIn;
	int SixthScore;
	std::string SixthIn;
	int SeventhScore;
	std::string SeventhIn;
	int EighthScore;
	std::string EighthIn;

	HighScores() :
		TopScore(0), SecondScore(0), ThirdScore(0), FourthScore(0), FifthScore(0), SixthScore(0), SeventhScore(0), EighthScore(0),
		TopIn(" "), SecondIn(" "), ThirdIn(" "), FourthIn(" "), FifthIn(" "), SixthIn(" "), SeventhIn(" "), EighthIn(" ") {};
};

class HighScoreManager
{
public:

	static void Terminate();

	static void CheckScores(int score1, int score2) { Instance().privCheckScores(score1, score2); };

	static int GetTopScore() { return Instance().privGetTopScore(); };
	static int GetSecondScore() { return Instance().privGetSecondScore(); };
	static int GetThirdScore() { return Instance().privGetThirdScore(); };
	static int GetFourthScore() { return Instance().privGetFourthScore(); };
	static int GetFifthScore() { return Instance().privGetFifthScore(); };
	static int GetSixthScore() { return Instance().privGetSixthScore(); };
	static int GetSeventhScore() { return Instance().privGetSeventhScore(); };
	static int GetEighthScore() { return Instance().privGetEighthScore(); };

	static std::string GetTopInitials() { return Instance().privGetTopInitials(); };
	static std::string GetSecondInitials() { return Instance().privGetSecondInitials(); };
	static std::string GetThirdInitials() { return Instance().privGetThirdInitials(); };
	static std::string GetFourthInitials() { return Instance().privGetFourthInitials(); };
	static std::string GetFifthInitials() { return Instance().privGetFifthInitials(); };
	static std::string GetSixthInitials() { return Instance().privGetSixthInitials(); };
	static std::string GetSeventhInitials() { return Instance().privGetSeventhInitials(); };
	static std::string GetEighthInitials() { return Instance().privGetEighthInitials(); };

	void ReceiveInput(std::string initials);


private:
	static HighScoreManager* ptrInstance;
	static HighScores myScores;

	HighScoreManager() = default;
	HighScoreManager(const HighScoreManager&) = delete;
	HighScoreManager& operator=(const HighScoreManager&) = delete;
	~HighScoreManager() = default;

	static HighScoreManager& Instance()	    // Access reference (all public methods will be static)
	{
		if (ptrInstance == nullptr)
			ptrInstance = new HighScoreManager();
		return *ptrInstance;
	};

	void privCheckScores(int score1, int score2);

	int privGetTopScore();
	int privGetSecondScore();
	int privGetThirdScore();
	int privGetFourthScore();
	int privGetFifthScore();
	int privGetSixthScore();
	int privGetSeventhScore();
	int privGetEighthScore();
	std::string privGetTopInitials();
	std::string privGetSecondInitials();
	std::string privGetThirdInitials();
	std::string privGetFourthInitials();
	std::string privGetFifthInitials();
	std::string privGetSixthInitials();
	std::string privGetSeventhInitials();
	std::string privGetEighthInitials();

	enum class WhichScore { TopScore, SecondScore, ThirdScore, FourthScore, FifthScore, SixthScore, SeventhScore, EighthScore};

	WhichScore Score;
};

#endif _HighScoreManager