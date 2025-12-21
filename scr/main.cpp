//#include "Game Components/MemTracker/Framework.h"

class Dummy
{
public: 
	Dummy() {}
	virtual ~Dummy() {}
};
Dummy dummy;

#include "Game Components\TEAL\Game.h"

int main()
{
	//_crtBreakAlloc = 293;

	Game::Run();

    return 0;
}
