#include "ScorpionFactory.h"
#include "Scorpion.h"
#include "CritterSpawner.h"

ScorpionFactory* ScorpionFactory::ptrInstance = nullptr;

Scorpion* ScorpionFactory::privCreateScorpion(sf::Vector2f pos, int LR, int speed, CritterSpawner* referenceback)
{
	Scorpion* b = myScorpionPool.GetScorpion();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleScorpion);

	b->Initialize(pos, LR, speed, referenceback);
	return b;
}

void ScorpionFactory::privRecycleScorpion(GameObject* b)
{
	myScorpionPool.ReturnScorpion(static_cast<Scorpion*>(b));
}

void ScorpionFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}