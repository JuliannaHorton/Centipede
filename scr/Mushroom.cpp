
#include "Mushroom.h"
#include "MushroomField.h"

#include "ScoreAccessor.h"

Mushroom::Mushroom() : Health(0), Poison(false)
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2, 1, 0, 5);
	MainSprite.SetAnimation(0, 3);
	MainSprite.setOrigin(1.0f, 1.0f);

	mDeath = ScoreAccessor::GetScoreCommand(ScoreAccessor::myScoreEvents::MushroomKilled);

	CollisionTools::TextureBitmap& bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	SetCollider(MainSprite, bitmap);
	RegisterCollision<Mushroom>(*this);
}

void Mushroom::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void Mushroom::Collision(Bullet* other)
{
	Health++; 
	if (Health == MaxHealth) //Checks if the health has reached 4 
	{
		ScoreAccessor::SendScoreCmd(mDeath);

		MushroomField::removeShroomPos(Pos);
		MarkForDestroy();
	}
	else MainSprite.NextFrame(); //Moves to next frame
}

void Mushroom::Collision(Scorpion* other)
{
	Poison = true;
	MainSprite.SetFrame(MaxHealth + Health); //Sets the frames to poisoned
    MainSprite.SetAnimation(MaxHealth + Health, 7);
	MainSprite.Update();
}

void Mushroom::Collision(Spider* other)
{
	MushroomField::removeShroomPos(Pos);
	MarkForDestroy();
}


void Mushroom::Destroy()
{
	Pos = sf::Vector2f(2000, 2000);
	MainSprite.setPosition(Pos);

	DeregisterCollision<Mushroom>(*this);
}

void Mushroom::Initialize(sf::Vector2f p)
{
	Health = 0;
	Poison = false;
	MainSprite.SetFrame(0);
	MainSprite.SetAnimation(0, 3);
	Pos = p;
	MainSprite.setPosition(Pos);
	RegisterCollision<Mushroom>(*this);
}

bool Mushroom::GetPoison()
{
	return Poison;
}

sf::Vector2f Mushroom::GetPos()
{
	return Pos;
}

void Mushroom::Heal() //Resets the mushrooms health and frames
{
    Health = 0;
	Poison = false;
	MainSprite.SetFrame(0);
	MainSprite.SetAnimation(0, 3);
	MainSprite.Update();
}

bool Mushroom::lifeAlert() //Returns whether the mushroom is hurt or poisoned
{
	if (Poison == true || Health != 0)
	{
		return true;
	}
	return false;
}

bool Mushroom::amIShroom()
{
	return true;
}
