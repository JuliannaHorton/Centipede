#include "DeathPool.h"
#include "Death.h"

#include "Game Components/TEAL/CommonElements.h"

DeathPool::~DeathPool()
{
	//ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Bullets");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Death* DeathPool::GetDeath()
{
	Death* b;

	if (recycledItems.empty())
	{
		//ConsoleMsg::WriteLine("New Bullet"); //I just kept these in, in case I wanted to use them

		b = new Death();
	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled Bullet"); // For illustration purposes
		b = recycledItems.top();
		recycledItems.pop();

		b->RegisterToCurrentScene();
	}

	return b;
}

void DeathPool::ReturnDeath(Death* b)
{
	recycledItems.push(static_cast<Death*>(b));
}