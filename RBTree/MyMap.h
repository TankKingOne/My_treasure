#pragma once

#include "RBTree.h"

template<class K, class T>
class MyMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const std::pair<K, T>& kv)
		{
			return kv.first;
		}
	};
public:
	typedef typename  RBTree<K, std::pair<K, T>, MapKeyOfValue>::iterator iterator;
	//typedef pair<K, T> ValueType;
	iterator begin()
	{
		return t.begin();
	}
	iterator end()
	{
		return t.end();
	}

	T& operator[](const K& key)
	{
		return (*(t.Insert(std::make_pair(key, T()))).first).second;
	}

	std::pair<iterator, bool> Insert(const std::pair<K, T>& kv)
	{
		return t.Insert(kv);
	}
private:
	RBTree<K, std::pair<K, T>, MapKeyOfValue> t;
};

void testMap()
{
	MyMap<std::string, std::string> dict;
	dict.Insert(std::make_pair(std::string("sort"), std::string("ÅÅĞò")));
	dict.Insert(std::make_pair(std::string("left"), std::string("×ó±ß")));
	dict.Insert(std::make_pair(std::string("right"), std::string("ÓÒ±ß")));

	MyMap<std::string, std::string>::iterator it = dict.begin();

	while (it != dict.end())
	{
		cout << (*it).first << " : " << (*it).second << endl;
		++it;
	}
	cout << endl;

	dict["map"];
	dict["left"] = "Ê£Óà";

	for (const auto& kv : dict)
	{
		cout << kv.first << " : " << kv.second << endl;
	}
}