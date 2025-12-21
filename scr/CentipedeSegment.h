#pragma once

#ifndef _CentipedeSegment
#define _CentipedeSegment


#include "Game Components/TEAL/CommonElements.h"

class Bullet;
class CentipedeHead;
class MoveState;
class CmdScore;
class CritterSpawner;
class SoundPlay;

class CentipedeSegment : public GameObject
{
public:
	CentipedeSegment();
	CentipedeSegment(const CentipedeSegment&) = delete;
	CentipedeSegment& operator=(const CentipedeSegment&) = delete;
	~CentipedeSegment() = default;

	//GameObject methods
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Bullet* go);

	//Methods for segments and splitting
	void ChangeState(const MoveState* newState);
	void SendState(const MoveState*);
	void SetNext(CentipedeSegment* Next);
	void SetHead(CentipedeHead* Head);

	void Succession(); //Creates the new head and destroys the segment
	void Squashed();
	void PauseSeg(); 

	void CompleteReset();

	//Other methods
	void ChangeSpriteDirection(); //Changes the direction the sprite is facing

	void Initialize(sf::Vector2f p, int Speed, CentipedeSegment* prev, CritterSpawner* referenceBack); //Used when a new Segment is created

	int GetRow();
	int GetCol();

private:
	AnimatedSprite MainSprite;
	CritterSpawner* Reference = nullptr;
	CentipedeSegment* Prev = nullptr;
	CentipedeSegment* Next = nullptr;
	CentipedeHead* Leader = nullptr;
	const MoveState* State;
	CmdScore* cDeath;
	SoundPlay* DeathSound;

	sf::Vector2f pos;

	int Row;
	int Col;
	int Speed;
	int ind;

	const int Size = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 4, 2).getTextureRect().height;
	const int SizeW = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 4, 2).getTextureRect().width;
};

#endif _CentipedeSegment

