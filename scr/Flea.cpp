#include "Flea.h"
#include "MushroomField.h"
#include "ScoreAccessor.h"
#include "CritterSpawner.h"
#include "SoundAccessor.h"
#include "ExplodeFactory.h"

Flea::Flea() : Health(2), SPEED(4)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Flea"), 2, 2);
	MainSprite.setScale(1, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.SetAnimation(0, 3);
	MainSprite.SetLoopSpeed(10);

	fDeath = ScoreAccessor::GetScoreCommand(ScoreAccessor::myScoreEvents::FleaKilled);
	mySound = SoundAccessor::AddSound(SoundAccessor::mySoundEvents::FleaSpawn);

	float MoreShroom = (float)(rand() % 4) / 10;
	SetAlarm(4, MoreShroom);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Flea");
	SetCollider(MainSprite, bitmap);
	RegisterCollision<Flea>(*this);
}

void Flea::Update()
{
	pos.y += SPEED;

	if (pos.y > WindowManager::Window().getSize().y)
	{
		AlarmCancel(4);
		MarkForDestroy();
	}

	MainSprite.setPosition(pos);
	MainSprite.Update();
}

void Flea::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Flea::Collision(Bullet*)
{
	Health--;
	if (Health == 1)
	{
		AlarmCancel(4);
		SPEED *= TimesSpeed; //2x speed
	}
	else if (Health == 0)
	{
		ExplodeFactory::CreateExplode(pos);
		ScoreAccessor::SendScoreCmd(fDeath);

		MarkForDestroy();
	}
}

void Flea::Destroy()
{
	SoundAccessor::StopLoop(static_cast<LoopedPlay*>(mySound));
	AlarmCancel(4);
	DeregisterCollision<Flea>(*this);
}

void Flea::Squashed()
{
	Reference->FleaSquashed();
	MarkForDestroy();
}

void Flea::Initialize(sf::Vector2f p, CritterSpawner* referenceback)
{
	pos = p;
	Health = 2;
	SPEED = 4;
	SoundAccessor::StartSound(mySound);
	RegisterCollision<Flea>(*this);
	Reference = referenceback;

	float MoreShroom = (float)(rand() % AlarmTime) / AlarmDivide;
	SetAlarm(4, MoreShroom);
}

void Flea::Alarm4()
{
	MushroomField::CreateMushroom(sf::Vector2f(pos.x- Size, pos.y));
	float MoreShroom = (float)(rand() % AlarmTime) / AlarmDivide;
	SetAlarm(4, MoreShroom);
}

void Flea::Pause()
{
	SPEED = 0;
}