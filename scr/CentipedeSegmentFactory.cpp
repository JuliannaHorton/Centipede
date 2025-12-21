#include "CentipedeSegmentFactory.h"
#include "CentipedeSegment.h"
#include "CentipedeHead.h"
#include "CritterSpawner.h"

CentipedeSegmentFactory* CentipedeSegmentFactory::ptrInstance = nullptr;

CentipedeSegment* CentipedeSegmentFactory::privCreateSeg(sf::Vector2f pos, int Speed, CentipedeSegment* Prev, CritterSpawner* referenceBack)
{
	CentipedeSegment* b = mySegPool.GetSeg();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleSeg);

	b->CompleteReset();
	b->Initialize(pos, Speed, Prev, referenceBack);

	return b;
}

void CentipedeSegmentFactory::privRecycleSeg(GameObject* b)
{
	mySegPool.ReturnSeg(static_cast<CentipedeSegment*>(b));
}

void CentipedeSegmentFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
