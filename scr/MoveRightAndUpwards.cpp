#include "MoveRightAndUpwards.h"
#include <iostream>
#include "MoveFSM.h"
#include "TurnDownSwitchToLeft.h"
#include "TurnUpSwitchToLeft.h"
#include "Poisoned_TurnSwitchLeft.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include <assert.h>

MoveRightAndUpwards::MoveRightAndUpwards()
{
	std::cout << "Initializing MoveRightAndUpwards state\n";

	MyMoveOffsets = &MovementCollection::OffsetsStraightRight;
}
void MoveRightAndUpwards::Show() const
{
	std::cout << "MoveRightAndUpwards";
}
const MoveState* MoveRightAndUpwards::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->GetRow() + 1;
	int col = chead->GetCol(); // looking ahead while right
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	if (obst == MushroomField::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (chead->GetZone() == false)
		{
			if (col == MushroomField::TOP_PLAYER_ROW)
				pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
			else
				pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		}
		else
		{
			if (col == 1)
				pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
			else
				pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		}
	}
	else // poison
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchLeft; //Should not happen on the bottom Row
	}

	return pNextState;
}