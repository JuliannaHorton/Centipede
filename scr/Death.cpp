// Death Animation

#include "Death.h"
#include "GameController.h"
#include "MyPlayer.h"

Death::Death()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Death"), 8, 2, 19);
	MainSprite.SetAnimation(0, 19);
	MainSprite.scale(1, 1);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);
}

void Death::Update()
{
	if (MainSprite.IsLastAnimationFrame())
	{
		GameController::PlayerDied(); //Tells the GameController that the explosion has ended and the next wave can start
		MarkForDestroy(); //Animation gets deleted
	}

	MainSprite.Update();
}

void Death::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Death::Initialize(sf::Vector2f _Pos)
{
	Pos = _Pos;
	MainSprite.SetFrame(0);
	MainSprite.setPosition(Pos);
}