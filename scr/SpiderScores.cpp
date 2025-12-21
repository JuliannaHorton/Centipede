// Spawn Animation

#include "SpiderScores.h"

SpiderScores::SpiderScores()
{
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Scores"), 1, 3, 1, 0, 3);

	MainSprite.scale(2, 2);
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);
}

void SpiderScores::Alarm0()
{
	MarkForDestroy(); //Animation gets deleted
}

void SpiderScores::Draw()
{
	WindowManager::Window().draw(MainSprite);
}

void SpiderScores::Initialize(sf::Vector2f _Pos, int Score)
{
	Pos = _Pos;
	MainSprite.SetFrame(0);

	if (Score == 600)
	{
		MainSprite.NextFrame();
		MainSprite.Update();
	}
	else if (Score == 900)
	{
		MainSprite.NextFrame();
		MainSprite.NextFrame();
		MainSprite.Update();
	}

	MainSprite.setPosition(Pos);

	SetAlarm(0, 0.5);
}