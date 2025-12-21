#include "ExplodeFactory.h"
#include "Explode.h"

ExplodeFactory* ExplodeFactory::ptrInstance = nullptr;

void ExplodeFactory::privCreateExplode(sf::Vector2f pos)
{
	Explode* b = myExplodePool.GetExplode();


	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleExplode);

	b->Initialize(pos);
}

void ExplodeFactory::privRecycleExplode(GameObject* b)
{
	myExplodePool.ReturnExplode(static_cast<Explode*>(b));
}


void ExplodeFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}