// Centipede Animation

#ifndef _Explode
#define _Explode

#include "Game Components/TEAL/CommonElements.h"

class Explode : public GameObject
{
public:
	Explode();
	Explode(const Explode&) = delete;
	Explode& operator=(const Explode&) = delete;
	~Explode() = default;

	virtual void Update();
	virtual void Draw();

	void Initialize(sf::Vector2f _Pos);

private:
	AnimatedSprite MainSprite;

	sf::Vector2f Pos;
};


#endif _Explosion