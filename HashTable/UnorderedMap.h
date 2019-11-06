#pragma once
#include "HashTable.h"

template<class K, class T>
class UnorderedMap
{
public:

private:
	struct MapKeyOfValue
	{
		const K& operator()(const std::pair<K, T>& kv)
		{
			return kv.first;
		}
	};
	OPEN::HashTable<K, std::pair<K, T>, MapKeyOfValue, HashFunc> _ht;
};