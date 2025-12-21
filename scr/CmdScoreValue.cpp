#include "CmdScoreValue.h"
#include <iostream>
#include "ScoreAccessor.h"

CmdScoreValue::CmdScoreValue(int val)
	: points(val)
{
	printf("Score Command created: Points = %i\n", val);
}

void CmdScoreValue::Execute()
{
	printf("\tScore Command Executing\n");
	ScoreAccessor::AddScore(points);
}