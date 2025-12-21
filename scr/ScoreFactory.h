
#ifndef _ScoreFactory
#define _ScoreFactory

class ScorePool;
class CmdScore;

class ScoreFactory
{
private:
	ScorePool* myScorePool;

public:
	ScoreFactory();
	ScoreFactory(const ScoreFactory&) = delete;
	ScoreFactory& operator=(const ScoreFactory&) = delete;
	~ScoreFactory();

	CmdScore* CreateScore(const int score);

	CmdScore* CreateScore(const int score1, const int score2, const int score3, const int score4, const int score5, const int score6);

	//void RecycleScore(CmdScore* b);
};


#endif _ScoreFactory