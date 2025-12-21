#pragma once

#ifndef _PlayerPool
#define _PlayerPool

#include <stack>
#include <SFML/System/Vector2.hpp>

class MyPlayer;

class PlayerPool
{
private:
	std::stack<MyPlayer*> recycledItems;
	MyPlayer* CurPlayer = nullptr;

public:
	PlayerPool() = default;
	PlayerPool(const PlayerPool&) = delete;
	PlayerPool& operator=(const PlayerPool&) = delete;
	~PlayerPool();

	MyPlayer* GetPlayer();

	void ReturnPlayer(MyPlayer* b);

	sf::Vector2f CurPlayerPos();
};

#endif _PlayerPool