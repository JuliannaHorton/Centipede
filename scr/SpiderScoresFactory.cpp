#include "SpiderScoresFactory.h"
#include "SpiderScores.h"

SpiderScoresFactory* SpiderScoresFactory::ptrInstance = nullptr;

void SpiderScoresFactory::privCreateScores(sf::Vector2f pos, int Score)
{
	SpiderScores* b = myScoresPool.GetScores();

	b->SetExternalManagement(RecycleScores);

	b->Initialize(pos, Score);
}

void SpiderScoresFactory::privRecycleScores(GameObject* b)
{
	myScoresPool.ReturnScores(static_cast<SpiderScores*>(b));
}


void SpiderScoresFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}