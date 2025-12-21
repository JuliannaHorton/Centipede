#pragma once
#include "Game Components/TEAL/CommonElements.h"

class SoundPlay
{
public:
	SoundPlay() = default;
	SoundPlay(const SoundPlay&) = delete;
	SoundPlay& operator=(const SoundPlay&) = delete;
	virtual ~SoundPlay() = default;

	// Note: the Excecute method must NOT have _any_ paramters
	virtual void Execute() = 0;
};
