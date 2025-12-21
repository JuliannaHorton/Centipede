#include "SoundManager.h"

#include <iostream>
#include "SoundPlay.h"
#include "SinglePlay.h"
#include "LoopedPlay.h"
#include "SoundFactory.h"

#include "Game Components/TEAL/CommonElements.h"

SoundManager::SoundManager()
{
	myFactory = new SoundFactory();
}

SoundPlay* SoundManager::GetSoundCommand(int ev)
{
	SoundPlay* sound = nullptr;

	SoundEvents eve = (SoundEvents)ev;

	switch (eve)
	{
	case SoundEvents::PlayerDied:
		sound = myFactory->CreateSound(PlayerDeath);
		break;
	case SoundEvents::FleaSpawn:
		sound = myFactory->CreateLoop(FleaSpawned);
		break;
	case SoundEvents::ScorpionSpawn:
		sound = myFactory->CreateLoop(ScorpionSpawned);
		break;
	case SoundEvents::SpiderSpawn:
		sound = myFactory->CreateLoop(SpiderSpawned);
		break;
	case SoundEvents::FireBullet:
		sound = myFactory->CreateSound(Fired);
		break;
	case SoundEvents::CritterDied:
		sound = myFactory->CreateSound(Killed);
		break;
	}

	return sound;
}

void SoundManager::SendSound(SoundPlay* sound)
{
	QueueSounds.push(sound);
}

void SoundManager::StopLoop(LoopedPlay* sound)
{
	sound->StopLoop();
}

void SoundManager::Update()
{
	SoundPlay* c;

	while (!QueueSounds.empty())
	{
		c = QueueSounds.front();
		c->Execute();

		QueueSounds.pop();
	}

}

void SoundManager::Destroy()
{
	delete myFactory;
}