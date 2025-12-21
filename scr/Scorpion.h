#pragma once

#ifndef _Scorpion
#define _Scorpion


#include "Game Components/TEAL/CommonElements.h"

class Mushroom;
class Bullet;
class CmdScore;
class CritterSpawner;
class SoundPlay;

class Scorpion : public GameObject
{
public:
	Scorpion();
	Scorpion(const Scorpion&) = delete;
	Scorpion& operator=(const Scorpion&) = delete;
	~Scorpion() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet* go);

	void Squashed();
	void Pause();

	void Initialize(sf::Vector2f p, int _LR, int _Speed, CritterSpawner* referenceBack);

private:
	AnimatedSprite MainSprite;
	CritterSpawner* Reference = nullptr;
	SoundPlay* mySound;
	SoundPlay* DeathSound;
	CmdScore* sDeath;


	sf::Vector2f pos;
	int LR;
	int SPEED;
};

#endif _Scorpion