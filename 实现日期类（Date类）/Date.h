#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month) const;
	// �ĸ���Ա����
	Date(int year, int month, int day);

	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	bool operator>(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<=(const Date& d) const;

	Date& operator=(const Date& d);

	//d1 + 10
	Date operator+(int day) const;
	Date operator+=(int day);

	Date operator-(int day) const;
	Date operator-=(int day);

	// ǰ��
	Date& operator++();
	Date& operator--();

	// ����
	Date operator++(int);
	Date operator--(int);

	// d1-d2
	int operator-(const Date& d) const;

	void Print() const;

private:
	int _year;
	int _month;
	int _day;
};

void Test1();
void Test2();
void Test3();
void Test4();