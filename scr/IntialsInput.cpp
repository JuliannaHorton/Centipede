#include "InitialsInput.h"
#include "SpriteString.h"
#include  "HighScoreManager.h"

InitialsInput::InitialsInput(HighScoreManager* referenceBack)
{
	RegisterInput(InputFlags::TextEntered);
	Reference = referenceBack;

	InitialsPos = sf::Vector2f(200, 200);

	Label = new SpriteString("Enter Initials: ", sf::Vector2f(130, 184));
	myInitials = new SpriteString("", InitialsPos);
}

void InitialsInput::TextEntered(sf::Uint32 UnicodeValue)
{
	//if (!initials.empty() )
	char text = (char)UnicodeValue;

	if (text == '\b')
	{
		myInitials->Backspace();
		if (!Initials.empty()) Initials.pop_back();
	}
	else if (text == '\r')
	{
		Reference->ReceiveInput(Initials);
		MarkForDestroy();
	}
	else if (Initials.size() < 3)
	{
		Initials.push_back(text);

		myInitials->SetText(Initials);
	}

	// we must update the next position ourselves

}

void InitialsInput::Destroy()
{
	myInitials->MarkForDestroy();
	Label->MarkForDestroy();
	DeregisterInput(InputFlags::TextEntered);
}