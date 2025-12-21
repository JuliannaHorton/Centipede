#ifndef _AIControl
#define _AIControl

#include "StrategyInterface.h"
class MyPlayer;

class AIControl : public  StrategyInterface
{
public:
	AIControl();
	AIControl(const AIControl&) = delete;
	AIControl& operator=(const AIControl&) = delete;
	~AIControl() = default;

	virtual void Alarm4();
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
	virtual void ExecuteInput(MyPlayer*) override;

private:
	int x = 0;
	int y = 0;
};

#endif _AIControl
