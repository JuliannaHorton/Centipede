#include "CentipedeSegmentPool.h"
#include "CentipedeSegment.h"

#include "Game Components/TEAL/CommonElements.h"

CentipedeSegmentPool::CentipedeSegmentPool()
{
	// Alterninatively: pre-load the recycledItems queue is a few bullets already
}

CentipedeSegmentPool::~CentipedeSegmentPool()
{
	// forcefully delele all recycled gameobjects

	//ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Bullets");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeSegment* CentipedeSegmentPool::GetSeg()
{
	CentipedeSegment* b;

	if (recycledItems.empty())
	{
		//ConsoleMsg::WriteLine("New Head"); // For illustration purposes

		b = new CentipedeSegment();
	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled Head"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();
	}

	return b;
}

void CentipedeSegmentPool::ReturnSeg(CentipedeSegment* b)
{
	recycledItems.push(static_cast<CentipedeSegment*>(b));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));

}