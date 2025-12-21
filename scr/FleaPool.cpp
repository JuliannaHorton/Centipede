#include "FleaPool.h"
#include "Flea.h"

#include "Game Components/TEAL/CommonElements.h"

FleaPool::~FleaPool()
{
	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Bullets");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Flea* FleaPool::GetFlea()
{
	Flea* b;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Flea"); // For illustration purposes

		b = new Flea();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Flea"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();

		b->RegisterToCurrentScene();
	}

	return b;
}

void FleaPool::ReturnFlea(Flea* b)
{
	recycledItems.push(static_cast<Flea*>(b));

	ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));

}
