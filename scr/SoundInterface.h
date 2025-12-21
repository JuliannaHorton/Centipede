#ifndef _SoundInterface
#define _SoundInterface

class SoundManager;
class SoundPlay;


class SoundInterface
{
public:
	SoundInterface() = default;
	SoundInterface(const SoundInterface&) = delete;
	SoundInterface& operator=(const SoundInterface&) = delete;
	~SoundInterface() = default;

	virtual void ExecuteInput(SoundManager*, SoundPlay*) = 0;
};

#endif _SoundInterface