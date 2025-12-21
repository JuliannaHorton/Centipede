#ifndef _MoveFSM
#define _MoveFSM

class MoveRightAndDownwards;
class MoveRightAndUpwards;
class MoveLeftAndDownwards;
class MoveLeftAndUpwards;
class TurnDownSwitchToLeft;
class TurnDownSwitchToRight;
class TurnUpSwitchToLeft;
class TurnUpSwitchToRight;

class Poisoned_TurnSwitchLeft;
class Poisoned_TurnSwitchRight;

class DoNothing;


class MoveFSM
{
private:

public:
	static const MoveRightAndDownwards StateMoveRightAndDownwards;
	static const MoveRightAndUpwards StateMoveRightAndUpwards;
	static const MoveLeftAndDownwards StateMoveLeftAndDownwards;
	static const MoveLeftAndUpwards StateMoveLeftAndUpwards;
	static const TurnDownSwitchToLeft StateTurnDownSwitchToLeft;
	static const TurnDownSwitchToRight StateTurnDownSwitchToRight;
	static const TurnUpSwitchToLeft StateTurnUpSwitchToLeft;
	static const TurnUpSwitchToRight StateTurnUpSwitchToRight;

	static const Poisoned_TurnSwitchLeft StatePoisoned_TurnSwitchLeft;
	static const Poisoned_TurnSwitchRight StatePoisoned_TurnSwitchRight;

	static const DoNothing StateDoNothing;

};

#endif _MoveFSM