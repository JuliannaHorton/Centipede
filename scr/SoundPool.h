#pragma once


#ifndef _SoundPool
#define _SoundPool

#include <stack>
#include <SFML/Audio.hpp> 

class SoundPlay;

class SoundPool
{
private:
	std::stack<SoundPlay*> Sounds;

public:
	SoundPool() = default;
	SoundPool(const SoundPool&) = delete;
	SoundPool& operator=(const SoundPool&) = delete;
	~SoundPool();

	SoundPlay* GetSound(sf::SoundBuffer sound);

	SoundPlay* GetLoop(sf::SoundBuffer sound);
};


#endif _SoundPool
