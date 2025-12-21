#pragma once

#pragma once

#ifndef _HUDAccess
#define _HUDAccess

#include "Game Components/TEAL/CommonElements.h"

class HUD;

class HUDAccess
{
private:
	static HUDAccess* ptrInstance;	// set up as a singleton

	HUDAccess() = default;
	HUDAccess(const HUDAccess&) = delete;
	HUDAccess& operator=(const HUDAccess&) = delete;
	~HUDAccess() = default;

	static HUDAccess& Instance()					// Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new HUDAccess;
		return *ptrInstance;
	};

	static HUD* myHUD;

	void privScoreUpdate(int s);
	void privUpdateLife();
	void privPlayerSwitch();

public:

	static void UpdateScore(int s) { Instance().privScoreUpdate(s); };
	static void UpdateLife() { Instance().privUpdateLife(); };
	static void PlayerSwitch() { Instance().privPlayerSwitch(); };

	static void Terminate();
	static void Initialize();
};

#endif _GameController
