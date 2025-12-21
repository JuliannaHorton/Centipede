#ifndef _KeyboardControl
#define _KeyboardControl

#include "StrategyInterface.h"
class MyPlayer;

class KeyboardControl : public  StrategyInterface
{
public:
	KeyboardControl();
	KeyboardControl(const KeyboardControl&) = delete;
	KeyboardControl& operator=(const KeyboardControl&) = delete;
	~KeyboardControl() = default;

	virtual void ExecuteInput(MyPlayer*) override;
	virtual void KeyPressed(sf::Keyboard::Key k, bool altKey, bool ctrlKey, bool shiftKey, bool systemKey);
};

#endif _KeyboardControl
