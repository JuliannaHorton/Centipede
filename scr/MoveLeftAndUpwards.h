#pragma once

#ifndef _MoveLeftAndUpwards
#define _MoveLeftAndUpwards

#include "MoveState.h"

class MoveLeftAndUpwards : public  MoveState
{
public:
	MoveLeftAndUpwards();
	virtual const MoveState* GetNextState(CentipedeHead* chead) const override;
	virtual void Show() const override;
};

#endif _MoveLeftAndUpwards
