#ifndef _Font
#define _Font

#include "SpriteSheet.h"

class Font : public SpriteSheet
{
public:
	Font();

	Font(const Font&) = delete;
	Font& operator=(const Font&) = delete;
	virtual ~Font() = default;

private:
	virtual int CharToIndex(char& c);
};


#endif _Font