#include "Poisoned_TurnSwitchRight.h"
#include <iostream>
#include "MoveFSM.h"
#include "Poisoned_TurnSwitchLeft.h"
#include "TurnDownSwitchToLeft.h"
#include "MoveRightAndUpwards.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include <assert.h>

Poisoned_TurnSwitchRight::Poisoned_TurnSwitchRight()
{
	std::cout << "Initializing Poisoned_TurnSwitchLeft state\n";

	MyMoveOffsets = &MovementCollection::OffsetsPoisonedTurnDownEndRight;
}
void Poisoned_TurnSwitchRight::Show() const
{
	std::cout << "Poisoned_TurnSwitchLeft";
}
const MoveState* Poisoned_TurnSwitchRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->GetRow();
	int col = chead->GetCol() - 1; // looking ahead after turn -> left
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	if (obst == MushroomField::Obstacle::Clear)
	{
		if (col == MushroomField::BOTTOM_ROW)
		{
			pNextState = &MoveFSM::StateMoveRightAndUpwards;
			if (chead->GetDirection() != -2) chead->ChangeSpriteDirection();
		}
		else
		{
			pNextState = &MoveFSM::StatePoisoned_TurnSwitchLeft;
			chead->ChangeSpriteDirection();
		}
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
	}
	else // poison
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchLeft;
	}

	return pNextState;
}