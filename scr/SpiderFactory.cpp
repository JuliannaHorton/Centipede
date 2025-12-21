#include "SpiderFactory.h"
#include "SpiderPool.h"
#include "Spider.h"
#include "CritterSpawner.h"


SpiderFactory* SpiderFactory::ptrInstance = nullptr;

Spider* SpiderFactory::PrivCreateSpider(sf::Vector2f pos, int LR, CritterSpawner* referenceback)
{
	Spider* b = mySpiderPool.GetSpider();

	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleSpider);

	b->Initialize(pos, referenceback, LR);
	return b;
}

void SpiderFactory::PrivRecycleSpider(GameObject* b)
{
	mySpiderPool.ReturnSpider(static_cast<Spider*>(b));
}

void SpiderFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}

sf::Vector2f SpiderFactory::privGetPos()
{
	return mySpiderPool.CurSpiderPos();
}