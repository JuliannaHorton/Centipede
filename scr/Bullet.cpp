
#include "Bullet.h"
#include "MyPlayer.h"
#include "MushroomField.h"

Bullet::Bullet() : SPEED(15)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Bullet"), 1, 1, 120);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Bullet");
	SetCollider(MainSprite, bitmap);
}

void Bullet::Update()
{
	Pos.y -= SPEED;

	//if the bullet moves outside the window it gets destroyed
	if (Pos.y <= 0) MarkForDestroy();

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Bullet::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Bullet::Destroy()
{
	Blaster->Reload(); //Tells the blaster that it's nolonger on screen
	DeregisterCollision<Bullet>(*this);
}

//Collision methods
void Bullet::Collision(Mushroom *other)
{
	MarkForDestroy();
}

void Bullet::Collision(CentipedeHead* other)
{
	MarkForDestroy();
}

void Bullet::Collision(CentipedeSegment* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Scorpion* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Flea* other)
{
	MarkForDestroy();
}

void Bullet::Collision(Letter* other)
{
	MarkForDestroy();
}

//Intialized when created in a factory
void Bullet::Initialize(sf::Vector2f p, MyPlayer* _Blaster)
{
	Pos = p;
	Blaster = _Blaster;
	RegisterCollision<Bullet>(*this);
}

