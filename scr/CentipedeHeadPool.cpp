#include "CentipedeHeadPool.h"
#include "CentipedeHead.h"

#include "Game Components/TEAL/CommonElements.h"

CentipedeHeadPool::CentipedeHeadPool()
{
	// Alterninatively: pre-load the recycledItems queue is a few bullets already
}

CentipedeHeadPool::~CentipedeHeadPool()
{
	// forcefully delele all recycled gameobjects

	//ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " CentipedeHead");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

CentipedeHead* CentipedeHeadPool::GetHead()
{
	CentipedeHead* b;

	if (recycledItems.empty())
	{
		//ConsoleMsg::WriteLine("New Head"); // For illustration purposes

		b = new CentipedeHead();
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

void CentipedeHeadPool::ReturnHead(CentipedeHead* b)
{
	recycledItems.push(static_cast<CentipedeHead*>(b));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));

}