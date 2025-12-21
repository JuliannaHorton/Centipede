#include "SpriteString.h"
#include "MushroomField.h"
#include "Letter.h"

SpriteString::SpriteString(std::string text, sf::Vector2f pos)
{
	myText = text;
	myPos = pos; //The saved position
	NextPos = pos;  //The position it iterates through

	for (size_t i = 0; i < text.length(); i++)
	{
		mySymbols.push_back(myFont.GetGlyph(myText.at(i), NextPos));

		// we must update the next position ourselves
		if (myText[i] != ' ')
		{
			MushroomField::AddtoGrid(new Letter(NextPos)); //For some reason this skrews up my grid for the last row
			LetterPos.push_back(NextPos);
		}
		NextPos.x += myFont.CellWidth();
	}
}

void SpriteString::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = mySymbols.begin(); it != mySymbols.end(); it++)
		it->Draw();
}

void SpriteString::SetText(std::string text)
{
	size_t count = 0;
	if (text.length() > myText.length()) count = text.length() - myText.length();

	myText = text;
	NextPos = myPos;

	for (size_t i = 0; i < myText.length(); i++) //Iterates through the string
	{
		mySymbols.push_back(myFont.GetGlyph(myText.at(i), NextPos)); //Adds it to the glyphs

		NextPos.x += myFont.CellWidth();
	}
}

void SpriteString::Backspace()
{
	if (myText.length() > 0) //Checks that mytext can remove a char
	{
		myText.pop_back(); //Removes the last char
		std::string ghostText = myText;
		ghostText += "*"; //Covers up the original drawing

		NextPos = myPos;
		for (size_t i = 0; i < ghostText.length(); i++)
		{
			mySymbols.push_back(myFont.GetGlyph(ghostText.at(i), NextPos));

			NextPos.x += myFont.CellWidth();
		}
	}
}

void SpriteString::pushBackPos() //Pushes the string back a cell
{
	myPos.x -= Size;
}

int SpriteString::getStringLength()
{
	return myText.length();
}

void SpriteString::Delete()
{
	while (!LetterPos.empty())
	{
		MushroomField::removeShroomPos(LetterPos.back());
		LetterPos.pop_back();
	}
	MarkForDestroy();
}