#include "TurnUpSwitchToRight.h"
#include <iostream>
#include "MoveFSM.h"
#include "MoveRightAndUpwards.h"
#include "TurnDownSwitchToLeft.h"
#include "TurnUpSwitchToLeft.h"
#include "Poisoned_TurnSwitchLeft.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include <assert.h>

TurnUpSwitchToRight::TurnUpSwitchToRight()
{
	std::cout << "Initializing TurnUpSwitchToRight state\n";

	MyMoveOffsets = &MovementCollection::OffsetsTurnUpEndRight;
}
void TurnUpSwitchToRight::Show() const
{
	std::cout << "TurnUpSwitchToRight";
}
const MoveState* TurnUpSwitchToRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->GetRow() + 1;
	int col = chead->GetCol(); // looking ahead after turn -> Right
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	if (obst == MushroomField::Obstacle::Clear)
	{
		obst = MushroomField::Inspect(row - 1, col);
	}

	if (obst == MushroomField::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndUpwards;
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (chead->GetZone() == false)
		{
			if (col == MushroomField::TOP_PLAYER_ROW)
				pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
			else
				pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		}
		else
		{
			if (col == 1)
				pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
			else
				pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		}
	}
	else // poison
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchLeft;
	}

	chead->ChangeSpriteDirection();

	return pNextState;
}
