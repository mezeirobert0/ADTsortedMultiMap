#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <stdexcept>
#include <iostream>
using namespace std;

SMMIterator::SMMIterator(const SortedMultiMap& d) : map(d){
	first();
}

void SMMIterator::first(){
	indices.clear();
	map.getInorderIndexes(0, indices);
	currentValueIndex = 0;
	currentNodeIndex = 0;

	while (currentNodeIndex < map.n && currentValueIndex == map.e[indices[currentNodeIndex]].n) {
		currentNodeIndex++;
		currentValueIndex = 0;
	}
}

void SMMIterator::next(){
	if (!valid())
		throw std::out_of_range("Iterator is out of range!");
	
	currentValueIndex++;

	while (currentNodeIndex < map.n && currentValueIndex == map.e[indices[currentNodeIndex]].n) {
		currentNodeIndex++;
		currentValueIndex = 0;
	}
}

bool SMMIterator::valid() const{
	return currentNodeIndex < map.n && currentValueIndex < map.e[indices[currentNodeIndex]].n;
}

TElem SMMIterator::getCurrent() const{
	if (!valid())
		throw std::out_of_range("Iterator is out of range!");

	return TElem(map.e[indices[currentNodeIndex]].key, map.e[indices[currentNodeIndex]].values[currentValueIndex]);
}

// vector subscript out of range, how to fix it?
// I have no idea, I'm just a comment.
// I'm not sure, but I think the problem is in the SortedMultiMap::getInorderIndexes function.


