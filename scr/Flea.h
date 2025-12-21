#pragma once

#ifndef _Flea
#define _Flea


#include "Game Components/TEAL/CommonElements.h"

class Bullet;
class CmdScore;
class CritterSpawner;
class SoundPlay;

class Flea : public GameObject
{
public:
	Flea();
	Flea(const Flea&) = delete;
	Flea& operator=(const Flea&) = delete;
	~Flea() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	virtual void Alarm4();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet* go);

	void Squashed();
	void Pause();

	void Initialize(sf::Vector2f p, CritterSpawner* reference);


private:
	AnimatedSprite MainSprite;
	CritterSpawner* Reference = nullptr;
	SoundPlay* mySound;
	CmdScore* fDeath;

	sf::Vector2f pos;
	int SPEED;
	int Health;

	const int Size = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2).getTextureRect().width; //Size 16
	const int AlarmDivide = 10; //Puts the random variables into floats, for example 0.5
	const int AlarmTime = 4;
	const int TimesSpeed = 2;
};

#endif _Flea