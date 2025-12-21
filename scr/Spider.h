#pragma once

#ifndef _Spider
#define _Spider


#include "Game Components/TEAL/CommonElements.h"

class Bullet;
class CmdScore;
class CritterSpawner;
class SoundPlay;

class Spider : public GameObject
{
public:
	Spider();
	Spider(const Spider&) = delete;
	Spider& operator=(const Spider&) = delete;
	~Spider() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet* go);

	virtual void Alarm0();

	void Initialize(sf::Vector2f p, CritterSpawner* referenceback, int _LR);
	void Squashed();
	void Pause();

	sf::Vector2f GetPos();

private:
	AnimatedSprite MainSprite;
	CritterSpawner* Reference = nullptr;
	SoundPlay* mySound;
	CmdScore* pDeath;

	sf::Vector2f pos;
	int LR;
	int x;
	int y;

	const float WindowY = WindowManager::Window().getView().getSize().y;
	const float WindowX = WindowManager::Window().getView().getSize().x;
	const int AlarmDivide = 10;
	const int alarmTimeMax = 3;
	const int alarmTimeMin = 2;
	const int RandomTwo = 2;
};

#endif _Spider