#pragma once

#include "RBTree.h"

template<class K>
class MySet
{
	struct  SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename RBTree<K, K, SetKeyOfValue>::iterator iterator;
	iterator begin()
	{
		return t.begin();
	}
	iterator end()
	{
		return t.end();
	}
	std::pair<iterator, bool> Insert(const K& key)
	{
		return t.Insert(key);
	}
private:
	RBTree<K, K, SetKeyOfValue> t;
};

void testSet()
{
	MySet<int> s;
	s.Insert(1);
	s.Insert(0);
	s.Insert(5);
	s.Insert(4);
	s.Insert(3);

	MySet<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for(auto e : s)
	{
		cout << e << " " ;
	}
	cout << endl;
}