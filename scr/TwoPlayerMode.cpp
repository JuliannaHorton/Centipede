// FirstScene
// Andre Berthiaume, March 2013

#include "TwoPlayerMode.h"

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
#include "ScoreAccessor.h"
#include "SoundAccessor.h"
#include "Letter.h"
#include "HighScoreManager.h"

#include "KeyboardControl.h"



void TwoPlayerMode::Initialize()
{
	WindowManager::SetBackgroundColor(sf::Color(0, 0, 64, 255));
	ScoreAccessor::Initialize();
	SoundAccessor::Initialize();
	SoundAccessor::Mute();

	PlayerManager::SetPlayer(1);
	GameController::SetMode(2);
	MushroomField::GenerateField();

	WindowManager::SetBackgroundColor(sf::Color::Black);

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

void TwoPlayerMode::Terminate()
{
	BulletFactory::Terminate();
	SpiderFactory::Terminate();
	GameController::Terminate();
	PlayerFactory::Terminate();
	PlayerManager::Terminate();
	ScoreAccessor::Terminate();
	SoundAccessor::Terminate();

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