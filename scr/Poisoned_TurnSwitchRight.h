#ifndef _Poisoned_TurnSwitchRight
#define _Poisoned_TurnSwitchRight

#include "MoveState.h"

class Poisoned_TurnSwitchRight : public MoveState
{
public:
	Poisoned_TurnSwitchRight();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};

#endif _TurnUpSwitchToLeft
