#pragma once

#include "Game Components/TEAL/CommonElements.h"
#include <queue>

class SoundPlay;
class LoopedPlay;
class SoundFactory;

class SoundManager : public GameObject
{
private:
	// Score values;
	const sf::SoundBuffer PlayerDeath = ResourceManager::GetSound("Death");
	const sf::SoundBuffer FleaSpawned = ResourceManager::GetSound("Flea");
	const sf::SoundBuffer ScorpionSpawned = ResourceManager::GetSound("Scorpion");
	const sf::SoundBuffer SpiderSpawned = ResourceManager::GetSound("Spider");
	const sf::SoundBuffer Fired = ResourceManager::GetSound("Fire");
	const sf::SoundBuffer Killed = ResourceManager::GetSound("Kill");

	SoundFactory* myFactory;

	std::queue<SoundPlay*> QueueSounds;

	sf::Sound test;

public:
	SoundManager();
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;
	virtual ~SoundManager() = default;

	// events
	enum class SoundEvents { PlayerDied = 0, FleaSpawn = 1, ScorpionSpawn = 2, SpiderSpawn = 3, FireBullet = 4, CritterDied = 5 };

	void SendSound(SoundPlay* c);

	SoundPlay* GetSoundCommand(int ev);

	void StopLoop(LoopedPlay* sound);

	virtual void Destroy();

	virtual void Update();
};