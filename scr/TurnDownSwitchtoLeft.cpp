#include "TurnDownSwitchToLeft.h"
#include <iostream>
#include "MoveFSM.h"
#include "MoveLeftAndDownwards.h"
#include "TurnDownSwitchToRight.h"
#include "TurnUpSwitchToRight.h"
#include "Poisoned_TurnSwitchRight.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include "GameController.h"
#include <assert.h>

TurnDownSwitchToLeft::TurnDownSwitchToLeft()
{
	std::cout << "Initializing TurnDownSwitchToLeft state\n";

	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndLeft;
}
void TurnDownSwitchToLeft::Show() const
{
	std::cout << "TurnDownSwitchToLeft";
}
const MoveState* TurnDownSwitchToLeft::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	//switch row and column later *face slap*
	int row = chead->GetRow() - 2;
	int col = chead->GetCol(); // looking ahead after turn ->left
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	if (obst == MushroomField::Obstacle::Clear)
	{
		obst = MushroomField::Inspect(row + 1, col);
	}

	if (obst == MushroomField::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveLeftAndDownwards;
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (col != MushroomField::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToRight;
		else
		{
			GameController::BottomHit();
			pNextState = &MoveFSM::StateTurnUpSwitchToRight;
		}
	}
	else 
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchRight;
	}

	chead->ChangeSpriteDirection();

	return pNextState;
}