#include "SoundAccessor.h"
#include "SoundPlay.h"
#include "SoundInterface.h"
#include "SoundMute.h"
#include "SoundOn.h"
#include "Mode.h"

SoundAccessor* SoundAccessor::ptrInstance = nullptr;
SoundManager* SoundAccessor::myManager;
SoundInterface* SoundAccessor::myMode;
//bool SoundAccessor::mute;


void SoundAccessor::Initialize()
{
	myMode = &Mode::ModeMute;
	myManager = new SoundManager();
}

SoundPlay* SoundAccessor::AddSound(mySoundEvents ev)
{
	switch (ev)
	{
	case mySoundEvents::PlayerDied:
		return myManager->GetSoundCommand(0);
		break;
	case mySoundEvents::FleaSpawn:
		return myManager->GetSoundCommand(1);
		break;
	case mySoundEvents::ScorpionSpawn:
		return myManager->GetSoundCommand(2);
		break;
	case mySoundEvents::SpiderSpawn:
		return myManager->GetSoundCommand(3);
		break;
	case mySoundEvents::FireBullet:
		return myManager->GetSoundCommand(4);
		break;
	case mySoundEvents::CritterDied:
		return myManager->GetSoundCommand(5);
		break;
	}

	return nullptr;
}

void SoundAccessor::privSendSound(SoundPlay *c)
{
	myMode->ExecuteInput(myManager, c);
}

void SoundAccessor::privMute()
{
	//delete myMode;
	if (myMode == &Mode::ModeMute)
	{
		myMode = &Mode::ModeOn;
	}
	else
	{
		myMode = &Mode::ModeMute;
	}
}

void SoundAccessor::privStopLoop(LoopedPlay* c)
{
	myManager->StopLoop(c);
}

void SoundAccessor::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;	// important habit for Singleton. Why?
}