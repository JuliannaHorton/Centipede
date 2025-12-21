#pragma once

#ifndef _CentipedeHeadPool
#define _CentipedeHeadPool

#include <stack>

class CentipedeHead;

class CentipedeHeadPool
{
private:
	std::stack<CentipedeHead*> recycledItems;

public:
	CentipedeHeadPool();
	CentipedeHeadPool(const CentipedeHeadPool&) = delete;
	CentipedeHeadPool& operator=(const CentipedeHeadPool&) = delete;
	~CentipedeHeadPool();

	CentipedeHead* GetHead();

	void ReturnHead(CentipedeHead* b);
};

#endif _CentipedeHeadPool