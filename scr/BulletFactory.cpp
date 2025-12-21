#include "BulletFactory.h"
#include "BulletPool.h"
#include "Bullet.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

void BulletFactory::privCreateBullet(sf::Vector2f pos, MyPlayer* Blaster)
{
	Bullet* b = myBulletPool.GetBullet();


	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleBullet);

	b->Initialize(pos, Blaster);
}

void BulletFactory::privRecycleBullet(GameObject* b)
{
	myBulletPool.ReturnBullet(static_cast<Bullet*>(b));
}


void BulletFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}