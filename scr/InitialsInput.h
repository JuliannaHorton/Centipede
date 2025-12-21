#ifndef _InitialsInput
#define _InitialsInput

#include "Game Components/TEAL/CommonElements.h"

class SpriteString;
class HighScoreManager;

class InitialsInput : public GameObject
{
public:
	InitialsInput() = delete;
	InitialsInput(const InitialsInput&) = delete;
	InitialsInput& operator=(const InitialsInput&) = delete;
	~InitialsInput() = default;

	InitialsInput(HighScoreManager* referenceBack);

	virtual void TextEntered(sf::Uint32 UnicodeValue);
	virtual void Destroy();

private:
	HighScoreManager* Reference;
	SpriteString* myInitials;
	SpriteString* Label;

	std::string Initials;
	sf::Vector2f InitialsPos;

};

#endif _InitialsInput