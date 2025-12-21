#ifndef _MovementCollection
#define _MovementCollection
#include <SFML/System/Vector2.hpp>

struct Offsets
{
	sf::Vector2f values[16];
};

struct OffsetArray
{
	Offsets set;

	OffsetArray(Offsets a) : set(a) {};
};

class MovementCollection
{
public:
	static const OffsetArray OffsetsStraightRight;
	static const OffsetArray OffsetsTurnUpEndRight;
	static const OffsetArray OffsetsTurnDownEndRight;
	static const OffsetArray OffsetsStraightLeft;
	static const OffsetArray OffsetsTurnUpEndLeft;
	static const OffsetArray OffsetsTurnDownEndLeft;

	static const OffsetArray OffsetsPoisonedTurnDownEndLeft;
	static const OffsetArray OffsetsPoisonedTurnDownEndRight;

	static const OffsetArray OffsetsDoNothing;
};

#endif _MovementCollection

