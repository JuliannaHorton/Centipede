#include "CentipedeHead.h"
#include "CentipedeSegment.h"
#include "CentipedeHeadFactory.h"
#include "MoveState.h"
#include "MovementCollection.h"
#include "MoveFSM.h"
#include "ScoreAccessor.h"
#include "MushroomField.h"
#include "DoNothing.h"
#include "CritterSpawner.h"
#include "ExplodeFactory.h"
#include "SoundAccessor.h"

CentipedeSegment::CentipedeSegment() : Speed(4), Col(0), Row(0)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("CentipedeSegment"), 8, 2);
	MainSprite.setScale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	MainSprite.SetAnimation(0, 3);
	MainSprite.SetLoopSpeed(7);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("CentipedeSegment");
	SetCollider(MainSprite, bitmap);
	RegisterCollision<CentipedeSegment>(*this);

	pos = sf::Vector2f(WindowManager::Window().getView().getSize().x / 2, (float)Size);
	cDeath = ScoreAccessor::GetScoreCommand(ScoreAccessor::myScoreEvents::SegmentKilled);
	DeathSound = SoundAccessor::AddSound(SoundAccessor::mySoundEvents::CritterDied);
	State = &MoveFSM::StateDoNothing;
	ind = 0;

	MainSprite.setPosition(pos);

}

void CentipedeSegment::Update()
{
	//Gets the current offsets for movement
	pos.x += State->GetMoveOffsets()->set.values[ind].x * Speed;
	pos.y += State->GetMoveOffsets()->set.values[ind].y * Speed;

	ind += Speed;
	if (ind >= SizeW)
	{
		if ((int)pos.y / SizeW != Col) 
		{
			MainSprite.setScale(-MainSprite.getScale().x, 2); //Change sprite direction
		}

		Row = (int)pos.x / SizeW;
		Col = (int)pos.y / SizeW;

		SendState(State); //Sends the state to the segment behind it
		ind = 0;
	}

	if (pos.x < -1 || pos.x > WindowManager::Window().getSize().x)
	{
		ind = 0;
	}

	MainSprite.setPosition(pos);
	MainSprite.Update();
}

void CentipedeSegment::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void CentipedeSegment::Collision(Bullet* other)
{
	MushroomField::CreateMushroom(sf::Vector2f(pos.x + SizeW, pos.y)); //Spawns the mushroom directly in front
	if (Prev != nullptr)
	{
		Prev->Succession();
	}

	if (Next != nullptr)
	{
		Next->Prev = nullptr;
	}
	
	if (Leader != nullptr && Next == nullptr)
	{
		Leader->SetPrev(nullptr);
	}

	if (Leader != nullptr && Next != nullptr)
	{
		ind = 0;
	}

	ScoreAccessor::SendScoreCmd(cDeath);

	ExplodeFactory::CreateExplode(pos);
	SoundAccessor::StartSound(DeathSound);
	MarkForDestroy();
}

void CentipedeSegment::Destroy()
{
	DeregisterCollision<CentipedeSegment>(*this);
}

void CentipedeSegment::Squashed()
{
	if (Prev != nullptr)
	{
		Prev->Squashed();
	}

	MarkForDestroy();
}

void CentipedeSegment::Initialize(sf::Vector2f p, int _Speed, CentipedeSegment* prev, CritterSpawner* referenceBack)
{
	//Sets all values
	pos = p;
	Speed = _Speed;
	Prev = prev;
	if (Prev != nullptr)
	{
		Prev->SetNext(this);
	}
	MainSprite.setScale(-2, 2);
	Row = 0;
	Col = 0;
	ind = 0;
	State = &MoveFSM::StateDoNothing;

	Reference = referenceBack;
	RegisterCollision<CentipedeSegment>(*this);
}

void CentipedeSegment::CompleteReset()
{
	Prev = nullptr;
	Next = nullptr;
	Leader = nullptr;
}

void CentipedeSegment::ChangeSpriteDirection()
{
	MainSprite.setScale(-MainSprite.getScale().x, 2);
}

void CentipedeSegment::Succession()
{
	CentipedeHead* New = CentipedeHeadFactory::CreateHead(pos, Speed, State, ind, Prev, Reference);
	New->SetDirection((int)MainSprite.getScale().x);
	if (Prev != nullptr)
	{
		Prev->Next = nullptr;
		New->SetPrev(Prev);
		Prev->Leader = New;
	}

	Reference->SegmentSquashed(New); //Tells the Critter Spawner that a new head has been created

	MarkForDestroy();
}

void CentipedeSegment::ChangeState(const MoveState* newState)
{
	State = newState;
}

void CentipedeSegment::SendState(const MoveState* state)
{
	if (Prev != nullptr)
	{
		Prev->ChangeState(state);
	}
}

void CentipedeSegment::PauseSeg()
{
	State = &MoveFSM::StateDoNothing;

	if (Prev != nullptr)
	{
		Prev->PauseSeg();
	}
}

void CentipedeSegment::SetNext(CentipedeSegment* next)
{
	Next = next;
}

void CentipedeSegment::SetHead(CentipedeHead* Head)
{
	Leader = Head;
}

