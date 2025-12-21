#include "BulletPool.h"
#include "Bullet.h"

#include "Game Components/TEAL/CommonElements.h"

BulletPool::~BulletPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Bullets");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Bullet* BulletPool::GetBullet()
{
	Bullet* b;

	if (recycledItems.empty())
	{
		//ConsoleMsg::WriteLine("New Bullet");

		b = new Bullet();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Bullet"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();
	}

	return b;
}

void BulletPool::ReturnBullet(Bullet* b)
{
	recycledItems.push(static_cast<Bullet*>(b));

	// For illustration purposes
	//ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));

}