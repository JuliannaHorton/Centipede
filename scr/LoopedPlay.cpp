#include "LoopedPlay.h"
#include "SoundManager.h"

LoopedPlay::LoopedPlay(sf::SoundBuffer sound)
{
	buffer = sound;
	SoundUsed.setBuffer(buffer);
	SoundUsed.setPitch(2);
	SoundUsed.setVolume(10);
	SoundUsed.setLoop(false);

}

void LoopedPlay::StopLoop()
{
	SoundUsed.setLoop(false);
}

void LoopedPlay::Execute()
{
	SoundUsed.play();
	SoundUsed.setLoop(true);
}