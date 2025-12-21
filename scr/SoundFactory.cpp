
#include "SoundFactory.h"
#include "SoundPool.h"
#include "SoundPlay.h"

SoundFactory::SoundFactory()
{
	mySoundPool = new SoundPool();
}

SoundFactory::~SoundFactory()
{
	delete mySoundPool;
}

SoundPlay* SoundFactory::CreateSound(sf::SoundBuffer sound)
{
	return mySoundPool->GetSound(sound);
}

SoundPlay* SoundFactory::CreateLoop(sf::SoundBuffer sound)
{
	return mySoundPool->GetLoop(sound);
}