#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_head = NULL;
	pq->_tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_head;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_head = pq->_tail = NULL;
}

void QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (pq->_tail == NULL)
	{
		pq->_tail = pq->_head = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	QueueNode* newhead = pq->_head->_next;
	free(pq->_head);
	pq->_head = newhead;
	if (newhead == NULL)
		pq->_tail = NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->_head;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

int QueueEmpty(Queue* pq)
{
	return pq->_head == NULL ? 0 : 1;
}

QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	return pq->_head->_data;
}