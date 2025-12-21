#include "MoveFSM.h"
//#include "MoveState.h"
#include "MoveRightAndDownwards.h"
#include "TurnDownSwitchToRight.h"
#include "MoveRightAndUpwards.h"
#include "MoveLeftAndDownwards.h"
#include "MoveLeftAndUpwards.h"
#include "TurnDownSwitchToLeft.h"
#include "TurnUpSwitchToLeft.h"
#include "TurnUpSwitchToRight.h"

#include "Poisoned_TurnSwitchLeft.h"
#include "Poisoned_TurnSwitchRight.h"

#include "DoNothing.h"

// Set up all the unique copies of states
const MoveRightAndDownwards MoveFSM::StateMoveRightAndDownwards;
const MoveRightAndUpwards MoveFSM::StateMoveRightAndUpwards;
const MoveLeftAndDownwards MoveFSM::StateMoveLeftAndDownwards;
const MoveLeftAndUpwards MoveFSM::StateMoveLeftAndUpwards;
const TurnDownSwitchToLeft MoveFSM::StateTurnDownSwitchToLeft;
const TurnDownSwitchToRight MoveFSM::StateTurnDownSwitchToRight;
const TurnUpSwitchToLeft MoveFSM::StateTurnUpSwitchToLeft;
const TurnUpSwitchToRight MoveFSM::StateTurnUpSwitchToRight;

const Poisoned_TurnSwitchLeft MoveFSM::StatePoisoned_TurnSwitchLeft;
const Poisoned_TurnSwitchRight MoveFSM::StatePoisoned_TurnSwitchRight;

const DoNothing MoveFSM::StateDoNothing;