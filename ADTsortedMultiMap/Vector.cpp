#include "Vector.h"

Vector::Vector() {
	n = 0;
	cp = 1;
	e = new int[cp];
}

Vector::~Vector() {
	delete[] e;
}

void Vector::add(int x) {
	if (n == cp)
		resize();

	*(e + n) = x;
	n++;
}

void Vector::resize() {
	//New array of double the capacity of the initial one
	int* eNew = new int[2 * cp];

	//We copy all the elements from the old array into the new one
	for (int i = 0; i < n; i++)
		*(eNew + i) = *(e + i);

	//Doubling the capacity
	cp *= 2;

	//Freeing the memory occupied by the initial array
	delete[] e;

	//Now e will refer to the newly created array
	e = eNew;
}

void Vector::clear() {
	n = 0;
}