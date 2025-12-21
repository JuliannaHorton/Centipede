

#ifndef _HUD
#define _HUD

#include "Game Components/TEAL/CommonElements.h"
#include <list>
#include "Font.h"

class SpriteString;

class HUD : public GameObject
{
public:
	HUD();
	HUD(const HUD&) = delete;
	HUD& operator=(const HUD&) = delete;
	~HUD() = default;

	virtual void Alarm0();

	void ScoreUpdate(int v);	// Callback used when score changes
	void UpdateLife();
	void AttractorScreen();

	void PlayerSwitch();

	std::string addZeros(int originalScore);

private:

	SpriteString* PlayerOneScore;
	SpriteString* PlayerTwoScore;
	SpriteString* PlayerOneLife;
	SpriteString* PlayerTwoLife;
	SpriteString* HighScoreString;

	SpriteString* PlayerSwitchS;

	Font myFont;

	SpriteString* High;
	SpriteString* Top;
	SpriteString* Second;
	SpriteString* Third;
	SpriteString* Fourth;
	SpriteString* Fifth;
	SpriteString* Sixth;
	SpriteString* Seventh;
	SpriteString* Eighth;


	sf::Sound ScoreSnd;


	const float HalfWindow = (float)WindowManager::Window().getView().getSize().x / 2;
	const float Size = (float)AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2).getTextureRect().width; //Size 16
	const float HighScoreCenter = Size * 4; //Size 64, I just needed a value to center the highscore
};

#endif _HUD