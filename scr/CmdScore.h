#pragma once
#include "SpiderScoresFactory.h"

class CmdScore
{
public:
	CmdScore() = default;
	CmdScore(const CmdScore&) = delete;
	CmdScore& operator=(const CmdScore&) = delete;
	virtual ~CmdScore() = default;

	// Note: the Excecute method must NOT have _any_ paramters
	virtual void Execute() = 0;
};
