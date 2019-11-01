#include <iostream>
#include <vector>

using namespace std;

//template<class T>

//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if(_ptr)
//			delete _ptr;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//void func()
//{
//	
//	
//
//	//vector<int> v;
//	//v.at(0) = 0;
//}
//
//int main()
//{
//	SmartPtr<int> sp1(new int);
//	*sp1 = 10;
//	cout << *sp1 << endl;
//
//	system("pause");
//	return 0;
//}

// auto_ptr
//namespace MySPtr
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		~auto_ptr()
//		{
//			if (_ptr)
//			{
//				cout << "123" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//		// ap1(ap2)
//		auto_ptr(auto_ptr<T>& ap)
//			:_ptr(ap._ptr)
//		{
//			ap._ptr = nullptr;
//		}
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//}
//
//void test()
//{
//	MySPtr::auto_ptr<int> ap1(new int);
//	MySPtr::auto_ptr<int> ap2(ap1);
//
//}
//
//int main()
//{
//	test();
//
//	system("pause");
//	return 0;
//}

// unique_ptr
//namespace MySPtr
//{
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//		~unique_ptr()
//		{
//			if (_ptr)
//			{
//				cout << "123" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//		// ap1(ap2)
//		unique_ptr(unique_ptr<T>& ap) = delete;
//		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{auto_ptr
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//	};
//}

namespace MySPtr
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			,_pcount(new int(1))
		{}
		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				delete _ptr;
				delete _pcount;
			}
		}
		// ap1(ap2)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_pcount(sp._pcount)
		{
			++(*_pcount);
		}
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (_ptr != &sp._ptr)
			{
				if (--(*_pcount) == 0)
				{
					delete _ptr;
					delete _pcount;
				}
				
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(*_pcount);
			}
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;
	};
}

void test()
{
	MySPtr::shared_ptr<int> sp1(new int);
	MySPtr::shared_ptr<int> sp2(sp1);
	sp1 = sp2;

	MySPtr::shared_ptr<int> sp3(new int);
	sp2 = sp3;
}

int main()
{
	test();

	system("pause");
	return 0;
}