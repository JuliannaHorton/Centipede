#include "ExplodePool.h"
#include "Explode.h"

#include "Game Components/TEAL/CommonElements.h"

ExplodePool::~ExplodePool()
{
	//ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Bullets");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Explode* ExplodePool::GetExplode()
{
	Explode* b;

	if (recycledItems.empty())
	{
		//ConsoleMsg::WriteLine("New Bullet"); //I just kept these in, in case I wanted to use them

		b = new Explode();
	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled Bullet");

		b = recycledItems.top();
		recycledItems.pop();

		b->RegisterToCurrentScene();
	}

	return b;
}

void ExplodePool::ReturnExplode(Explode* b)
{
	recycledItems.push(static_cast<Explode*>(b));
}