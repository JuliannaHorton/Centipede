#include "CentipedeHeadFactory.h"
#include "CentipedeHead.h"
#include "CritterSpawner.h"
#include "MoveState.h"

CentipedeHeadFactory* CentipedeHeadFactory::ptrInstance = nullptr;

CentipedeHead* CentipedeHeadFactory::privCreateHead(sf::Vector2f pos, int Speed, const MoveState* State, int CurIdn, CentipedeSegment* prev, CritterSpawner* referenceback)
{
	CentipedeHead* b = myHeadPool.GetHead();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleHead);

	b->Initialize(pos, Speed, State, CurIdn, prev, referenceback);

	return b;
}

CentipedeHead* CentipedeHeadFactory::privCreateHead(sf::Vector2f pos, int Speed, CentipedeSegment* prev, CritterSpawner* referenceback, bool zone)
{
	CentipedeHead* b = myHeadPool.GetHead();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleHead);

	b->CompleteReset();
	b->Initialize(pos, Speed, prev, referenceback, zone);

	return b;
}

void CentipedeHeadFactory::privRecycleHead(GameObject* b)
{
	myHeadPool.ReturnHead(static_cast<CentipedeHead*>(b));
}

void CentipedeHeadFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
