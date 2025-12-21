#pragma once

#ifndef _BulletPool
#define _BulletPool

#include <stack>

class Bullet;

class BulletPool
{
private:
	std::stack<Bullet*> recycledItems;

public:
	BulletPool() = default;
	BulletPool(const BulletPool&) = delete;
	BulletPool& operator=(const BulletPool&) = delete;
	~BulletPool();

	Bullet* GetBullet();

	void ReturnBullet(Bullet* b);
};

#endif _BulletPool