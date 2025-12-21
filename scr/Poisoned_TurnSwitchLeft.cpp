#include "Poisoned_TurnSwitchLeft.h"
#include <iostream>
#include "MoveFSM.h"
#include "Poisoned_TurnSwitchRight.h"
#include "TurnDownSwitchToRight.h"
#include "MoveLeftAndUpwards.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include <assert.h>

Poisoned_TurnSwitchLeft::Poisoned_TurnSwitchLeft()
{
	std::cout << "Initializing Poisoned_TurnSwitchLeft state\n";

	MyMoveOffsets = &MovementCollection::OffsetsPoisonedTurnDownEndLeft;
}
void Poisoned_TurnSwitchLeft::Show() const
{
	std::cout << "Poisoned_TurnSwitchLeft";
}
const MoveState* Poisoned_TurnSwitchLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->GetRow();
	int col = chead->GetCol() - 1; // looking ahead after turn -> left
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	if (obst == MushroomField::Obstacle::Clear)
	{
		if (col == MushroomField::BOTTOM_ROW)
		{
			pNextState = &MoveFSM::StateMoveLeftAndUpwards;
			if (chead->GetDirection() != 2) chead->ChangeSpriteDirection();
		}
		else
		{
			pNextState = &MoveFSM::StatePoisoned_TurnSwitchRight;
			chead->ChangeSpriteDirection();
		}
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		pNextState = &MoveFSM::StateTurnDownSwitchToRight;
	}
	else // poison
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchRight;
	}

	return pNextState;
}