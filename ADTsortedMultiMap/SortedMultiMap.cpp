#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>

#include <iomanip>
using namespace std;

Node::Node() {
	key = NULL_TVALUE;
	cp = 1;
	values = new TValue[cp];
	n = 0;
}

Node::Node(TKey k) {
	key = k;
	values = new TValue[cp];
	cp = 1;
	n = 0;
}

Node::Node(const Node& other) {
	key = other.key;
	cp = other.cp;
	n = other.n;

	values = new TValue[cp];
	for (int i = n; i < cp; i++)
		values[i] = NULL_TVALUE;

	if (n != 0)
		for (int i = 0; i < n; i++)
			values[i] = other.values[i];
}

Node& Node::operator=(const Node& other) {
	if (this == &other)
		return *this;

	key = other.key;
	cp = other.cp;
	n = other.n;

	delete[] values;
	values = new TValue[cp];

	for (int i = n; i < cp; i++)
		values[i] = NULL_TVALUE;

	if (n != 0)
		for (int i = 0; i < n; i++)
			values[i] = other.values[i];

	return *this;
}

void Node::addValue(TValue value) {
	if (n == cp)
		resize();

	values[n++] = value;
}

void Node::removeValue(TValue value) {
	if (n == 0)
		return;

	int i;
	for (i = 0; i < n; i++)
		if (values[i] == value)
			break;

	if (i == n)
		return;

	for (int j = i; j < cp - 1; j++)
		values[j] = values[j + 1];

	values[n - 1] = NULL_TVALUE;
	n--;
}

void Node::resize() {
	TValue* valuesNew = new TValue[cp * 2];

	for (int i = 0; i < n; i++)
		valuesNew[i] = values[i];

	cp *= 2;

	for (int i = n; i < cp; i++)
		valuesNew[i] = NULL_TVALUE;

	delete[] values;
	values = valuesNew;
}

void Node::printValues() {
	for (int i = 0; i < n; i++)
		cout << values[i] << ' ';

	cout << '\n';
}

Node::~Node() {
	delete[] values;
}

/*
void SortedMultiMap::printTree() {
	// print all 3 arrays on separate lines, elements of same indexes line up one under the other
	cout << "n = " << n << '\n';
	cout << "cp = " << cp << '\n';
	cout << "firstEmpty = " << firstEmpty << '\n';
	
	cout << "   ";
	for (int i = 0; i < cp; i++) {
		cout << setw(3) << i;
		cout << ' ';
	}
	cout << '\n';

	cout << "K: ";
	for (int i = 0; i < cp; i++) {
		cout << setw(3);
		if (e[i].key != NULL_TVALUE)
			cout << e[i].key;
		else
			cout << ' ';
		cout << ' ';
	}
	cout << '\n';

	cout << "L: ";
	for (int i = 0; i < cp; i++) {
		cout << setw(3) << left[i];
		cout << ' ';
	}
	cout << '\n';

	cout << "R: ";
	for (int i = 0; i < cp; i++) {
		cout << setw(3) << right[i];
		cout << ' ';
	}
	cout << '\n';
}

void SortedMultiMap::printPairs() {
	for (int i = 0; i < cp; i++) {
		if (e[i].key != NULL_TVALUE) {
			cout << e[i].key << ": ";
			e[i].printValues();
		}
	}
}
*/

SortedMultiMap::SortedMultiMap(Relation r) {
	cp = 10; // initializing capacity
	n = 0;
	e = new Node[cp];
	left = new int[cp];
	right = new int[cp];
	rel = r;
	firstEmpty = 0;
	root = 0;
	pairs = 0;

	// left will also store the singly linked list of empty positions in the tree
	for (int i = 0; i < cp - 1; i++)
		left[i] = i + 1;
	left[cp - 1] = -1;
	 
	// for printing purposes
	for (int i = 0; i < cp; i++)
		right[i] = -1;
}

Node* SortedMultiMap::searchKey(int start, TKey k) const {
	if (e[start].key == k)
		return e + start;

	if (rel(k, e[start].key)) {  // if k < e[start].key
		if (left[start] != -1)
			return searchKey(left[start], k); // search left subtree

		return nullptr;
	}

	if (!rel(k, e[start].key)) { // if k > e[start].key
		if (right[start] != -1)
			return searchKey(right[start], k); // search right subtree

		return nullptr;
	}

	return nullptr;
}

void SortedMultiMap::resize() {
	if (n != cp)
		throw std::logic_error("Resize function can only be called if max capacity has been reached");

	Node* eNew = new Node[cp * 2];
	int* leftNew = new int[2 * cp];
	int* rightNew = new int[2 * cp];
	
	// cp *= 2;

	for (int i = 0; i < cp; i++)
		leftNew[i] = left[i];

	delete[] left;
	left = leftNew;

	// setting up the empty spots linked list in left
	for (int i = cp; i < cp * 2 - 1; i++)
		left[i] = i + 1;
	left[cp * 2 - 1] = -1;
	firstEmpty = cp;

	for (int i = 0; i < cp; i++)
		rightNew[i] = right[i];

	delete[] right;
	right = rightNew;

	for (int i = cp; i < cp * 2; i++)
		right[i] = -1;

	for (int i = 0; i < cp; i++)
		eNew[i] = e[i];

	cp *= 2;

	delete[] e;
	e = eNew;
}

void SortedMultiMap::addNode(int start, const Node& node) {
	if (rel(node.key, e[start].key)) {  // if node.key < e[start].key
		if (left[start] != -1)
			addNode(left[start], node); // search left subtree
		else {
			int emptySpot = firstEmpty;
			firstEmpty = left[firstEmpty];

			left[start] = emptySpot;
			e[emptySpot] = node;
			left[emptySpot] = right[emptySpot] = -1;
		}
	}

	if (!rel(node.key, e[start].key)) {  // if node.key > e[start].key
		if (right[start] != -1)
			addNode(right[start], node); // search right subtree
		else {
			int emptySpot = firstEmpty;
			firstEmpty = left[firstEmpty];

			right[start] = emptySpot;
			e[emptySpot] = node;
			left[emptySpot] = right[emptySpot] = -1;
		}
	}

	return;
}

vector<TKey> SortedMultiMap::keySet() const {
	vector<TKey> keys;

	for(int i = 0; i < n; i++)
		keys.push_back(e[i].key);

	return keys;
}

void SortedMultiMap::getInorderIndexes(int start, Vector& indexes) const {
	if (left[start] != -1)
		getInorderIndexes(left[start], indexes);

	indexes.add(start);

	if (right[start] != -1)
		getInorderIndexes(right[start], indexes);
}

void SortedMultiMap::add(TKey c, TValue v) {
	if (n == 0)
	{
		int emptySpot = firstEmpty;
		firstEmpty = left[firstEmpty];
		root = emptySpot;
		n = 1;
		pairs = 1;

		Node* node = new Node(c);
		node->addValue(v);
		e[root] = *node;
		left[root] = right[root] = -1;
		
		return;
	}

	// first, search if the key exists in the BST
	Node* node = searchKey(root, c);

	if (node != nullptr) {
		node->addValue(v);
		pairs++;
		return;
	}

	if (n == cp)
		resize();

	node = new Node(c);
	node->addValue(v);
	pairs++;
	addNode(root, *node);
	n++;
}

vector<TValue> SortedMultiMap::search(TKey c) const {
	Node* node = searchKey(root, c);
	if (node == nullptr)
		return vector<TValue>();

	vector<TValue> valuesVector = vector<TValue>();
	for (int i = 1; i <= node->n; i++)
		valuesVector.push_back(node->values[i]);

	return valuesVector;
}

bool SortedMultiMap::remove(TKey c, TValue v) {
	Node* node = searchKey(root, c);

	if (node == nullptr)
		return false;

	int initialSize = node->n;
	node->removeValue(v);

	if (node->n == initialSize)
		return false;

	pairs--;
	return true;
}


int SortedMultiMap::size() const {
	return pairs;
}

bool SortedMultiMap::isEmpty() const {
	return pairs == 0;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	delete[] e;
	delete[] left;
	delete[] right;
}
