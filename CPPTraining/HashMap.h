#pragma once
#include "LinkedList.h"
#include "List.h"
using namespace std;

class Tuple {
public:
	int key;
	int value;
	Tuple(int k, int v)
	{
		key = k;
		value = v;
	}
	Tuple() {}
};
class IntHashMap
{
	List<LinkedList<Tuple>*>* lists;
public:
	IntHashMap();
	~IntHashMap();
	int HashValue(int value);
	void Insert(int key, int value);
	int operator [] (int key);
};