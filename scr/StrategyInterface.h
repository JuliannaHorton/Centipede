#ifndef _StrategyInterface
#define _StrategyInterface

class MyPlayer;


#include "Game Components/TEAL/CommonElements.h"

class StrategyInterface : public GameObject
{
public:
	StrategyInterface() = default;
	StrategyInterface(const StrategyInterface&) = delete;
	StrategyInterface& operator=(const StrategyInterface&) = delete;
	~StrategyInterface() = default;

	virtual void ExecuteInput(MyPlayer*) = 0;
};

#endif _StrategyInterface