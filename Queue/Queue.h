#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include"BTree.h"

typedef BTNode* QDatatype;
typedef struct QueueNode
{
	QDatatype _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDatatype x);
void QueuePop(Queue* pq);
int QueueSize(Queue* pq);
int QueueEmpty(Queue* pq);
QDatatype QueueFront(Queue* pq);