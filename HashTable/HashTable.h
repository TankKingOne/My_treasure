#pragma once
#include <iostream>
#include <vector>
#include <string>

enum State
{
	EXITS,
	EMPTY,
	DELETE,
};

namespace CLOSE // 闭散列
{
	template<class K, class V>
	struct HashData
	{
		std::pair<K, V> _kv;
		State _state;

		HashData()
			:_state(EMPTY)
		{}

	};

	template<class K, class V>
	class HashTable
	{
		typedef HashData<K, V> HashData;
	public:
		HashTable()
			:_num(0)
		{}

		bool Insert(const std::pair<K, V>& kv)
		{
			// 如果表为空或负载因子到达0.7就增容
			if (_table.size() == 0 || _num * 10 / _table.size() == 7)  // 防止精度丢失，整型/整型
			{
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				HashTable<K, V> newht;
				newht._table.resize(newsize);
				for (size_t i = 0; i < _table.size(); ++i)
				{
					if (_table[i]._state == EXITS)
						newht.Insert(_table[i]._kv);
				}
				newht._table.swap(_table);
			}
			// 线性探测
			//size_t index = kv.first % _table.size();
			//
			//while (_table[index]._state == EXITS)
			//{
			//	if (_table[index]._kv.first == kv.first)
			//	{
			//		return false;
			//	}

			//	index += 1;
			//	if (index == _table.size())
			//	{
			//		index = 0;
			//	}
			//}

			// 二次探测
			size_t start = kv.first % _table.size();
			size_t index = start;
			size_t i = 1;

			while (_table[index]._state == EXITS)
			{
				if (_table[index]._kv.first == kv.first)
				{
					return false;
				}

				index = start + i * i;
				++i;
				index %= _table.size();
			}

			_table[index]._kv = kv;
			_table[index]._state = EXITS;
			_num++;
			return true;
		}
		HashData* Find(const K& key)
		{
			size_t start = key % _table.size();
			size_t index = start;
			size_t i = 1;
			while (_table[index]._state != EMPTY)
			{
				if (_table[index]._kv.first == key)
				{
					if (_table[index]._state == EXITS && _table[index]._kv.first == key)
					{
						return &_table[index];

					}
				}

				index = start + i * i;
				++i;

				index %= _table.size();
			}
		}

		bool Erase(const K& key)
		{
			HashData* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				return true;
			}
			else
			{
				return false;
			}
		}
	private:
		std::vector<HashData> _table;
		size_t _num = 0;  // 存储数据的个数
	};

	void test()
	{
		HashTable<int, int> ht;
		ht.Insert(std::make_pair(3, 3));
		ht.Insert(std::make_pair(13, 13));
		ht.Insert(std::make_pair(33, 33));
		//ht.Insert(std::make_pair(23, 23));
	}
}

// 开散列
namespace OPEN
{
	template<class V>
	struct HashNode
	{
		HashNode<V>* _next;
		V _valuefiled; // 值->K 或者 pair<K, V>

		HashNode(const V& v)
			:_next(nullptr)
			,_valuefiled(v)
		{}
	};

	template<class K, class V, class KeyOfValue, class HashFunc>
	class HashTable;											// 前置声明

	template<class K, class V, class KeyOfValue, class HashFunc>
	struct HTIterator
	{
		typedef HashNode<V> Node;
		typedef HTIterator<K, V, KeyOfValue, HashFunc> Self;
		Node* _node;
		HashTable<K, V, KeyOfValue, HashFunc>* _ht;

		HTIterator(Node* node, HashTable<K, V, KeyOfValue, HashFunc>* ht)
			:_node(node)
			,_ht(ht)
		{}
		
		Self& operator++()
		{
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				KeyOfValue kov;
				size_t index = _ht->HashIndex(kov(_node->_valuefiled), _ht->_table.size());
				++index;
				while (index < _ht->_table.size())
				{
					if (_ht->_table[index])
					{
						_node = _ht->_table[index];
						break;
					}
					++index;
				}
				if(index == _ht->_table.size())
					_node = nullptr;
			}
			return *this;
		}

		V& operator*()
		{
			return _node->_valuefiled;
		}
		V* operator->()
		{
			return &_node->_valuefiled;
		}
		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};

	// UnorderedMap -> HashTable<K, pair<K, V>, KeyOfValue>
	// UnorderedSet -> HashTable<K, K, KeyOfValue>
	template<class K, class V, class KeyOfValue, class HashFunc>
	class HashTable
	{
		typedef HashNode<V> Node;

		template<class K, class V, class KeyOfValue, class HashFunc>
		friend struct HTIterator;
	public:
		typedef HTIterator<K, V, KeyOfValue, HashFunc> iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				if (_table[i])
				{
					return iterator(_table[i], this);
				}
			}

			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}
		std::pair<iterator, bool> Insert(const V& v)
		{
			KeyOfValue kov;

			if (_num == _table.size())  // 负载因子等于1
			{
				size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
				std::vector<Node*> newtable;
				newtable.resize(newsize, nullptr);
				for (size_t i = 0; i < _table.size(); ++i)
				{
					Node* cur = _table[i];
					while (cur)
					{
						// 重新计算在新表中的位置，移动到新表
						Node* next = cur->_next;
						//size_t index = kov(cur->_valuefiled) % newtable.size();
						size_t index = HashIndex(kov(cur->_valuefiled), newtable.size());
						cur->_next = newtable[index];
						newtable[index] = cur;

						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newtable);
			}
			//size_t index = kov(v) % _table.size();
			size_t index = HashIndex(kov(v), _table.size());

			Node* cur = _table[index];
			while (cur)
			{
				if (kov(cur->_valuefiled) == kov(v))
				{
					return std::make_pair(iterator(cur, this), false);
				}
				cur = cur->_next;
			}

			Node* newnode = new Node(v);
			newnode->_next = _table[index];
			_table[index] = newnode;
			++_num;
			return std::make_pair(iterator(newnode, this), true);
		}

		iterator Find(const K& key)
		{
			KeyOfValue kov;
			//size_t index = key % _table.size();
			size_t index = HashIndex(key, _table.size());

			Node* cur = _table[index];
			while (cur)
			{
				if (kov(cur->_valuefiled) == key)
				{
					return iterator();
				}
				cur = cur->_next;
			}
			// return end();
		}

		bool Erase(const K& key)
		{
			KeyOfValue kov;
			//size_t index = key % _table.size();
			size_t index = HashIndex(key, _table.size());

			Node* cur = _table[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (kov(cur->_valuefiled) == key)
				{
					if (prev == nullptr)
					{
						_table[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					--_num;
					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
			
		}

		size_t HashIndex(const K& key, size_t size)
		{
			HashFunc hf;
			return hf(key) % size;
		}
	private:
		std::vector<Node*> _table;
		size_t _num = 0;
	};
}