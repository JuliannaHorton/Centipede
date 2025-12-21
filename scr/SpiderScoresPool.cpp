#include "SpiderScoresPool.h"
#include "SpiderScores.h"

#include "Game Components/TEAL/CommonElements.h"

SpiderScoresPool::~SpiderScoresPool()
{
	// forcefully delele all recycled gameobjects

	//ConsoleMsg::WriteLine("Deleting " + Tools::ToString(recycledItems.size()) + " Bullets");
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

SpiderScores* SpiderScoresPool::GetScores()
{
	SpiderScores* b;

	if (recycledItems.empty())
	{
		//ConsoleMsg::WriteLine("New Bullet"); //I just kept these in, in case I wanted to use them

		b = new SpiderScores();
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

void SpiderScoresPool::ReturnScores(SpiderScores* b)
{
	recycledItems.push(static_cast<SpiderScores*>(b));
}