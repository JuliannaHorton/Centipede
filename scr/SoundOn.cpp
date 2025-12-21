#include "SoundOn.h"
#include "SoundManager.h"
#include "SoundPlay.h"

void SoundOn::ExecuteInput(SoundManager* Manager, SoundPlay* sound)
{
	Manager->SendSound(sound);
}
