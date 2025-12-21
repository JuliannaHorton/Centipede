#include "SinglePlay.h"
#include "SoundManager.h"

SinglePlay::SinglePlay(sf::SoundBuffer sound)
{
	buffer = sound;
	SoundUsed.setBuffer(buffer);
	SoundUsed.setPitch(2);
	SoundUsed.setVolume(10);

}

void SinglePlay::Execute()
{
	SoundUsed.play();
}