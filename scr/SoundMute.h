#ifndef _SoundMute
#define _SoundMute

#include "SoundInterface.h"
class SoundManager;
class SoundPlay;

class SoundMute : public  SoundInterface
{
public:
	SoundMute() = default;
	SoundMute(const SoundMute&) = delete;
	SoundMute& operator=(const SoundMute&) = delete;
	~SoundMute() = default;

	virtual void ExecuteInput(SoundManager* manager, SoundPlay* sound) override {};
};

#endif _SoundMute
