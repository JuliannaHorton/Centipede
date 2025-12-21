// FirstScene
// Andre Berthiaume, March 2013

#include "DefaultScene.h"

#include "MushroomField.h"
#include "MyPlayer.h"
#include "Mushroom.h"
#include "Bullet.h"
#include "Scorpion.h"
#include "Spider.h"
#include "CritterSpawner.h"
#include "BulletFactory.h"
#include "BulletPool.h"
#include "CentipedeHead.h"
#include "CentipedeHeadFactory.h"
#include "CentipedeSegmentFactory.h"
#include "Flea.h"
#include "FleaFactory.h"
#include "SpiderFactory.h"
#include "ScorpionFactory.h"
#include "DeathFactory.h"
#include "ExplodeFactory.h"
#include "SpiderScoresFactory.h"
#include "CentipedeSegment.h"
#include "PlayerFactory.h"
#include "HUDAccess.h"
#include "GameController.h"
#include "PlayerManager.h"
#include "ScoreManager.h"
#include "Letter.h"
#include "ScoreAccessor.h"
#include "SoundAccessor.h"
#include "HighScoreManager.h"

#include "KeyboardControl.h"



void DefaultScene::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 64, 255));
	ScoreAccessor::Initialize();
	SoundAccessor::Initialize();

	MushroomField::GenerateField();
	SoundAccessor::Mute(); //turns off mute
	PlayerManager::SetPlayer(1);

	WindowManager::SetBackgroundColor(sf::Color::Black);

	GameController::SetMode(1);
	GameController::GameOn();
	HUDAccess::Initialize();


	CollisionTestPair<Mushroom, Bullet>();
	CollisionTestPair<Spider, Bullet>();
	CollisionTestPair<Scorpion, Bullet>();
	CollisionTestPair<Scorpion, Mushroom>();
	CollisionTestPair<Spider, Mushroom>();
	CollisionTestPair<Spider, MyPlayer>();
	CollisionTestPair<CentipedeHead, MyPlayer>();
	CollisionTestPair<CentipedeSegment, MyPlayer>();
	CollisionTestPair<Flea, MyPlayer>();
	CollisionTestPair<CentipedeHead, Bullet>();
	CollisionTestPair<Flea, Bullet>();
	CollisionTestPair<CentipedeSegment, Bullet>();
	CollisionTestPair<Letter, Bullet>();
}

void DefaultScene::Terminate()
{
	ScoreAccessor::Terminate();
	SoundAccessor::Terminate();
	BulletFactory::Terminate();
	SpiderFactory::Terminate();
	GameController::Terminate();
	PlayerFactory::Terminate();
	PlayerManager::Terminate();

	CentipedeHeadFactory::Terminate();
	CentipedeSegmentFactory::Terminate();
	FleaFactory::Terminate();
	ScorpionFactory::Terminate();
	DeathFactory::Terminate();
	ExplodeFactory::Terminate();
	SpiderScoresFactory::Terminate();
	HUDAccess::Terminate();
	MushroomField::Terminate();
	HighScoreManager::Terminate();
}