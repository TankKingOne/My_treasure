#pragma once
#include "HashTable.h"

//template<class K, class HashFunc>
//class UnorderedSet
//{
//	struct SetKeyOfValue
//	{
//		const K& operator()(const K& key)
//		{
//			return key;
//		}
//	};
//public:
//	typedef typename OPEN::HashTable<K, K, SetKeyOfValue, HashFunc>::iterator iterator;
//	std::pair<iterator, bool> Insert(const K& key)
//	{
//		return _ht.Insert(key);
//	}
//
//	bool Erase(const K& key)
//	{
//		return _ht.Erase(key);
//	}
//private:
//	OPEN::HashTable<K, K, SetKeyOfValue, HashFunc> _ht;
//};
//
//struct intHashFunc
//{
//	size_t operator()(size_t key)
//	{
//		return key;
//	}
//};
//
//struct stringHashFunc
//{
//	size_t operator()(const std::string& s)
//	{
//		size_t value = 0;
//		for (size_t i = 0; i < s.size(); ++i)
//		{
//			value += s[i];
//		}
//		return value;
//	}
//};

template<class K>
struct DefaultHashFunc
{
	const K& operator()(const K& key)
	{
		return key;
	}
};

template<>
struct DefaultHashFunc<std::string> // 类模板的特化
{
	size_t operator()(const std::string& s)
	{
		size_t value = 0;
		for (size_t i = 0; i < s.size(); ++i)
		{
			value *= 131;
			value += s[i];
		}
		return value;
	}
};

template<class K, class HashFunc = DefaultHashFunc<K>>
class UnorderedSet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename OPEN::HashTable<K, K, SetKeyOfValue, HashFunc>::iterator iterator;
	std::pair<iterator, bool> Insert(const K& key)
	{
		return _ht.Insert(key);
	}

	bool Erase(const K& key)
	{
		return _ht.Erase(key);
	}

	iterator begin()
	{
		return _ht.begin();
	}

	iterator end()
	{
		return _ht.end();
	}
private:
	OPEN::HashTable<K, K, SetKeyOfValue, HashFunc> _ht;
};

void TestUnorderedSet()
{
	//UnorderedSet<int> us;
	//us.Insert(2);
	//us.Insert(12);
	//us.Insert(3);

	//UnorderedSet<int>::iterator it = us.begin();
	//while (it != us.end())
	//{
	//	std::cout << *it << std::endl;
	//	++it;
	//}


	//us.Erase(2);
	//us.Erase(12);
	//us.Erase(3);

	//UnorderedSet<std::string> sset;
	//sset.Insert("opop");
	//sset.Insert("kkl");
	//sset.Insert("fgh");

	//UnorderedSet<int>::iterator it1 = sset.begin();
	//while (it1 != sset.end())
	//{
	//	std::cout << *it1 << std::endl;
	//	++it1;
	//}

	// 需要写仿函数
	// UnorderedSet<std::pair(std::string, std::string)> pus;
}