#include "CmdScoreByDistance.h"
#include <iostream>
#include "ScoreAccessor.h"

#include "SpiderFactory.h"
#include "PlayerFactory.h"

//#include <cmath> 

CmdScoreByDistance::CmdScoreByDistance(int dn, int dm, int df,
	int vn, int vm, int vf)
	: vNear(vn), vMed(vm), vFar(vf)
{
	dNear = WindowY / dn;
	dMed = WindowY / dm;
	dFar = WindowY / df;
}

void CmdScoreByDistance::Execute()
{

	sf::Vector2f SpiderPos = SpiderFactory::GetPos();
	sf::Vector2f PlayerPos = PlayerFactory::GetPos();

	sf::Vector2f Distance = sf::Vector2f(SpiderPos.x - PlayerPos.x, SpiderPos.y - PlayerPos.y);

	float CalDistance = (float)sqrt(int(Distance.x*Distance.x + Distance.y*Distance.y));



	// processing distance to score:
	if (CalDistance <= dNear)
	{
		SpiderScoresFactory::CreateScores(SpiderFactory::GetPos(), vNear);
		ScoreAccessor::AddScore(vNear);
	}
	else if (CalDistance <= dMed)
	{
		SpiderScoresFactory::CreateScores(SpiderFactory::GetPos(), vMed);
		ScoreAccessor::AddScore(vMed);
	}
	else
	{
		SpiderScoresFactory::CreateScores(SpiderFactory::GetPos(), vFar);
		ScoreAccessor::AddScore(vFar);
	}

	ConsoleMsg::WriteLine("SpiderScore" + Tools::ToString(vNear));
}
