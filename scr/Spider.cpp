#include "Spider.h"
#include "ScoreAccessor.h"
#include "CritterSpawner.h"
#include "SoundAccessor.h"
#include "SoundPlay.h"
#include "ExplodeFactory.h"

Spider::Spider() : LR(1), x(0), y(0)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spider"), 4, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(2, 2);
	MainSprite.SetAnimation(0, 3);
	MainSprite.SetLoopSpeed(20);

	mySound = SoundAccessor::AddSound(SoundAccessor::mySoundEvents::SpiderSpawn);
	pDeath = ScoreAccessor::GetScoreCommand(ScoreAccessor::myScoreEvents::SpiderKilled);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Spider");
	SetCollider(MainSprite, bitmap);
	RegisterCollision<Spider>(*this);
}

void Spider::Alarm0()
{
	x = 0;
	y = 0;

	x = (rand() % RandomTwo); //1 = left/right, 0 = nothing
	y = (rand() % RandomTwo); //0 = down, 1 = up

	if (x == 1) x = LR; //Left/Right

	if (y == 0) y = LR; //Down

	if (y == 1) y = -LR; //Up

	float secs = (float)(alarmTimeMin + (rand() % alarmTimeMax)) / AlarmDivide;  //0.2 - 0.5 seconds
	SetAlarm(0, secs);
}

void Spider::Update()
{
	pos.x += x;
	pos.y += y;

	MainSprite.setPosition(pos);
	MainSprite.Update();

	Tools::Clamp<float>(pos.y, WindowY - WindowY/3, WindowY - (MainSprite.getTextureRect().height));

	if (pos.x > WindowManager::Window().getSize().x) pos.x = 0;
	else if (pos.x < 0) pos.x = (float)WindowManager::Window().getSize().x;

	if (pos.y == WindowY - WindowY / 3) AddTime(0, -5);
	else if (pos.y == WindowY - (MainSprite.getTextureRect().height)) AddTime(0, -5);
}

void Spider::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Spider::Collision(Bullet* other)
{
	ScoreAccessor::SendScoreCmd(pDeath);
	ExplodeFactory::CreateExplode(pos);
	//ConsoleMsg::WriteLine("Spider Squashed! Plus Score: " + Tools::ToString(ScoreAccessor::GetScore(pDeath)));

	AlarmCancel(0);
	Reference->SpiderSquashed();
	MarkForDestroy();
}

void Spider::Destroy()
{
	SoundAccessor::StopLoop(static_cast<LoopedPlay*>(mySound));
	DeregisterCollision<Spider>(*this);
}

void Spider::Squashed()
{
	MarkForDestroy();
}

void Spider::Initialize(sf::Vector2f p, CritterSpawner* referenceback, int _LR)
{
	pos = p;
	LR = _LR;
	Reference = referenceback;
	SoundAccessor::StartSound(mySound);
	RegisterCollision<Spider>(*this);

	float secs = (float)(alarmTimeMin + (rand() % alarmTimeMax)) / AlarmDivide;  //0.2 - 0.5 seconds
	SetAlarm(0, secs);
}

sf::Vector2f Spider::GetPos()
{
	return pos;
}

void Spider::Pause()
{
	x = 0;
	y = 0;
	AlarmCancel(0);
}