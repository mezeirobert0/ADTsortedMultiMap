#pragma once

#include "SortedMultiMap.h"


class SMMIterator{
	friend class SortedMultiMap;
private:
	const SortedMultiMap& map;
	SMMIterator(const SortedMultiMap& map);



public:
	void first();
	void next();
	bool valid() const;
   	TElem getCurrent() const;
};

