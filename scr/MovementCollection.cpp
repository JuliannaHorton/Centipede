#include "MovementCollection.h"


const OffsetArray MovementCollection::OffsetsStraightRight = OffsetArray({ sf::Vector2f(1, 0),  sf::Vector2f(1, 0), sf::Vector2f(1, 0),  sf::Vector2f(1, 0),
	sf::Vector2f(1, 0),  sf::Vector2f(1, 0), sf::Vector2f(1, 0),  sf::Vector2f(1, 0), sf::Vector2f(1, 0),  sf::Vector2f(1, 0), sf::Vector2f(1, 0),  sf::Vector2f(1, 0),
	sf::Vector2f(1, 0),  sf::Vector2f(1, 0), sf::Vector2f(1, 0),  sf::Vector2f(1, 0) });

const OffsetArray MovementCollection::OffsetsTurnUpEndRight = OffsetArray({ sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1),
	sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1),
	sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1) });

const OffsetArray MovementCollection::OffsetsTurnDownEndRight = OffsetArray({ sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1),
	sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1),
	sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1) });

const OffsetArray MovementCollection::OffsetsStraightLeft = OffsetArray({ sf::Vector2f(-1, 0),  sf::Vector2f(-1, 0), sf::Vector2f(-1, 0),  sf::Vector2f(-1, 0),
	sf::Vector2f(-1, 0),  sf::Vector2f(-1, 0), sf::Vector2f(-1, 0),  sf::Vector2f(-1, 0), sf::Vector2f(-1, 0),  sf::Vector2f(-1, 0), sf::Vector2f(-1, 0),  sf::Vector2f(-1, 0),
	sf::Vector2f(-1, 0),  sf::Vector2f(-1, 0), sf::Vector2f(-1, 0),  sf::Vector2f(-1, 0) });

const OffsetArray MovementCollection::OffsetsTurnUpEndLeft = OffsetArray({ sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1),
	sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1),
	sf::Vector2f(0,-1),  sf::Vector2f(0,-1), sf::Vector2f(0,-1),  sf::Vector2f(0,-1) });

const OffsetArray MovementCollection::OffsetsTurnDownEndLeft = OffsetArray({ sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1),
	sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1),
	sf::Vector2f(0,1),  sf::Vector2f(0,1), sf::Vector2f(0,1),  sf::Vector2f(0,1) });



const OffsetArray MovementCollection::OffsetsPoisonedTurnDownEndLeft = OffsetArray({ sf::Vector2f(1,1),  sf::Vector2f(1,1), sf::Vector2f(1,1),  sf::Vector2f(1,1),
	sf::Vector2f(1,1),  sf::Vector2f(1,1), sf::Vector2f(1,1),  sf::Vector2f(1,1), sf::Vector2f(1,1),  sf::Vector2f(1,1), sf::Vector2f(1,1),  sf::Vector2f(1,1),
	sf::Vector2f(1,1),  sf::Vector2f(1,1), sf::Vector2f(1,1),  sf::Vector2f(1,1) });

const OffsetArray MovementCollection::OffsetsPoisonedTurnDownEndRight = OffsetArray({ sf::Vector2f(-1,1),  sf::Vector2f(-1,1), sf::Vector2f(-1,1),  sf::Vector2f(-1,1),
	sf::Vector2f(-1,1),  sf::Vector2f(-1,1), sf::Vector2f(-1,1),  sf::Vector2f(-1,1), sf::Vector2f(-1,1),  sf::Vector2f(-1,1), sf::Vector2f(-1,1),  sf::Vector2f(-1,1),
	sf::Vector2f(-1,1),  sf::Vector2f(-1,1), sf::Vector2f(-1,1),  sf::Vector2f(-1,1) });


const OffsetArray MovementCollection::OffsetsDoNothing = OffsetArray({ sf::Vector2f(0,0),  sf::Vector2f(0,0), sf::Vector2f(0,0),  sf::Vector2f(0,0),
	sf::Vector2f(0,0),  sf::Vector2f(0,0), sf::Vector2f(0,0),  sf::Vector2f(0,0), sf::Vector2f(0,0),  sf::Vector2f(0,0), sf::Vector2f(0,0),  sf::Vector2f(0,0),
	sf::Vector2f(0,0),  sf::Vector2f(0,0), sf::Vector2f(0,0),  sf::Vector2f(0,0) });

// Note: In this demoe, I move one cell per frame, so I only need one movement offset per direction.
// If your centipede takes 8 frame to move fro mone cell to another, then these offset collection would 
// need to be an array of 8 offsets, one for each frame. The sprite position at frame i would be
// previous cell center + ith offset value