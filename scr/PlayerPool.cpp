#include "PlayerPool.h"
#include "MyPlayer.h"

#include "Game Components/TEAL/CommonElements.h"

PlayerPool::~PlayerPool()
{
	// forcefully delele all recycled gameobjects

	ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Player");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

MyPlayer* PlayerPool::GetPlayer()
{
	MyPlayer* b;

	if (recycledItems.empty())
	{
		ConsoleMsg::WriteLine("New Bullet"); // For illustration purposes

		b = new MyPlayer();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Bullet"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();
	}

	CurPlayer = b;
	return b;
}

void PlayerPool::ReturnPlayer(MyPlayer* b)
{
	recycledItems.push(static_cast<MyPlayer*>(b));

	// For illustration purposes
	ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));

}

sf::Vector2f PlayerPool::CurPlayerPos()
{
		return CurPlayer->GetPos();
}