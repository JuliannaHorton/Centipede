
#ifndef _MyPlayer
#define _MyPlayer

#include "Game Components/TEAL/CommonElements.h"

class Spider;
class CentipedeHead;
class CentipedeSegment;
class Flea;
class Bullet;
class StrategyInterface;
class SoundPlay;

class MyPlayer : public GameObject
{
public:
	MyPlayer();
	MyPlayer(const MyPlayer&) = delete;
	MyPlayer& operator=(const MyPlayer&) = delete;
	~MyPlayer() = default;

	virtual void Update();
	virtual void Draw();

	//Collision methods and destroy
	virtual void Collision(Spider* go);
	virtual void Collision(CentipedeHead* go);
	virtual void Collision(CentipedeSegment* go);
	virtual void Collision(Flea* go);
	virtual void Collision(GameObject* go) {};
	virtual void Destroy();

	//Methods for Strategy Pattern
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Fire();

	void Reload(); //Called by the Bullet when its destroyed, to turn the value BulletOn to false

	virtual MyPlayer* GetPlayer() { return this; }

	void Initialize(StrategyInterface* _Pattern);

	sf::Vector2f GetPos();

private:
	AnimatedSprite Blaster;
	StrategyInterface* Pattern = nullptr; //Reference to its strategy pattern
	SoundPlay* FireSound;
	SoundPlay* DeathSound;

	sf::Vector2f Pos;

	float SPEED;

	//Constants for the blaster sizes and 
	const int Size = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2).getTextureRect().width; //Size 16
	const int HalfBlaster = AnimatedSprite(ResourceManager::GetTexture("Blaster"), 4, 2).getTextureRect().width / 2;
	const float WindowY = WindowManager::Window().getView().getSize().y;
	const float WindowX = WindowManager::Window().getView().getSize().x;

	bool bulletOn; //Checks if a bullet is active
};

#endif _MyPlayer