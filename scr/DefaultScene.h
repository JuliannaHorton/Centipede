// DefaultScene

#ifndef _DefaultScene
#define _DefaultScene

#include "Game Components/TEAL/CommonElements.h"


class DefaultScene : public Scene
{
public:
	DefaultScene() = default;
	DefaultScene(const DefaultScene&) = delete;
	DefaultScene& operator=(const DefaultScene&) = delete;
	~DefaultScene() = default;

	virtual void Initialize();
	virtual void Terminate();
};

#endif _DefaultScene