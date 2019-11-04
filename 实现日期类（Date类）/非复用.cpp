#include "Date.h"

int Date::GetMonthDay(int year, int month) const
{
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  //�洢ÿ�µ�������2����ʱ��28���ʾ
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))   //�ж��Ƿ����꣬����Ļ�2�±��29��
		return 29;
	else
		return monthArray[month];
}

Date::Date(int year = 2019, int month = 1, int day = 1)      //���캯��
{
	if (year > 0 &&											//�ж������Ƿ�Ϸ�
		month > 0 && month < 13 &&
		day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "���ڷǷ�" << endl;
	}

}

bool Date::operator==(const Date& d) const
{
	return this->_day == d._day &&
		this->_month == d._month &&
		this->_year == d._year;
}

bool Date::operator!=(const Date& d) const
{
	return this->_day != d._day ||
		this->_month != d._month ||
		this->_year != d._year;
}

bool Date::operator>(const Date& d) const
{
	return (this->_year > d._year || (this->_year == d._year&&this->_month > d._month) ||
		(this->_year == d._year&&this->_month == d._month&&this->_day > d._day));
}

bool Date::operator<(const Date& d) const
{
	return (this->_year < d._year || (this->_year == d._year&&this->_month < d._month) ||
		(this->_year == d._year&&this->_month == d._month&&this->_day < d._day));
}

bool Date::operator>=(const Date& d) const
{
	return *this < d ? 0 : 1;
}

bool Date::operator<=(const Date& d) const
{
	return *this > d ? 0 : 1;
}

Date& Date::operator=(const Date& d)
{
	if(*this != d)
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
	if (day < 0)                         //�û������븺�������ʾ��ǰ��day�죬ֱ�ӵ���"-"
		return *this - (-day);
	Date ret(*this);
	while (ret._day + day > GetMonthDay(ret._year, ret._month))  //day��������ʣ�������������ѭ��
	{
		day = day - (GetMonthDay(ret._year, ret._month) - ret._day);
		ret._day = 0;
		if (ret._month == 12)  //�ж��Ƿ���һ��
		{
			ret._year++;
			ret._month = 0;
		}
		ret._month++;  //������һ����
	}
	ret._day += day;  //����ʣ�������

	return ret;
}

Date Date::operator+=(int day)
{
	if (day < 0)
		return *this -= (-day);
	while (this->_day + day > GetMonthDay(this->_year, this->_month))
	{
		day = day - (GetMonthDay(this->_year, this->_month) - this->_day);
		this->_day = 0;
		if (this->_month == 12)
		{
			this->_year++;
			this->_month = 0;
		}
		this->_month++;
	}
	this->_day += day;

	return *this;
}

Date Date::operator-(int day) const
{
	if (day < 0)							//���û����븺�������ʾ�����day�죬ֱ�ӵ���"-"
		return *this + (-day);
	Date ret(*this);
	while (ret._day < day)                  //����������������dayʱ������ѭ��
	{
		day = day - ret._day;
		if (ret._month == 1)                //�ж��Ƿ��˻�ǰһ��
		{
			ret._month = 13;
			ret._year--;
		}
		ret._month--;                       //��ǰ��һ����
		ret._day = GetMonthDay(ret._year, ret._month);
	}
	ret._day -= day;

	return ret;
}

Date Date::operator-=(int day)
{
	if (day < 0)
		return *this += (-day);
	while (this->_day <= day)
	{
		day = day - this->_day;
		if (this->_month == 1)
		{
			this->_month = 13;
			this->_year--;
		}
		this->_month--;
		this->_day = GetMonthDay(this->_year, this->_month);
	}
	this->_day -= day;

	return *this;
}

// ǰ��
Date& Date::operator++()
{
	if (++_day > GetMonthDay(_year, _month))
	{
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}

		_day = 1;
	}

	return *this;
}

Date& Date::operator--()
{
	if (--_day == 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}

		_day = GetMonthDay(_year, _month);
	}
			
	return *this;
}

// ����
Date Date::operator++(int)
{
	Date ret(*this);
	if (++_day > GetMonthDay(_year, _month))
	{
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year++;
		}

		_day = 1;
	}

	return ret;
}

Date Date::operator--(int)
{
	Date ret(*this);
	if (--_day == 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}

		_day = GetMonthDay(_year, _month);
	}

	return ret;
}

// d1-d2
int Date::operator-(const Date& d) const
{
	int bYear = _year;
	int sYear = d._year;
	int bMonth = _month;
	int sMonth = d._month;
	int bDay = _day;
	int sDay = d._day;
	int yFlag, mFlag, dFlag;
	yFlag = mFlag = dFlag = 1;

	//����x�����һ��֮ǰ�м���
	int DaysBeforeMonth[] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };

	if (_year < d._year)
	{
		bYear = d._year;
		sYear = _year;
		yFlag = -1;
	}

	if (_month < d._month)
	{
		bMonth = d._month;
		sMonth = _month;
		mFlag = -1;
	}

	if (_day < d._day)
	{
		bDay = d._day;
		sDay = _day;
		dFlag = -1;
	}

	int years = 0;
	int days = 0;//������

	years = bYear - sYear;

	for (int i = sYear; i <= bYear; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			days++;
		}
	}
	
	return (bDay - sDay)*dFlag +
		(DaysBeforeMonth[bMonth] - DaysBeforeMonth[sMonth])*mFlag +
		(years * 365 + days)*yFlag;
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

// ++ / -- (ǰ��/����)
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