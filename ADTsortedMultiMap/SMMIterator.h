#pragma once

#include "SortedMultiMap.h"
#include <vector>
#include "Vector.h"


class SMMIterator{
	friend class SortedMultiMap;
	friend class Node;
private:
	int currentNodeIndex;
	int currentValueIndex;
	Vector indices;

	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

