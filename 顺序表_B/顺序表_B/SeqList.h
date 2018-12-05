#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

// ˳���Ķ�̬�洢 
typedef struct SeqList
{
	SLDataType* _array; // ָ��̬���ٵ����� 
	size_t _size; // ��Ч���ݸ��� 
	size_t _capicity; // �����ռ�Ĵ�С 
}SeqList;

// ������ɾ��Ľӿ� 
void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);

void CheckCapacity(SeqList* psl);                      //�������
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);   //ǰ��
void SeqListPopFront(SeqList* psl);                  //ǰɾ

int SeqListFind(SeqList* psl, SLDataType x); //����
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
void SeqListErase(SeqList* psl, size_t pos);
void SeqListRemove(SeqList* psl, SLDataType x);
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);

// ��չ������ʵ�� 
void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);


void SeqListTest();
void SeqListTest2();
void SeqListTest3();
void SeqListTest4();
void SeqListTest5();
void SeqListTest6();
void SeqListTest7();