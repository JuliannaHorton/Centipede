#ifndef _Letter
#define _Letter

#include "Cell.h"

class Letter : public  Cell
{
public:
	Letter() = default;
	Letter(const Letter&) = delete;
	Letter& operator=(const Letter&) = delete;
	~Letter() = default;

	Letter(sf::Vector2f p);
	sf::Vector2f GetPos() override;

	bool amIShroom() override; //I use this to check whether its a Letter of Shroom

private:
	sf::Vector2f Pos;
};

#endif _Letter
