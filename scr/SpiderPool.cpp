#include "SpiderPool.h"
#include "Spider.h"

#include "Game Components/TEAL/CommonElements.h"

SpiderPool::~SpiderPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Bullets");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Spider* SpiderPool::GetSpider()
{
	Spider* b;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Spider"); // For illustration purposes

		b = new Spider();

	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Spider"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();
	}

	CurSpider = b;
	return b;
}

void SpiderPool::ReturnSpider(Spider* b)
{
	recycledItems.push(static_cast<Spider*>(b));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));

}

sf::Vector2f SpiderPool::CurSpiderPos()
{;
	return CurSpider->GetPos();
}