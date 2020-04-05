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
//1. ѡ���⣺
//ѡ�� : A.ջ B.�� C.���ݶ� D.�����
//	globalVar�����____ staticGlobalVar�����____
//	staticVar�����____ localVar�����____
//	num1 �����____
//	char2�����____ *char2�����___
//	pChar3�����____ *pChar3�����____
//	ptr1�����____ *ptr1�����____
//2. ����⣺
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
//		//ʹ�ÿռ�
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//void Test()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10);
//	// ��̬����10��int���͵Ŀռ�
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
	// ���뵥�� A ���͵Ŀռ�
	A* p1 = (A*)malloc(sizeof(A));
	free(p1);


	// ����10�� A ���͵Ŀռ�
	A* p2 = (A*)malloc(sizeof(A) * 10);
	free(p2);
}

void Test2()
{
	cout << "Test2:" << endl;
	// ���뵥��Test���͵Ķ���
	A* p1 = new A;
	delete p1;
	// ����10��Test���͵Ķ���
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