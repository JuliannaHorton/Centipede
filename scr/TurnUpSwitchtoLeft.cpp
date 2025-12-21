#include "TurnUpSwitchToLeft.h"
#include <iostream>
#include "MoveFSM.h"
#include "TurnDownSwitchToRight.h"
#include "MoveLeftAndUpwards.h"
#include "Poisoned_TurnSwitchRight.h"
#include "TurnUpSwitchToRight.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include <assert.h>

TurnUpSwitchToLeft::TurnUpSwitchToLeft()
{
	std::cout << "Initializing TurnUpSwitchToLeft state\n";

	MyMoveOffsets = &MovementCollection::OffsetsTurnUpEndLeft;
}
void TurnUpSwitchToLeft::Show() const
{
	std::cout << "TurnUpSwitchToLeft";
}
const MoveState* TurnUpSwitchToLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->GetRow() - 2;
	int col = chead->GetCol(); // looking ahead after turn -> left
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	if (obst == MushroomField::Obstacle::Clear)
	{
		obst = MushroomField::Inspect(row + 1, col);
	}

	if (obst == MushroomField::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndUpwards;
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (chead->GetZone() == false)
		{
			if (col == MushroomField::TOP_PLAYER_ROW)
				pNextState = &MoveFSM::StateTurnUpSwitchToRight;
			else
				pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		}
		else
		{
			if (col == 1)
				pNextState = &MoveFSM::StateTurnUpSwitchToRight;
			else
				pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		}

	}
	else // poison
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchRight;
	}

	chead->ChangeSpriteDirection();

	return pNextState;
}