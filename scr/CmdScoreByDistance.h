#pragma once

#include "CmdScore.h"
#include "Game Components/TEAL/CommonElements.h"

class CmdScoreByDistance : public CmdScore
{
private:
	int dNear;
	int dMed;
	int dFar;
	int vNear;
	int vMed;
	int vFar;

public:
	CmdScoreByDistance() = delete;
	CmdScoreByDistance(const CmdScoreByDistance&) = delete;
	CmdScoreByDistance& operator=(const CmdScoreByDistance&) = delete;
	virtual ~CmdScoreByDistance() = default;

	CmdScoreByDistance(int dNear, int dMed, int dFar,
		int vNear, int vMed, int vFar);

	virtual void Execute() override;

	int WindowY = (int)WindowManager::Window().getView().getSize().y;

};
