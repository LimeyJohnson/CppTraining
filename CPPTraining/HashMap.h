#pragma once
#include "LinkedList.h"
#include "List.h"
using namespace std;

template<class K, class V>
class Tuple {
public:
	K key;
	V value;
	Tuple(K k, V v)
	{
		key = k;
		value = v;
	}
	Tuple() {}
};

template<class K, class V>
class IntHashMap
{
	List<LinkedList<Tuple<K,V>*>*>* lists;
public:

	IntHashMap() 
	{
		lists = new List<LinkedList<Tuple<K, V>*>*>(100);
		for (int x = 0; x < 100; x++)
		{
			lists->append(NULL);
		}
	}
	~IntHashMap()
	{
		for (int x = 0; x < 100; x++)
		{
			if (lists->at(x) != NULL) delete lists->at(x);
		}
	}
	int HashValue(int key) 
	{
		int fullHash = std::hash<K>()(key);
		int fullHashCpy = fullHash;
		fullHash /= 100;
		fullHash *= 100;
		int diff = fullHashCpy - fullHash;
		return diff > 0 ? diff : (-1) * diff;
	}
	void Insert(int key, int value)
	{
		int hash = HashValue(key);
		Tuple<K,V>* t = new Tuple<K,V>(key, value);
		if (lists->at(hash) == NULL)
		{
			LinkedList<Tuple<K,V>*> * newList = new LinkedList<Tuple<K, V>*>(t);
			lists->insert(newList, hash);
		}
		else
		{
			lists->at(hash)->add(t);
		}
	}
	int operator [] (int key)
	{
		int hash = HashValue(key);
		LinkedList<Tuple<K,V>*> *l = lists->at(hash);
		for (int x = 0; x < l->size(); x++)
		{
			if (l->at(x)->key == key) return l->at(x)->value;
		}
		return 0;
	}
};