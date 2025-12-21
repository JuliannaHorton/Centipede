#include "DeathFactory.h"
#include "Death.h"

DeathFactory* DeathFactory::ptrInstance = nullptr;

void DeathFactory::privCreateDeath(sf::Vector2f pos)
{
	Death* b = myDeathPool.GetDeath();

	b->SetExternalManagement(RecycleDeath);

	b->Initialize(pos);
}

void DeathFactory::privRecycleDeath(GameObject* b)
{
	myDeathPool.ReturnDeath(static_cast<Death*>(b));
}


void DeathFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}