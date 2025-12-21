#include "CentipedeHead.h"
#include "MushroomField.h"
#include "MoveFSM.h"
#include <iostream>
#include "MovementCollection.h"
#include "MoveState.h"
#include "TurnDownSwitchToLeft.h"
#include "DoNothing.h"
#include "CentipedeSegment.h"
#include "CentipedeSegmentFactory.h"
#include "CritterSpawner.h"
#include "ScoreAccessor.h"
#include "ExplodeFactory.h"
#include "SoundAccessor.h"


struct OffsetArray;

CentipedeHead::CentipedeHead() : Speed(4)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeHead"), 8, 2);
	MainSprite.setScale(-2,2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.SetAnimation(0, 3);
	MainSprite.SetLoopSpeed(7);

	hDeath = ScoreAccessor::GetScoreCommand(ScoreAccessor::myScoreEvents::HeadKilled);
	DeathSound = SoundAccessor::AddSound(SoundAccessor::mySoundEvents::CritterDied);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("CentipedeHead");
	SetCollider(MainSprite, bitmap);
	RegisterCollision<CentipedeHead>(*this);

	pos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2, (float)Size);

	Row = (int)pos.x / SizeW;
	Col = (int)pos.y / SizeW;
	pCurrentState = &MoveFSM::StateTurnDownSwitchToLeft;
	ind = 0;
	stayInZone = false;

	MainSprite.setPosition(pos);
}

void CentipedeHead::Update()
{
	//Gets the current offsets
	pos.x += pCurrentState->GetMoveOffsets()->set.values[ind].x * Speed;
	pos.y += pCurrentState->GetMoveOffsets()->set.values[ind].y * Speed;

	ind += Speed;

	if (ind >= SizeW) //size 16
	{
		Row = (int)pos.x / SizeW;
		Col = (int)pos.y / SizeW;

		SendState(pCurrentState); //Sends the previous state to the segment behind it
		pCurrentState = pCurrentState->GetNextState(this); //Gets the next state

		ind = 0;
	}

	MainSprite.setPosition(pos);
	MainSprite.Update();
}

void CentipedeHead::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeHead::Collision(Bullet* other)
{
	ScoreAccessor::SendScoreCmd(hDeath);
	SoundAccessor::StartSound(DeathSound);
	MushroomField::CreateMushroom(sf::Vector2f(pos.x + SizeW, pos.y));

	if (Prev != nullptr)
	{
		Prev->Succession();
	}

	Reference->HeadSquashed(this);
	ExplodeFactory::CreateExplode(pos);
	MarkForDestroy();
}

void CentipedeHead::Destroy()
{
	pos = sf::Vector2f(2000, 2000);
	MainSprite.setPosition(pos);

	DeregisterCollision<CentipedeHead>(*this);
}

//This Intialized is for when a new Head is created after a split
void CentipedeHead::Initialize(sf::Vector2f p, int _Speed, const MoveState* State, int CurInd, CentipedeSegment* prev, CritterSpawner* referenceback)
{
	//I make sure each value is the same as the destroyed segment or head
	pos = p;
	pCurrentState = State;
	ind = CurInd;
	Prev = prev;
	Reference = referenceback;
	if (Prev != nullptr)
	{
		Prev->SetHead(this);
	}
	stayInZone = false;

	RegisterCollision<CentipedeHead>(*this);
}

//For when creating a new head at the beginning of the game or solohead
void CentipedeHead::Initialize(sf::Vector2f p, int _Speed, CentipedeSegment* prev, CritterSpawner* referenceback, bool zone)
{
	//All features and values are set
	pos = p;
	Speed = _Speed;
	Prev = prev;
	if (Prev != nullptr)
	{
		Prev->SetHead(this);
	}
	Row = (int)pos.x / SizeW;
	Col = (int)pos.y / SizeW;
	pCurrentState = &MoveFSM::StateTurnDownSwitchToLeft;
	ind = 0;
	MainSprite.setScale(-2, 2);
	Reference = referenceback;

	stayInZone = zone;

	RegisterCollision<CentipedeHead>(*this);
}

void CentipedeHead::CompleteReset()
{
	Prev = nullptr;
}

int CentipedeHead::GetRow()
{
	return Row;
}

int CentipedeHead::GetCol()
{
	return Col;
}

bool CentipedeHead::GetZone()
{
	return stayInZone;
}

void CentipedeHead::ChangeSpriteDirection()
{
	MainSprite.setScale(-MainSprite.getScale().x, 2);
}

int CentipedeHead::GetDirection()
{
	return (int)MainSprite.getScale().x;
}

void CentipedeHead::SetDirection(int X)
{
	MainSprite.setScale((float)X, 2);
}

void CentipedeHead::SendState(const MoveState* state)
{
	if (Prev != nullptr)
	{
		Prev->ChangeState(state);
	}
}

void CentipedeHead::SetPrev(CentipedeSegment* prev)
{
	Prev = prev;
}

void CentipedeHead::Squashed()
{
	if (Prev != nullptr)
	{
		Prev->Squashed();
	}

	MarkForDestroy();
}

void CentipedeHead::Pause()
{
	pCurrentState = &MoveFSM::StateDoNothing;

	if (Prev != nullptr)
	{
		Prev->PauseSeg();
	}
}