#pragma once

#ifndef _SpriteString
#define _SpriteString

#include "Game Components/TEAL/CommonElements.h"
#include "Font.h"
#include <list>

class  SpriteString : public  GameObject
{
public:
	SpriteString() = delete;
	SpriteString(const SpriteString&) = delete;
	SpriteString& operator=(const SpriteString&) = delete;
	~SpriteString() = default;

	SpriteString(std::string text, sf::Vector2f pos);

	virtual void Draw();

	void SetText(std::string); //For Adding new text

	void Backspace(); //Basically just removes the last char

	void pushBackPos();

	int getStringLength();

	void Delete();


private:
	Font myFont;

	std::string myText;
	sf::Vector2f myPos;
	sf::Vector2f NextPos;
	std::list<Glyph> mySymbols;

	std::list<sf::Vector2f> LetterPos;

	const int Size = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2).getTextureRect().width;
};

#endif _KeyboardControl
