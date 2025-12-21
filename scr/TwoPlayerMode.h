#pragma once
// DefaultScene

#ifndef _TwoPlayerMode
#define _TwoPlayerMode

#include "Game Components/TEAL/CommonElements.h"


class TwoPlayerMode : public Scene
{
public:
	TwoPlayerMode() = default;
	TwoPlayerMode(const TwoPlayerMode&) = delete;
	TwoPlayerMode& operator=(const TwoPlayerMode&) = delete;
	~TwoPlayerMode() = default;

	virtual void Initialize();
	virtual void Terminate();
};

#endif _TwoPlayerMode