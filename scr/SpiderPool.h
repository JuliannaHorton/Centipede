#pragma once

#ifndef _SpiderPool
#define _SpiderPool

#include <stack>
#include <SFML/Graphics.hpp>

class Spider;

class SpiderPool
{
private:
	std::stack<Spider*> recycledItems;

	Spider* CurSpider = nullptr;

public:
	SpiderPool() = default;
	SpiderPool(const SpiderPool&) = delete;
	SpiderPool& operator=(const SpiderPool&) = delete;
	~SpiderPool();

	Spider* GetSpider();

	void ReturnSpider(Spider* b);

	sf::Vector2f CurSpiderPos();

};

#endif _SpiderPool