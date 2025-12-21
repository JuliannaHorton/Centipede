#include "HUD.h"
#include "HUDAccess.h"

HUDAccess* HUDAccess::ptrInstance = nullptr;
HUD* HUDAccess::myHUD;

void HUDAccess::Initialize()
{
	myHUD = new HUD;
}

void HUDAccess::privScoreUpdate(int Score)
{
	myHUD->ScoreUpdate(Score);

}

void HUDAccess::privUpdateLife()
{
	myHUD->UpdateLife();
}

void HUDAccess::privPlayerSwitch()
{
	myHUD->PlayerSwitch();
}

void HUDAccess::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}