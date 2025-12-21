#pragma once

#ifndef _SoundFactory
#define _SoundFactory

#include <SFML/Audio.hpp> //For Sound Buffer

class SoundPool;
class SoundPlay;

class SoundFactory
{
private:
	SoundPool* mySoundPool;

public:
	SoundFactory();
	SoundFactory(const SoundFactory&) = delete;
	SoundFactory& operator=(const SoundFactory&) = delete;
	~SoundFactory();

	SoundPlay* CreateSound(sf::SoundBuffer sound);

	SoundPlay* CreateLoop(sf::SoundBuffer sound);
};


#endif _SoundFactory