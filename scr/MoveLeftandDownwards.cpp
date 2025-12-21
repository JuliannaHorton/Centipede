#include "MoveLeftAndDownwards.h"
#include <iostream>
#include "MoveFSM.h"
#include "TurnDownSwitchToRight.h"
#include "TurnUpSwitchToRight.h"
#include "Poisoned_TurnSwitchRight.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include "GameController.h"
#include <assert.h>

MoveLeftAndDownwards::MoveLeftAndDownwards()
{
	std::cout << "Initializing MoveLeftAndDownwards state\n";

	MyMoveOffsets = &MovementCollection::OffsetsStraightLeft;
}
void MoveLeftAndDownwards::Show() const
{
	std::cout << "MoveLeftAndDownwards";
}

const MoveState* MoveLeftAndDownwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->GetRow() - 2;
	int col = chead->GetCol(); // looking ahead while left
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	//if (obst == MushroomField::Obstacle::Clear)
	//{
	//	row = chead->GetRow();
	//	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);
	//}


	if (obst == MushroomField::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (col == MushroomField::BOTTOM_ROW)
		{
			GameController::BottomHit();
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		}
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}
	else // poison
	{
		// Not implemented
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchRight;
	}

	return pNextState;
}
