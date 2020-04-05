#include<stdio.h>
#include<stdlib.h>

//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//1. 选择题：
//选项 : A.栈 B.堆 C.数据段 D.代码段
//	globalVar在哪里？____ staticGlobalVar在哪里？____
//	staticVar在哪里？____ localVar在哪里？____
//	num1 在哪里？____
//	char2在哪里？____ *char2在哪里？___
//	pChar3在哪里？____ *pChar3在哪里？____
//	ptr1在哪里？____ *ptr1在哪里？____
//2. 填空题：
//	sizeof(num1) = ____;
//	sizeof(char2) = ____; strlen(char2) = ____;
//	sizeof(pChar3) = ____; strlen(pChar3) = ____;
//	sizeof(ptr1) = ____;

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//int main()
//{
//	int *p = (int*)calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//使用空间
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//void Test()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//	// 动态申请10个int类型的空间
//	int* ptr6 = new int[10];
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}

class A
{
public:
	A()
		: _data(0)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _data;
};

void Test1()
{
	cout << "Test1:" << endl;
	// 申请单个 A 类型的空间
	A* p1 = (A*)malloc(sizeof(A));
	free(p1);


	// 申请10个 A 类型的空间
	A* p2 = (A*)malloc(sizeof(A) * 10);
	free(p2);
}

void Test2()
{
	cout << "Test2:" << endl;
	// 申请单个Test类型的对象
	A* p1 = new A;
	delete p1;
	// 申请10个Test类型的对象
	A* p2 = new A[10];
	delete[] p2;
}

int main()
{
	Test1();
	Test2();

	system("pause");
	return 0;
}