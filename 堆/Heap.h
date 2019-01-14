#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;

void Swap(HPDataType* a, HPDataType* b);
void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

void AdjustDown(HPDataType* a, int n, int root);
void AdjustUp(Heap* ph, int child);

void Sort(int* a, int n);
void TestHeap();