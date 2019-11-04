#include "Date.h"

int Date::GetMonthDay(int year, int month) const
{
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;
	else
		return monthArray[month];
}

// 四个成员函数
Date::Date(int year = 2019, int month = 1, int day = 1)
{
	if (year > 0 &&
		month > 0 && month < 13 &&
		day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "日期非法" << endl;
	}

}

bool Date::operator==(const Date& d) const
{
	return _day == d._day &&
		_month == d._month &&
		_year == d._year;
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

bool Date::operator>(const Date& d) const
{
	return (_year > d._year || (_year == d._year&&_month > d._month) ||
		(_year == d._year&&_month == d._month&&_day > d._day));
}

bool Date::operator<(const Date& d) const
{
	return !((*this == d) || (*this > d));
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}

Date& Date::operator=(const Date& d)
{
	if (*this != d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}

	return *this;
}

//d1 + 10
Date Date::operator+(int day) const
{
	Date ret(*this);
	ret += day;

	return ret;
}

Date Date::operator+=(int day)
{
	if (day < 0)
		return *this -= (-day);
	while (_day + day > GetMonthDay(_year, _month))
	{
		day = day - (GetMonthDay(_year, _month) - _day);
		_day = 0;
		if (_month == 12)
		{
			_year++;
			_month = 0;
		}
		_month++;
	}
	_day += day;

	return *this;
}

Date Date::operator-(int day) const
{
	Date ret(*this);
	ret -= day;

	return ret;
}

Date Date::operator-=(int day)
{
	if (day < 0)
		return *this += (-day);
	while (_day <= day)
	{
		day = day - _day;
		if (_month == 1)
		{
			_month = 13;
			_year--;
		}
		_month--;
		_day = GetMonthDay(_year, _month);
	}
	_day -= day;

	return *this;
}

// 前置
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

Date& Date::operator--()
{
	*this -= 1;

	return *this;
}

// 后置
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;

	return ret;
}

Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;

	return ret;
}

// d1-d2
int Date::operator-(const Date& d) const
{
	Date max(*this);
	Date min(d);
	int flag = 1;
	int days = 0;//相差天数

	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	while (max != min)
	{
		max--;
		days++;
	}

	return days;
}

void Date::Print() const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}



// == / != / >= / <=
void Test1()
{
	Date d1(2019, 1, 15);
	d1.Print();
	Date d2(2021, 10, 10);
	d2.Print();
	Date d3(2021, 10, 10);
	d3.Print();
	cout << (d1 == d2) << endl;
	cout << (d2 == d3) << endl;
	cout << (d1 != d3) << endl;
	cout << (d2 != d3) << endl;

	cout << (d1 >= d2) << endl;
	cout << (d2 >= d3) << endl;
	cout << (d2 <= d3) << endl;
	cout << (d1 <= d2) << endl;
}

// + / - / += / -=
void Test2()
{
	Date d1(2019, 1, 15);
	d1.Print();
	Date d2(2021, 10, 10);
	d2.Print();
	Date d3 = (d1 + 999);
	d3.Print();
	Date d4 = (d2 - 999);
	d4.Print();

	d1 += 999;
	d2 -= 999;
	d1.Print();
	d2.Print();
}

// ++ / -- (前置/后置)
void Test3()
{
	Date d1(2018, 5, 10);
	Date d2(2019, 2, 5);
	d1--.Print();
	d1.Print();
	d2++.Print();
	d2.Print();

	(--d1).Print();
	d1.Print();
	(++d2).Print();
	d2.Print();
}

void Test4()
{
	Date d1(2019, 1, 15);
	Date d2(2021, 10, 10);
	int a = (d2 - d1);
	cout << a << endl;
}


int main()
{
	//Test1();
	//Test2();
	//Test3();
	Test4();

	system("pause");
	return 0;
}
