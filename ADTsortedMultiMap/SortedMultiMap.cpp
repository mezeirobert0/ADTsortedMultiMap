#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

SortedMultiMap::SortedMultiMap(Relation r) {
	
}

void SortedMultiMap::add(TKey c, TValue v) {
	
}

vector<TValue> SortedMultiMap::search(TKey c) const {
	
	return vector<TValue>();
}

bool SortedMultiMap::remove(TKey c, TValue v) {
	
    return false;
}


int SortedMultiMap::size() const {
	
	return 0;
}

bool SortedMultiMap::isEmpty() const {
	
	return false;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	
}
