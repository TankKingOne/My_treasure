#pragma once
#include <iostream>
#include <vector>

class BitSet
{
public:
	BitSet(size_t bitnum)
		:_bitnum(bitnum)
	{
		_bits.resize((bitnum >> 3) + 1, 0);
	}
	void Set(size_t x)
	{
		size_t index = x >> 3; // ������λ�൱�ڳ���8
		size_t num = x % 8;

		_bits[index] |= (1 << num); // ��numλ��1
	}
	void ReSet(size_t x)
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		_bits[index] &= (~(1 << num)); // ��numλ��0
	}
	bool Test(size_t x)
	{
		size_t index = x >> 3;
		size_t num = x % 8;

		return _bits[index] & (1 << num);
	}
private:
	std::vector<char> _bits;
	size_t _bitnum;
};

void test()
{
	// BitSet bs(10000);
	 BitSet bs(1024 * 1024 * 1024 * 4);
	// BitSet bs(-1); // -1����ȫ1�����޷����������ֵ
	bs.Set(9);
	bs.Set(99);
	bs.Set(999);
	bs.Set(9999);

	std::cout << bs.Test(9) << std::endl;
	std::cout << bs.Test(99) << std::endl;
	std::cout << bs.Test(999) << std::endl;
	std::cout << bs.Test(9999) << std::endl;

	bs.ReSet(9);
	bs.ReSet(99);
	bs.ReSet(999);
	bs.ReSet(9999);

	std::cout << bs.Test(9) << std::endl;
	std::cout << bs.Test(99) << std::endl;
	std::cout << bs.Test(999) << std::endl;
	std::cout << bs.Test(9999) << std::endl;
}