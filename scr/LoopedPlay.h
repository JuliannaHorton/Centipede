#pragma once

#include "SoundPlay.h"
#include "Game Components/TEAL/CommonElements.h"

class LoopedPlay : public SoundPlay
{
public:
	LoopedPlay() = delete;
	LoopedPlay(const LoopedPlay&) = delete;
	LoopedPlay& operator=(const LoopedPlay&) = delete;
	virtual ~LoopedPlay() = default;

	LoopedPlay(sf::SoundBuffer sound);

	void StopLoop();

	virtual void Execute() override;

private:
	sf::SoundBuffer buffer;
	sf::Sound SoundUsed;
};
