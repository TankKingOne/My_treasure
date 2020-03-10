#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

namespace St 
{
	class String
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		String(const char* str = "")
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		// copy(s1)
		String(const String& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			String tmp(s._str);
			this->Swap(tmp);
		}
		// copy = s2;
		String& operator=(String s)
		{
			this->Swap(s);
			return *this;
		}

		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}


		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = 0;
				_capacity = 0;
			}
		}

		bool operator<(const String& s)
		{
			return (strcmp(_str, s._str) < 0);
		}

		bool operator>(const String& s)
		{
			return (strcmp(_str, s._str) > 0);
		}

		bool operator<=(const String& s)
		{
			return (*this == s || *this < s);
		}

		bool operator>=(const String& s)
		{
			return (*this == s || *this > s);
		}

		bool operator==(const String& s)
		{
			return (strcmp(_str, s._str) == 0);
		}

		bool operator!=(const String& s)
		{
			return (strcmp(_str, s._str) != 0);
		}

		void Reserve(size_t n)
		{
			if (_capacity >= n)//如果新空间小于旧空间，返回
				return;
			else
			{
				char *new_str = new char[n + 1];
				strcpy(new_str, _str);
				//清除原有空间
				delete[] _str;
				_str = new_str;
				_capacity = n;
			}
		}

		void Resize(size_t newSize, char ch = char());

		void PushBack(char ch)
		{
			if (_size == _capacity)
				Reserve(_capacity * 2);
			_str[_size] = ch;
			_str[++_size] = '\0';
		}

		// "hello"  "xxxxxxxxxxxxxxxxxxxxxxxxxx"
		void Append(const char* str)
		{
			while (_capacity < strlen(str) + _size)
				Reserve(_capacity * 2);
			strcpy(_str + _size, str);
			_size += strlen(str);
		}

		String& operator+=(char ch)
		{
			this->PushBack(ch);
			return *this;
		}

		String& operator+=(const char* str)
		{
			this->Append(str);
			return *this;
		}

		void Insert(size_t pos, char ch)
		{
			assert(pos < _size);
			
			char *rest = new char[_capacity];
			if (_capacity == _size)
				Reserve(_capacity * 2);
			strcpy(rest, _str + pos);
			_str[pos] = ch;
			strcpy(_str + pos + 1, rest);
			_size++;
		}

		void Insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			
			char *rest = new char[_capacity];
			while (_capacity < strlen(str) + _size)
				Reserve(_capacity * 2);
			strcpy(rest, _str + pos);
			strcpy(_str + pos, str);
			strcpy((_str + pos + strlen(str)), rest);
			_size += strlen(str);
		}

		void Erase(size_t pos, size_t len)
		{
			assert(pos < _size && pos + len <= _size);

			if (pos + len < _size)
			{
				char* tmp = new char[pos + 1];
				strncpy(_str + pos, _str + (pos + len), _size-pos-len);
				_str[_size - len] = '\0';
			}
			else
				_str[pos] = '\0';
			_size -= len;
		}

		size_t Find(char ch, size_t pos = 0)
		{
			assert(pos >= 0 && pos < _size);
			
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}

			return npos;
		}

		size_t Find(const char* str, size_t pos = 0)
		{
			assert(pos >= 0 && pos < _size);

			int len = strlen(str);

			for (size_t i = 0; i < _size - len; i++)
			{
				if (str[0] == _str[i])
				{
					char* tmp = new char[len + 1];
					for (int j = 0; j < len; j++)
					{
						tmp[j] = _str[j + i];
					}
					tmp[len] = '\0';
					if (strcmp(tmp, str) == 0)
						return i;
				}
			}

			return npos;
		}


		const char* c_str() const
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		size_t Size()
		{
			return _size;
		}

		size_t Capacity()
		{
			return _capacity;
		}

	private:
		friend ostream& operator<<(ostream& _cout, const St::String& s)
		{
			_cout << s._str;
			return _cout;	
		}

		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	size_t String::npos = -1;

	void TestString1()
	{
		String s1("hello");
		String s2("world");
		String copy(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << copy.c_str() << endl;

		copy = s1 = s2;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << copy.c_str() << endl;

		String::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : s1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	void TestString2()
	{
		String s1("abcdeb");
		String s2("abcde");
		cout << (s2 > s1) << endl;
		cout << (s2 < s1) << endl;
		cout << (s2 == s1) << endl;
		cout << (s2 >= s1) << endl;
		cout << (s2 <= s1) << endl;
	}

	void TestString3()
	{
		String s1("abcde");
		cout << s1.c_str() << endl;
		//s1.Reserve(100);
		cout << s1.c_str() << endl;
		s1.PushBack('m');
		cout << s1.c_str() << endl;
		//s1.Append("qwertyuiopasdfghjklzxcvbnm");
		s1 += 'b';
		s1 += "lllllll0";
		cout << s1 << endl;

	}
	void TestString4()
	{
		String s1("abcde");
		s1.Insert(1, 'm');
		s1.Insert(3, "123456789");
		cout << s1 << endl;
		int k = s1.Find('c');
		cout << k << endl;
	}
	void TestString5()
	{
		String s1("abcd");
		s1.Erase(1, 3);
		cout << s1 << endl;
	}
	void TestString6()
	{
		String s1("abbabbacabcddd");

		int k = s1.Find("abc");
		cout << k << endl;
	}
}
