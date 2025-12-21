#ifndef _DoNothing
#define _DoNothing

#include "MoveState.h"

class DoNothing : public  MoveState
{
public:
	DoNothing();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};

#endif _DoNothing
