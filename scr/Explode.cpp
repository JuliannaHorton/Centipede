// Spawn Animation

#include "Explode.h"

Explode::Explode()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Spawn"), 3, 2, 100);
	MainSprite.SetAnimation(0, 5);
	MainSprite.scale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);
}

void Explode::Update()
{
	if (MainSprite.IsLastAnimationFrame())
		MarkForDestroy();  //Animation gets deleted

	MainSprite.Update();
}

void Explode::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Explode::Initialize(sf::Vector2f _Pos)
{
	Pos = _Pos;


	MainSprite.SetFrame(0);
	MainSprite.setPosition(Pos);
}