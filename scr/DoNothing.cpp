#include "DoNothing.h"
#include <iostream>
#include "MoveFSM.h"
#include "CentipedeHead.h"
#include "MovementCollection.h"
#include <assert.h>

DoNothing::DoNothing()
{
	std::cout << "Initializing MoveLeftAndDownwards state\n";

	MyMoveOffsets = &MovementCollection::OffsetsDoNothing;
}
void DoNothing::Show() const
{
	std::cout << "MoveLeftAndDownwards";
}

const MoveState* DoNothing::GetNextState(CentipedeHead* chead) const
{
	return &MoveFSM::StateDoNothing;
}
