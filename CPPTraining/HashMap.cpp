#include "HashMap.h"
#include "Node.h"
using namespace std;

IntHashMap::IntHashMap()
{
	lists = new List<LinkedList<Tuple> *>(100);
	for (int x = 0; x < 100; x++)
	{
		lists->append(NULL);
	}
}
int IntHashMap::HashValue(int value)
{
	int original = value;
	value /= 100;
	value *= 100;
	int diff = original - value;
	return diff;
}
IntHashMap::~IntHashMap()
{
	for (int x = 0; x < 100; x++)
	{
		if (lists->at(x) != NULL) delete lists->at(x);
	}
}
void IntHashMap::Insert(int key, int value)
{
	int hash = HashValue(key);
	const Tuple t(key, value);
	if (lists->at(hash) == NULL)
	{
		LinkedList<Tuple> * newList = new LinkedList<Tuple>(t);
		lists->insert(newList, hash);
	}
	else
	{
		lists->at(hash)->add(t);
	}
}
int IntHashMap::operator[](int key)
{
	int hash = HashValue(key);
	LinkedList<Tuple> *l = lists->at(hash);
	for (int x = 0; x < l->size(); x++)
	{
		if (l->at(x).key == key) return l->at(x).value;
	}
	return 0;
}

