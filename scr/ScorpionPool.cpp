#include "ScorpionPool.h"
#include "Scorpion.h"

#include "Game Components/TEAL/CommonElements.h"

ScorpionPool::~ScorpionPool()
{
	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Bullets");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Scorpion* ScorpionPool::GetScorpion()
{
	Scorpion* b;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Scorpion"); // For illustration purposes

		b = new Scorpion();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Scorpion"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		b->RegisterToCurrentScene();
	}

	return b;
}

void ScorpionPool::ReturnScorpion(Scorpion* b)
{
	recycledItems.push(static_cast<Scorpion*>(b));

	ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));

}
