
#include "MyPlayer.h"
#include "MushroomField.h"
#include "Bullet.h"
#include "DeathFactory.h"

#include "BulletFactory.h"

#include "PlayerManager.h"
#include "HUDAccess.h"
#include "GameController.h"

#include "KeyboardControl.h"
#include "SoundAccessor.h"



MyPlayer::MyPlayer() : SPEED(7)
{
	Blaster = AnimatedSprite(ResourceManager::GetTexture("Blaster"), 1, 1);

	Pos = sf::Vector2f(WindowX/2, WindowY-(float)(Blaster.getTextureRect().height*1.5));

	Blaster.setOrigin(Blaster.getTextureRect().width / 2.0f, Blaster .getTextureRect().height / 2.0f);
	Blaster.setPosition(Pos);

	bulletOn = false;

	FireSound = SoundAccessor::AddSound(SoundAccessor::mySoundEvents::FireBullet);
	DeathSound = SoundAccessor::AddSound(SoundAccessor::mySoundEvents::PlayerDied);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Blaster");
	SetCollider(Blaster, bitmap);
	RegisterCollision<MyPlayer>(*this);
}

//Methods for strategy pattern
void MyPlayer::MoveLeft()
{
	MushroomField::Obstacle obst = MushroomField::Inspect((int)(Pos.x / 16)-1, (int)(Pos.y / 16));

	if (obst == MushroomField::Obstacle::Clear)
	{
		Pos += sf::Vector2f(-SPEED, 0);
	}
}

void MyPlayer::MoveRight()
{
	MushroomField::Obstacle obst = MushroomField::Inspect((int)(Pos.x / Size)+1, (int)(Pos.y / Size));

	if (obst == MushroomField::Obstacle::Clear)
	{
		Pos += sf::Vector2f(SPEED, 0);
	}
}

void MyPlayer::MoveUp()
{
	MushroomField::Obstacle obst = MushroomField::Inspect((int)(Pos.x / Size), (int)(Pos.y / Size)-1);

	if (obst == MushroomField::Obstacle::Clear)
	{
		Pos += sf::Vector2f(0, -SPEED);
	}
}

void MyPlayer::MoveDown()
{
	MushroomField::Obstacle obst = MushroomField::Inspect((int)(Pos.x / Size), (int)(Pos.y / Size)+1);

	if (obst == MushroomField::Obstacle::Clear)
	{
		Pos += sf::Vector2f(0, SPEED);
	}
}

void MyPlayer::Fire()
{
	if (bulletOn == false) 
	{
		bulletOn = true;
		BulletFactory::CreateBullet(Pos, this);

		SoundAccessor::StartSound(FireSound);
	}
}

//Update and collisions
void MyPlayer::Update()
{
	Pattern->ExecuteInput(this);

	Tools::Clamp<float>(Pos.x, (float)HalfBlaster, WindowX - HalfBlaster);
	Tools::Clamp<float>(Pos.y, WindowY - WindowY/5, WindowY - HalfBlaster);

	Blaster.setPosition(Pos);
}

void MyPlayer::Draw()
{
	WindowManager::Window().draw(Blaster);
}

void MyPlayer::Collision(Spider*)
{
	PlayerManager::SubLife();

	GameController::PauseGame();
	DeathFactory::CreateDeath(Pos);

	SoundAccessor::StartSound(DeathSound);
	MarkForDestroy();
}

void MyPlayer::Collision(CentipedeHead*)
{
	PlayerManager::SubLife();

	GameController::PauseGame();
	DeathFactory::CreateDeath(Pos);
	
	SoundAccessor::StartSound(DeathSound);
	MarkForDestroy();
}

void MyPlayer::Collision(CentipedeSegment*)
{
	PlayerManager::SubLife();

	GameController::PauseGame();
	DeathFactory::CreateDeath(Pos);

	SoundAccessor::StartSound(DeathSound);
	MarkForDestroy();
}

void MyPlayer::Collision(Flea*)
{
	PlayerManager::SubLife();

	GameController::PauseGame();
	DeathFactory::CreateDeath(Pos);

	SoundAccessor::StartSound(DeathSound);
	MarkForDestroy();
}

void MyPlayer::Destroy()
{
	DeregisterCollision<MyPlayer>(*this);
}

void MyPlayer::Initialize(StrategyInterface* _Pattern)
{
	RegisterCollision<MyPlayer>(*this);
	Pattern = _Pattern;

	Pos = sf::Vector2f(WindowX / 2, WindowY - (float)(Blaster.getTextureRect().height * 1.5));
	Blaster.setPosition(Pos);
}

sf::Vector2f MyPlayer::GetPos()
{
	return Pos;
}

void MyPlayer::Reload()
{
	bulletOn = false; //Called by the Bullet class
}