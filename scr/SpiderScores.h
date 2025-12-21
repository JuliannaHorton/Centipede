// Centipede Animation

#ifndef _SpiderScores
#define _SpiderScores

#include "Game Components/TEAL/CommonElements.h"

class SpiderScores : public GameObject
{
public:
	SpiderScores();
	SpiderScores(const SpiderScores&) = delete;
	SpiderScores& operator=(const SpiderScores&) = delete;
	~SpiderScores() = default;

	virtual void Draw();
	virtual void Alarm0();

	void Initialize(sf::Vector2f _Pos, int _Score);

private:
	AnimatedSprite MainSprite;

	sf::Vector2f Pos;
};


#endif _SpiderScores