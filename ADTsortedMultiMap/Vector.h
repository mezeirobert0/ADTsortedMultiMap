#pragma once
class Vector
{
public:
	int* e;
	int n;
	int cp;

	Vector();
	void add(int);
	void resize();
	void clear();
	~Vector();
};

