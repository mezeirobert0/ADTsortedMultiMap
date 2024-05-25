#pragma once

#include "SortedMultiMap.h"
#include <vector>


class SMMIterator{
	friend class SortedMultiMap;
	friend class Node;
private:
	int currentNodeIndex;
	int currentValueIndex;
	vector<int> indices;

	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);

public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

