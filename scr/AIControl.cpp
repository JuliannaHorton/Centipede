#include "AIControl.h"
#include "MyPlayer.h"
#include "PlayerManager.h" //Testing delete later
#include "GameController.h"
#include "DefaultScene.h"
#include "TwoPlayerMode.h"

AIControl::AIControl()
{
	float secs = (float)(2 + (rand() % 3)) / 10;  //0.2 - 0.5 seconds
	SetAlarm(4, secs);

	GameObject::RegisterInput(InputFlags::KeyPressed);
}

void AIControl::Alarm4()
{
	x = (rand() % 3); //1 = left/right, 0 = nothing
	y = (rand() % 3); //0 = down, 1 = up

	float secs = (float)(2 + (rand() % 3)) / 10;  //0.2 - 0.5 seconds
	SetAlarm(4, secs);
}

void AIControl::ExecuteInput(MyPlayer* blaster)
{
	if (x == 0) blaster->MoveLeft(); //Left/Right

	if (x == 1) blaster->MoveRight(); //Left/Right

	if (y == 0) blaster->MoveUp(); //Down

	if (y == 1) blaster->MoveDown(); //Up

	blaster->Fire();
}



void AIControl::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		PlayerManager::ClearFields();
		SceneManager::ChangeScene(new DefaultScene);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		PlayerManager::ClearFields();
		SceneManager::ChangeScene(new TwoPlayerMode);
	}
}