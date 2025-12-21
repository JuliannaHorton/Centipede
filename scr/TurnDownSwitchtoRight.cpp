#include "TurnDownSwitchToRight.h"
#include <iostream>
#include "MoveFSM.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include "MushroomField.h"
#include <assert.h>
#include "MoveState.h"
#include "MoveRightAndDownwards.h"
#include "TurnDownSwitchToLeft.h"
#include "Poisoned_TurnSwitchLeft.h"
#include "TurnUpSwitchToLeft.h"
#include "GameController.h"

// TurnDownSwitchToRight
TurnDownSwitchToRight::TurnDownSwitchToRight()
{
	std::cout << "Initializing TurnDownSwitchToRight state\n";

	MyMoveOffsets = &MovementCollection::OffsetsTurnDownEndRight;
}
void TurnDownSwitchToRight::Show() const
{
	std::cout << "TurnDownSwitchToRight";
}
const MoveState* TurnDownSwitchToRight::GetNextState(CentipedeHead* chead) const
{
	const MoveState* pNextState;

	int row = chead->GetRow() + 1; //Lookin in front
	int col = chead->GetCol(); // looking ahead after turn -> right
	MushroomField::Obstacle obst = MushroomField::Inspect(row, col);

	if (obst == MushroomField::Obstacle::Clear)
	{
		obst = MushroomField::Inspect(row-1, col);
	}

	if (obst == MushroomField::Obstacle::Clear)
	{
		pNextState = &MoveFSM::StateMoveRightAndDownwards;
	}
	else if (obst == MushroomField::Obstacle::Blocked) // Edge, shroom or letter?
	{
		if (col != MushroomField::BOTTOM_ROW)
			pNextState = &MoveFSM::StateTurnDownSwitchToLeft;
		else
		{
			GameController::BottomHit();
			pNextState = &MoveFSM::StateTurnUpSwitchToLeft;
		}
	}
	else // poison
	{
		pNextState = &MoveFSM::StatePoisoned_TurnSwitchLeft;
	}

	chead->ChangeSpriteDirection();

	return pNextState;
}