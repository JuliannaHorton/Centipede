#ifndef _Bullet
#define _Bullet


#include "Game Components/TEAL/CommonElements.h"
#include "MyPlayer.h"

class Mushroom;
class CentipedeSegment;
class CentipedeHead;
class MyPlayer;
class Scorpion;
class Flea;
class Letter;

class Bullet : public GameObject
{
public:
	Bullet();
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;
	~Bullet() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision(GameObject* go) {};
	virtual void Collision(Mushroom* other);
	virtual void Collision(CentipedeSegment* other);
	virtual void Collision(CentipedeHead* other);
	virtual void Collision(Scorpion* other);
	virtual void Collision(Flea* other);
	virtual void Collision(Letter* other);

	void Initialize(sf::Vector2f p, MyPlayer* blaster);

private:
	MyPlayer* Blaster = nullptr;
	AnimatedSprite MainSprite;

	sf::Vector2f Pos;
	float SPEED;
};

#endif _Bullet