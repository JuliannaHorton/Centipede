#include "MushroomPool.h"
#include "Cell.h"
#include "Mushroom.h"

MushroomPool::~MushroomPool()
{
	// forcefully delele all recycled gameobjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}


Mushroom* MushroomPool::GetMushroom()
{
	Mushroom* b;

	if (recycledItems.empty())
	{
		b = new Mushroom();
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();
	}

	return b;
}

void MushroomPool::ReturnMushroom(Mushroom* b)
{
	recycledItems.push(static_cast<Mushroom*>(b));

}