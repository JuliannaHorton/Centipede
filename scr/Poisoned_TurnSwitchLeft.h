#ifndef _Poisoned_TurnSwitchLeft
#define _Poisoned_TurnSwitchLeft

#include "MoveState.h"

class Poisoned_TurnSwitchLeft : public MoveState
{
public:
	Poisoned_TurnSwitchLeft();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};

#endif _TurnUpSwitchToLeft
