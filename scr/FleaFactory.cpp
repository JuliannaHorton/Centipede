#include "FleaFactory.h"
#include "Flea.h"
#include "CritterSpawner.h"

FleaFactory* FleaFactory::ptrInstance = nullptr;

Flea* FleaFactory::privCreateFlea(sf::Vector2f pos, CritterSpawner* Referenceback)
{
	Flea* b = myFleaPool.GetFlea();

	b->SetExternalManagement(RecycleFlea);

	b->Initialize(pos, Referenceback);
	return b;
}

void FleaFactory::privRecycleFlea(GameObject* b)
{
	myFleaPool.ReturnFlea(static_cast<Flea*>(b));
}

void FleaFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
