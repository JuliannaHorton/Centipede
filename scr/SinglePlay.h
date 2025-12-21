#pragma once

#include "SoundPlay.h"
//#include "Game Components/TEAL/CommonElements.h"

class SoundManager;

class SinglePlay : public SoundPlay
{
public:
	SinglePlay() = default;
	SinglePlay(const SinglePlay&) = delete;
	SinglePlay& operator=(const SinglePlay&) = delete;
	virtual ~SinglePlay() = default;

	SinglePlay(sf::SoundBuffer sound);

	virtual void Execute() override;

private:
	sf::Sound SoundUsed;
	sf::SoundBuffer buffer;
};
