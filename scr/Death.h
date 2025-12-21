
// Death Animation

#ifndef _Death
#define _Death

#include "Game Components/TEAL/CommonElements.h"

class MyPlayer;

class Death : public GameObject
{
public:
	Death();
	Death(const Death&) = delete;
	Death& operator=(const Death&) = delete;
	~Death() = default;

	virtual void Update();
	virtual void Draw();

	void Initialize(sf::Vector2f _Pos);

private:
	AnimatedSprite MainSprite;

	sf::Vector2f Pos;
};


#endif _Explosion