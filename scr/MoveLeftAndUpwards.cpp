#include "MoveLeftAndUpwards.h"
#include <iostream>
#include "MoveFSM.h"
#include "TurnDownSwitchToRight.h"
#include "TurnUpSwitchToRight.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include "Poisoned_TurnSwitchRight.h"
#include <assert.h>

MoveLeftAndUpwards::MoveLeftAndUpwards()
{
	std::cout << "Initializing MoveLeftAndUpwards state\n";

	MyMoveOffsets = &MovementCollection::OffsetsStraightLeft;
}
void MoveLeftAndUpwards::Show() const
{
	std::cout << "MoveLeftAndUpwards";
}
const MoveState* MoveLeftAndUpwards::GetNextState(CentipedeHead* chead) const
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
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (chead->GetZone() == false)
		{
			if (col == MushroomField::TOP_PLAYER_ROW)
				pNextState = &MoveFSM::StateTurnDownSwitchToRight;
			else
				pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		}
		else
		{
			if (col == 1)
				pNextState = &MoveFSM::StateTurnDownSwitchToRight;
			else
				pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		}
	}
	else // poison
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchRight; //Shouldn't happen on the bottom Row
	}

	return pNextState;
}