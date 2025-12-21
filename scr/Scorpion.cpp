#include "Scorpion.h"
#include "ScoreAccessor.h"
#include "CritterSpawner.h"
#include "SoundAccessor.h"
#include "ExplodeFactory.h"
#include "SoundPlay.h"

Scorpion::Scorpion() : LR(1), SPEED(4)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scorpion"), 4, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.SetAnimation(0, 3);
	MainSprite.SetLoopSpeed(10);

	sDeath = ScoreAccessor::GetScoreCommand(ScoreAccessor::myScoreEvents::ScorpionKilled);

	mySound = SoundAccessor::AddSound(SoundAccessor::mySoundEvents::ScorpionSpawn);
	DeathSound = SoundAccessor::AddSound(SoundAccessor::mySoundEvents::CritterDied);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Scorpion");
	SetCollider(MainSprite, bitmap);
	RegisterCollision<Scorpion>(*this);
}

void Scorpion::Update()
{
	pos.x += SPEED;

	if (pos.x > WindowManager::Window().getSize().x || pos.x < 0) MarkForDestroy();

	MainSprite.setPosition(pos);
	MainSprite.Update();
}

void Scorpion::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Scorpion::Collision(Bullet*)
{
	ExplodeFactory::CreateExplode(pos);
	SoundAccessor::StartSound(DeathSound);
	ScoreAccessor::SendScoreCmd(sDeath);

	MarkForDestroy();
}

void Scorpion::Destroy()
{
	SoundAccessor::StopLoop(static_cast<LoopedPlay*>(mySound));
	DeregisterCollision<Scorpion>(*this);
}

void Scorpion::Squashed()
{
	Reference->ScorpionSquashed();
	MarkForDestroy();
}

void Scorpion::Initialize(sf::Vector2f p, int _LR, int _Speed, CritterSpawner* referenceBack)
{
	pos = p;
	LR = _LR;
	SPEED = _Speed;
	Reference = referenceBack;
	SoundAccessor::StartSound(mySound);

	if (pos.x != 0)
	{
		SPEED = -SPEED;
	}
	MainSprite.setScale((float)LR, 1);


	MainSprite.setPosition(pos);
	RegisterCollision<Scorpion>(*this);
}

void Scorpion::Pause()
{
	SPEED = 0;
}