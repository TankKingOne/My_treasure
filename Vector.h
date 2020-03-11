#pragma once
#include <iostream>
#include <assert.h>

namespace v
{
	template <class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		Vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstroage(nullptr)
		{}

		Vector(int n, const T& value = T())
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}

		template<class InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		Vector(const Vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(v.Capacity());
			Iterator it = Begin();
			ConstIterator vit = v.CBegin();
			while (vit != v.CEnd())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}

		Vector<T>& operator=(Vector<T> v)
		{
			_start = new[v.Capacity()];
			for (size_t i = 0; i < size; i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.Size();
			_endofstroage = _start + v.Capacity();
		}

		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstroage, v._endofstroage);
		}

		~Vector()
		{
			delete[] _start;
			_start = _finish = _endofstroage = nullptr;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];

				if (_start)
				{
					for (size_t i = 0; i < size; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}

		void Resize(size_t n, const T& value = T())
		{
			if (n <= Size())
			{
				_finish = _start + n;
			}
			if (n > Capacity())
			{
				Reserve(n);
			}
			iterator cur = _finish;
			iterator finish = _start + n;
			while (cur != finish)
			{
				*cur = value;
				++cur;
			}
		}

		void PushBack(const T& x)
		{
			Insert(end(), x);
		}

		void PopBack()
		{
			Erase(--end());
		}

		iterator Insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstroage)
			{
				size_t size = Size();
				size_t NewCapacity = Capacity() == 0 ? 1 : Capacity() * 2;
				Reserve(NewCapacity);
				pos = _start + size;
			}

			iterator end = _finish - 1;
			while (pos < end)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;
			return pos;
		}

		iterator Erase(iterator pos)
		{
			iterator begin = _pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				begin++;
			}
			_finish--;
			return pos;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			return _start[pos];
		}

		size_t Size() const
		{
			return _start - _finish;
		}

		size_t Capacity() const
		{
			return _endofstroage - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstroage;
	};
}