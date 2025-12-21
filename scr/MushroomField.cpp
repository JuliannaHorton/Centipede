
#include "MushroomField.h"
#include "Mushroom.h"
#include "PlayerManager.h"
#include "ExplodeFactory.h"
#include "Cell.h"
#include <iostream>

MushroomField* MushroomField::ptrInstance = nullptr;
Cell* MushroomField::MushroomPosition[30][30];


void MushroomField::privCreateShroom(sf::Vector2f pos)
{
	Counter++;

	int X = (int)(pos.x / ShroomSize);
	int Y = (int)(pos.y / ShroomSize);
	pos.x = (float)(X * ShroomSize);
	pos.y = (float)(Y * ShroomSize);

	if (MushroomPosition[X][Y] == nullptr)
	{
		Mushroom* b = myMushroomPool.GetMushroom();

		b->SetExternalManagement(RecycleMushroom);
		b->Initialize(pos);

		MushroomPosition[X][Y] = b;
	}
}

void MushroomField::privRecycleShroom(GameObject* b)
{
	myMushroomPool.ReturnMushroom(static_cast<Mushroom*>(b));
}

void MushroomField::privRemoveShroomPos(sf::Vector2f pos) //Removes Mushroom Position
{
	int ShroomSize = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2).getTextureRect().width;
	MushroomPosition[(int)(pos.x)/ ShroomSize][(int)(pos.y)/ ShroomSize] = nullptr;

	Counter--;
}

sf::Vector2f MushroomField::privGetGridPos(sf::Vector2f pos)
{
	int X = (int)(pos.x / ShroomSize);
	int Y = (int)(pos.y / ShroomSize);
	return sf::Vector2f((float)X, (float)Y);
}

void MushroomField::privGenerateField()
{
	if (!PlayerManager::GetMushroom().empty()) //Creates Mushrooms based on a Player's MushroomField
	{

		std::list<sf::Vector2f> PlayerField = PlayerManager::GetMushroom();

		while (!PlayerField.empty())
		{
			sf::Vector2f b = PlayerField.back();

			CreateMushroom(b);
			PlayerField.pop_back();
		}
	}
	else //Creates mushrooms at a random position
	{
		X = (int)(WindowManager::Window().getView().getSize().x) / ShroomSize;
		Y = (int)((WindowManager::Window().getView().getSize().y) / ShroomSize);

		for (int i = 0; i < (shroomAmountMin + rand() % shroomAmountMax); i++)
		{
			float x = (float)(rand() % X);
			float y = (float)((QuarterShroom + (rand() % (Y - QuarterShroom)))); //min 4 max 26

			CreateMushroom(sf::Vector2f(x * ShroomSize, y * ShroomSize));
		}
		//CreateMushroom(sf::Vector2f((float)4 * ShroomSize, (float)7 * ShroomSize));

		//CreateMushroom(sf::Vector2f((float)7 * ShroomSize, (float)8 * ShroomSize));

		//CreateMushroom(sf::Vector2f((float)4 * ShroomSize, (float)11 * ShroomSize));

		//CreateMushroom(sf::Vector2f((float)6 * ShroomSize, (float)12 * ShroomSize));

		//CreateMushroom(sf::Vector2f((float)4 * ShroomSize, (float)15 * ShroomSize));

		//CreateMushroom(sf::Vector2f((float)5 * ShroomSize, (float)16 * ShroomSize));
	}
}

//Inspects whether there is a Mushroom, letter, or window in the way of the Centipede (or player)
MushroomField::Obstacle MushroomField::privInspect(int row, int col)
{
	int ans = 0;

	if (col == BOTTOM_ROW)
	{
		col--;
	}

	Mushroom* b = static_cast<Mushroom*>(MushroomPosition[row][col]);

	if (row >= (int)(WindowManager::Window().getSize().x / ShroomSize) || row <= -1 || col >= (int)(WindowManager::Window().getSize().x / ShroomSize) || col <= -1)
	{
		ans = 1;
	}
	else if (b != nullptr)
	{
		if (b->GetPoison() == true) ans = 2;

		else  ans = 1;
	}

	return (Obstacle)ans;
}

int MushroomField::privGetShroomNumbers()
{
	return Counter;
}

void MushroomField::privAddtoGrid(Cell* cell)
{
	sf::Vector2f Cellpos = cell->GetPos();

	X = (int)(Cellpos.x / ShroomSize);
	Y = (int)(Cellpos.y / ShroomSize);


	MushroomPosition[X][Y] = cell;
}

//Heals all mushrooms
void MushroomField::privHealAll()
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (MushroomPosition[i][j] != nullptr && MushroomPosition[i][j]->amIShroom() == true)
			{
				Mushroom* b = static_cast<Mushroom*>(MushroomPosition[i][j]); //This must be a Mushroom and not a letter
				if (b->lifeAlert())
				{
					ExplodeFactory::CreateExplode(sf::Vector2f(b->GetPos().x + 8, b->GetPos().y + 8));
					b->Heal(); 
				}
			}
		}
	}
}

void MushroomField::privSaveField() //Saves the feild to the current player and deletes it
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			Mushroom* b = static_cast<Mushroom*>(MushroomPosition[i][j]);
			if (b != nullptr && MushroomPosition[i][j]->GetPos().y != 0)
			{
				PlayerManager::AddToField(b->GetPos());
				privRemoveShroomPos(b->GetPos());
				b->MarkForDestroy();
			}
		}
	}
}

void MushroomField::Terminate()
{
	for (int i = 0; i < 30; i++) { //Cleans up all mushrooms in the grid
		for (int j = 0; j < 30; j++) {
			MushroomPosition[i][j] = nullptr;
		}
	}

	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}
