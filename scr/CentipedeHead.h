#pragma once

#ifndef _CentipedeHead
#define _CentipedeHead


#include "Game Components/TEAL/CommonElements.h"

class Bullet;
class MoveState;
class CentipedeSegment;
class CmdScore;
class CritterSpawner;
class SoundPlay;

class CentipedeHead : public GameObject
{
public:
	CentipedeHead();
	CentipedeHead(const CentipedeHead&) = delete;
	CentipedeHead& operator=(const CentipedeHead&) = delete;
	~CentipedeHead() = default;

	//GameObject methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet* go);

	//Segment and splitting methods
	void SendState(const MoveState*);
	void SetDirection(int x); //Sets what direction the sprite is facing
	int GetDirection(); //For when creating new segments or heads
	void SetPrev(CentipedeSegment* prev);
	void Squashed(); //Destroys the head and the segments behind it (For when the game or wave ends)

	void CompleteReset(); //This is a method to plug up an issue I need to fix

	//Other Methods
	void Initialize(sf::Vector2f p, int Speed, const MoveState* CurState, int CurIdn, CentipedeSegment* prev, CritterSpawner* referenceback);
	void Initialize(sf::Vector2f p, int Speed, CentipedeSegment* prev, CritterSpawner* referenceback, bool zone);

	int GetRow();
	int GetCol();

	void ChangeSpriteDirection(); //Changes the direction the sprite is facing 
	bool GetZone(); //Checks whether the centipede is in the bottom row for solo heads
	void Pause(); //stops the head and the segments behind it

private:
	AnimatedSprite MainSprite;
	CritterSpawner* Reference = nullptr;
	CentipedeSegment* Prev = nullptr;
	const MoveState* pCurrentState;
	SoundPlay* DeathSound;
	CmdScore* hDeath;

	sf::Vector2f pos;

	int ind;
	int Speed;

	int Row;
	int Col;

	const int Size = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 4, 2).getTextureRect().height;
	const int SizeW = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 4, 2).getTextureRect().width;

	bool stayInZone;
};

#endif _CentipedeHead