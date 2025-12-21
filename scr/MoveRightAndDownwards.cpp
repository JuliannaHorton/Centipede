#include "MoveRightAndDownwards.h"
#include <iostream>
#include "MoveFSM.h"
#include "TurnDownSwitchToLeft.h"
#include "TurnUpSwitchToLeft.h"
#include "Poisoned_TurnSwitchLeft.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include "GameController.h"
#include <assert.h>

MoveRightAndDownwards::MoveRightAndDownwards()
{
	std::cout << "Initializing MoveRightAndDownwards state\n";

	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
}
void MoveRightAndDownwards::Show() const
{
	std::cout << "MoveRightAndDownwards";
}
const MoveState* MoveRightAndDownwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->GetRow() + 1;
	int col = chead->GetCol(); // looking ahead while right
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	//if (obst == MushroomField::Obstacle::Clear)
	//{
	//	obst = MushroomField::Inspect(row-1, col);
	//}

	if (obst == MushroomField::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (col == MushroomField::BOTTOM_ROW)
		{
			GameController::BottomHit();
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		}
		else
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	else // poison
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchLeft;
	}

	return pNextState;
}