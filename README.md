# **Introduction**
Recreating Centipede served as an excercise to practice application of Object Oriented Programming, as it utilizes inheritance, abstraction, and encapsulation across many classes and objects. In this Description I plan to go over attributes of my Centipede program as well as the many ways I used design patterns to increase effciency.

# Design Patterns Used
Singletons - Used across multiple systems including Mushroom Manager, Factories, and Score

Simple Factories - Used to manage the production of characters and objects

Strategy Pattern - Used to manage game modes and sound settings (mute and not mute)

Finite State Machine - Used to control the Centipede movements

Command Pattern - Used to manage Score and Sound systems

Flyweight Pattern - Used to manage and access the font 

## Factories
### Bullet Example
In Centipede the player can shoot bullets over and over again, meaning the object will need to be created over and over again. Instead to make this system more effcient and maintainable I used the factory method to recycle already created bullets. Below I have the BulletPool and Bulletfactory classes. The Bulletpool pushes used bullets that have been destroyed onto a stack, returns them when a bullet needs to be created again, and then pushes them out and deletes them when the class destructor is called. The BulletFactory class is a singleton that creates a new BulletPool and calls it whenever it's create and recycle methods are called. 

*BulletFactory.cpp*

```C++
void BulletFactory::privCreateBullet(sf::Vector2f pos, MyPlayer* Blaster)
{
	Bullet* b = myBulletPool.GetBullet();


	// Declares that this object should be returned here (rather than deleted) when destroyed
	b->SetExternalManagement(RecycleBullet);

	b->Initialize(pos, Blaster);
}

void BulletFactory::privRecycleBullet(GameObject* b)
{
	myBulletPool.ReturnBullet(static_cast<Bullet*>(b));
}


void BulletFactory::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
```
*BulletPool.cpp*

```C++
BulletPool::~BulletPool()
{
	// forcefully delele all recycled gameobjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}

Bullet* BulletPool::GetBullet()
{
	Bullet* b;

	if (recycledItems.empty())
	{
		b = new Bullet();
	}
	else
	{
		ConsoleMsg::WriteLine("Recycled Bullet"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

		// Tell the object to register itself to the scene
		b->RegisterToCurrentScene();
	}

	return b;
}

void BulletPool::ReturnBullet(Bullet* b)
{
	recycledItems.push(static_cast<Bullet*>(b));
}
```

## Strategy Pattern

### Player Control Example
The player character switches between two different control systems for its movement in Centipede: Keyboard mode and attractor mode (AI mode). To prevent a constant if statement checking what mode the player is in I created a class called StrategyInterface with two child classes called KeyboardControl and AI control. When a new player is created a new child of the StrategyInterface is also created and assigned to the player. This way it movement is dependent on what mode it is in, rather than an if statemnt. 

**With if statement**

Nice and simple. The player accesses a virtual method each frame that will cause the player to move depending on what it's control mode is
```C++
void MyPlayer::Update() //Updates 60 frames per a second
{
	player->ExecuteInput(this); //Accesses either the KeyboardControl or AIControl
  
	Blaster.setPosition(Pos);
}

*StrategyInterface.h

```

**Without if statement**

Calls an uneeded if statement each frame and looks overly complicated

```C++
void MyPlayer::Update()
{
  if (KeyboardMode == True)
  	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  	{
  		player->MoveLeft();
  	}
  	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  	{
  		player->MoveRight();
  	}
  	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  	{
  		player->MoveUp();
  	}
  	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  	{
  		player->MoveDown();
  	}
  else
  {
    	if (x == 0) blaster->MoveLeft(); //Left/Right

	    if (x == 1) blaster->MoveRight(); //Left/Right

	    if (y == 0) blaster->MoveUp(); //Down

	    if (y == 1) blaster->MoveDown(); //Up
  }

	Blaster.setPosition(Pos);
}

void MyPlayer::Alarm4()
{
	x = (rand() % 3); //1 = left/right, 0 = nothing
	y = (rand() % 3); //0 = down, 1 = up

	float secs = (float)(2 + (rand() % 3)) / 10;  //0.2 - 0.5 seconds
	SetAlarm(4, secs);
}
```
