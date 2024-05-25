#include <iostream>

#include "ShortTest.h"
#include "ExtendedTest.h"

#include "SortedMultiMap.h"
#include "SMMIterator.h"

// #include <assert.h>
// #include <vector>

/*
bool cresc(TKey c1, TKey c2) {
	if (c1 <= c2) {
		return true;
	}
	else {
		return false;
	}
}
*/

int main() {
	testAll();
	testAllExtended();

	std::cout << "Finished SMM Tests!" << std::endl;
	system("pause");

	// add the following numbers to a map, each with a single key: 8 4 10 3 5 9 12
	/*SortedMultiMap smm = SortedMultiMap(cresc);
	smm.add(8, 0);
	smm.add(4, 0);
	smm.add(10, 0);
	smm.add(4, 1);
	smm.add(3, 0);
	smm.add(5, 0);
	smm.add(9, 0);
	smm.add(12, 0);
	smm.add(12, 1);
	smm.remove(5, 0);

	auto it = smm.iterator();
	while (it.valid()) {
		auto elem = it.getCurrent();
		std::cout << elem.first << ' ' << elem.second << '\n';
		it.next();
	}

	for (int i = 0; i <= 12; i++)
		smm.remove(i, 0), smm.remove(i, 1);

	assert(smm.size() == 0);

	it.first();
	assert(it.valid() == false);
	it.next();*/

	/*SortedMultiMap smm(cresc);
	int min = 10;
	int max = 25;
	for (int i = min; i <= max; i++) {
		smm.add(i, i);
		if (i % 2 == 0)
			smm.add(i, i + 2);
	}

	for (int c = min; c <= max; c++) {
		assert(smm.remove(c, c + 1) == false);
		if (c % 2 == 0)
			assert(smm.remove(c, c) == true);
		testIteratorSteps(smm);
	}

	smm.printPairs();

	for (int c = min; c <= max; c++) {
		if (c % 2 == 1) {
			assert(smm.remove(c, c + 1) == false);
			assert(smm.remove(c, c) == true);
		}
		else {
			assert(smm.remove(c, c + 2) == true);
		}
		testIteratorSteps(smm);
	}

	smm.printPairs();
	assert(smm.size() == 0);

	auto it = smm.iterator();

	try {
		it.getCurrent();
		assert(false);
	}
	catch (std::exception&) {
		assert(true);
	}*/

	/*
	auto r = cresc;
	SortedMultiMap smm(r);
	int current = 3;
	while (smm.size() < 8000) {
		smm.add(current, current);
		smm.add(current, current * 2);

		smm.printTree();
		cout << '\n';

		current = (current + 13) % 99;
	}
	SMMIterator smit = smm.iterator();
	TKey first = smit.getCurrent().first;
	smit.next();
	while (smit.valid()) {
		TKey current = smit.getCurrent().first;
		assert(current == smit.getCurrent().second || current == smit.getCurrent().second / 2);
		assert(r(first, current));
		first = current;
		smit.next();
	}
	SMMIterator smmi = smm.iterator();
	int count = smm.size();
	for (int i = 0; i < count / 2; i++) {
		smmi.next();
	}
	smmi.first();
	int c = 0;

	while (smmi.valid()) {
		c++;
		smmi.next();
	}
	assert(c == smm.size());
	*/

	/*SortedMultiMap smm = SortedMultiMap(cresc);
	smm.add(1, 2);
	smm.add(1, 3);
	assert(smm.remove(2, 1) == false);*/

	/*SortedMultiMap smm = SortedMultiMap(cresc);
	smm.printTree(); cout << '\n';

	smm.add(100, 0);
	smm.printTree(); cout << '\n';

	smm.add(500, 0);
	smm.printTree(); cout << '\n';

	smm.add(20, 0);
	smm.printTree(); cout << '\n';

	smm.add(600, 0);
	smm.printTree(); cout << '\n';

	smm.add(600, 10);
	smm.printTree(); cout << '\n';

	smm.add(200, 0);
	smm.printTree(); cout << '\n';

	smm.add(70, 0);
	smm.printTree(); cout << '\n';

	smm.add(5, 0);
	smm.printTree(); cout << '\n';

	smm.add(1, 0);
	smm.printTree(); cout << '\n';

	smm.add(2, 0);
	smm.printTree(); cout << '\n';

	smm.add(250, 0);
	smm.printTree(); cout << '\n';

	testIteratorSteps(smm);

	cout << "--------------------------\n";

	auto map = SortedMultiMap(cresc);
	map.add(4, 0);
	map.add(4, 1);

	map.add(1, 0);
	map.add(1, 1);
	map.add(1, 2);
	map.add(1, 3);
	map.add(1, 4);

	map.add(2, 0);
	map.add(2, 1);
	map.add(2, 2);

	map.add(3, 0);
	map.remove(3, 0);

	map.add(5, 0);
	map.add(5, 1);
	map.add(5, 2);
	map.add(5, 3);

	map.printTree();

	auto it = map.iterator();
	while (it.valid()) {
		auto elem = it.getCurrent();
		cout << elem.first << ' ' << elem.second << '\n';
		it.next();
	}*/

	return 0;
}
