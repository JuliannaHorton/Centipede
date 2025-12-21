#include "SoundPool.h"
#include "LoopedPlay.h"
#include "SinglePlay.h"

SoundPool::~SoundPool()
{
	// forcefully delele all recycled gameobjects

	while (!Sounds.empty())
	{
		delete Sounds.top();
		Sounds.pop();
	}
}

SoundPlay* SoundPool::GetSound(sf::SoundBuffer sound)
{
	SinglePlay* b;

	b = new SinglePlay(sound);

	Sounds.push(b);

	return b;
}

SoundPlay* SoundPool::GetLoop(sf::SoundBuffer sound)
{
	SinglePlay* b;

	b = new SinglePlay(sound);

	Sounds.push(b);

	return b;
}