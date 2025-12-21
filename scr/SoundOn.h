#ifndef _SoundOn
#define _SoundOn

#include "SoundInterface.h"
class SoundManager;
class SoundPlay;

class SoundOn : public  SoundInterface
{
public:
	SoundOn() = default;
	SoundOn(const SoundOn&) = delete;
	SoundOn& operator=(const SoundOn&) = delete;
	~SoundOn() = default;

	virtual void ExecuteInput(SoundManager* manager, SoundPlay* sound) override;
};

#endif _SoundOn