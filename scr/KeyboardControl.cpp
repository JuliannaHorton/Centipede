#include "KeyboardControl.h"
#include "PlayerManager.h"
#include "MyPlayer.h"
#include "SoundAccessor.h"
#include "Game Components/FirstScene.h"

KeyboardControl::KeyboardControl()
{
	GameObject::RegisterInput(InputFlags::KeyPressed);
}

void KeyboardControl::ExecuteInput(MyPlayer* blaster)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		blaster->MoveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		blaster->MoveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		blaster->MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		blaster->MoveDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		blaster->Fire();
	}
}

void KeyboardControl::KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		PlayerManager::ClearFields();
		PlayerManager::Reset();
		SceneManager::ChangeScene(new FirstScene);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		SoundAccessor::Mute();
	}
}