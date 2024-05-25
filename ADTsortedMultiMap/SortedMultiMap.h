#pragma once

#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
// typedef std::pair<TKey, TValue*> TElem;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);

class Node {
    friend class SortedMultiMap;
public:
    TKey key;
    TValue* values;
    int n;
    int cp;

    Node();
    Node(TKey);
	Node(const Node&);
	Node& operator=(const Node&);
    void addValue(TValue);
    void removeValue(TValue);
    void resize();
    void printValues(); // for printing purposes
    ~Node();
};

class SortedMultiMap {
	friend class SMMIterator;
    friend class Node;

private:
    Node* e;
    int* left;
    int* right;
    Relation rel;
    int n; // current size
    int cp; // maximum capacity
    int firstEmpty; // index of the first empty spot in the binary search tree
    int root; // index of the root of the BST
	int pairs; // number of <key, value> pairs in the map

    // returns a pointer to a Node with the specified Key
    // or nullptr if no such node exists in the BST
    Node* searchKey(int, TKey) const;

    // resize function to call if the 3 arrays reach maximum capacity
    void resize();

    // method to add in tree in correspoding spot
    // will be used by add method
    void addNode(int, const Node&);

public:
	// recursive method to eppend to a vector the indexes of the nodes in the inorder traversal
    void getInorderIndexes(int, vector<int>&) const;

    // void printTree();

	// void printPairs();

    // constructor
    SortedMultiMap(Relation r);

	//adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

	//returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

	//removes a key value pair from the sorted multimap
	//returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will return the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();
};
