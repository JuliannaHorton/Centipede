#pragma once

#ifndef _Mushroom
#define _Mushroom

#include "Game Components/TEAL/CommonElements.h"

#include "Scorpion.h"
#include "Cell.h"

class Bullet;
class Scorpion;
class Spider;
class CmdScore;

class Mushroom : public Cell
{
public:
	Mushroom();
	Mushroom(const Mushroom&) = delete;
	Mushroom& operator=(const Mushroom&) = delete;
	~Mushroom() = default;


	virtual void Draw();
	virtual void Collision(Bullet* go);
	virtual void Collision(Scorpion* go);
	virtual void Collision(Spider* go);
	virtual void Collision(GameObject* go) {};
	virtual void Destroy();

	bool GetPoison();
	sf::Vector2f GetPos() override;

	void Heal();
	bool lifeAlert(); //Returns whether the mushroom is hurt or poisoned

	bool amIShroom() override;
	void Initialize(sf::Vector2f p);

private:
	AnimatedSprite MainSprite;
	sf::Vector2f Pos;
	CmdScore* mDeath;

	int Health;
	bool Poison;

	const int MaxHealth = 4; //the maximum amount of health the mushroom could have, so once it reaches this number it has died
};

#endif _Mushroom