#include "PlayerFactory.h"
#include "PlayerPool.h"
#include "MyPlayer.h"

PlayerFactory* PlayerFactory::ptrInstance = nullptr;

void PlayerFactory::privCreatePlayer(StrategyInterface* Pattern)
{
	MyPlayer* b = myPlayerPool.GetPlayer();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecyclePlayer);

	b->Initialize(Pattern);

}

void PlayerFactory::privRecyclePlayer(GameObject* b)
{
	myPlayerPool.ReturnPlayer(static_cast<MyPlayer*>(b));
}


void PlayerFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}

sf::Vector2f PlayerFactory::privGetPos()
{
	return myPlayerPool.CurPlayerPos();
}