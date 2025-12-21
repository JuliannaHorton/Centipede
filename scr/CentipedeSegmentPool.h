#pragma once

#ifndef _CentipedeSegmentPool
#define _CentipedeSegmentPool

#include <stack>

class CentipedeSegment;
class CentipedeHead;

class CentipedeSegmentPool
{
private:
	std::stack<CentipedeSegment*> recycledItems;

public:
	CentipedeSegmentPool();
	CentipedeSegmentPool(const CentipedeSegmentPool&) = delete;
	CentipedeSegmentPool& operator=(const CentipedeSegmentPool&) = delete;
	~CentipedeSegmentPool();

	CentipedeSegment* GetSeg();

	void ReturnSeg(CentipedeSegment* b);
};

#endif _CentipedeSegmentPool