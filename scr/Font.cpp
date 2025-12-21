
#include "Font.h"
#include "Game Components/TEAL/CommonElements.h"

Font::Font()
	: SpriteSheet(ResourceManager::GetTexture("Keys"), 16, 3)
{
}

// Computing the magic value of the cellIndex for each char
int Font::CharToIndex(char& c)
{
	int cellIndex = 0;

	// This converts any lowercase key into an uppercase key
	if (c >= 'a' && c <= 'z')
		c -= 32;

	// Now selects which symbol to use
	if (c >= 'A' && c <= 'Z')
		cellIndex = (int)c - (int)'A' + 17;
	else if (c >= '0' && c <= '9')
		cellIndex = (int)c - (int)'0';
	else if (c == ' ')
		cellIndex = 13;
	else if (c == '{')
	{
		cellIndex = 43;
	}
	else if (c == '*')
	{
		cellIndex = 44;
	}
	else
		cellIndex = 10;  // This branch is the default symbol when all else fails. Set to space for now
	return cellIndex;
}